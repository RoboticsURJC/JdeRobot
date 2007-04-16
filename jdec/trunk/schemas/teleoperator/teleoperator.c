/*
 *  Copyright (C) 2006 José María Cañas Plaza 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Authors : José María Cañas Plaza <jmplaza@gsyc.escet.urjc.es>
 */

#include "jde.h"
#include "jdegui.h"
#include "teleoperatorgui.h"

#define v3f glVertex3f
#include <GL/gl.h>              
#include <GL/glx.h>
#include <GL/glu.h>

#include <forms.h>
#include <glcanvas.h>
#include "pioneeropengl.h"

#define DISPLAY_ROBOT 0x01UL
#define DISPLAY_PANTILTENCODERS 0x20UL
#define DISPLAY_SONARS 0x04UL
#define DISPLAY_LASER 0x08UL
#define DISPLAY_COLORIMAGEA 0x10UL
#define DISPLAY_COLORIMAGEB 0x20UL
#define DISPLAY_COLORIMAGEC 0x40UL
#define DISPLAY_COLORIMAGED 0x80UL
#define BASE_TELEOPERATOR 0x100UL
#define PANTILT_TELEOPERATOR 0x200UL

#define PI 3.141592654
#define MAXWORLD 30.
typedef struct SoRtype{
  struct SoRtype *father;
  float posx;
  float posy;
  float posz;
  float foax;
  float foay;
  float foaz;
  float roll;
}SofReference;

static SofReference mypioneer,virtualcam;
/* robot and virtual camera in the absolute FrameOfReference */
static int track_robot=TRUE;
static int toggle=FALSE;


#define PUSHED 1
#define RELEASED 0


static char *samplesource;
static int vmode;
static XImage *imagenA,*imagenB,*imagenC,*imagenD,*sampleimage; 
static char *imagenA_buf, *imagenB_buf, *imagenC_buf, *imagenD_buf, *sampleimage_buf; /* puntero a memoria para la imagen a visualizar en el servidor X. No compartida con el servidor */
static long int tabla[256]; 
/* tabla con la traduccion de niveles de gris a numero de pixel en Pseudocolor-8bpp. Cada numero de pixel apunta al valor adecuado del ColorMap, con el color adecuado instalado */
static int pixel8bpp_rojo, pixel8bpp_blanco, pixel8bpp_amarillo;


int teleoperator_id=0; 
int teleoperator_brothers[MAX_SCHEMAS];
arbitration teleoperator_callforarbitration;
int teleoperator_cycle=100; /* ms */

#define joystick_maxRotVel 30 /* deg/sec */
#define joystick_maxTranVel 500 /* mm/sec */
float joystick_x, joystick_y;
float pt_joystick_x, pt_joystick_y;
int back=0;

float *mysonars;
int *mylaser;
float *myencoders;
resumeFn laserresume, sonarsresume, encodersresume;
suspendFn lasersuspend, sonarssuspend, encoderssuspend;

float *myv;
float *myw;
resumeFn motorsresume;
suspendFn motorssuspend;

float *mypan_angle, *mytilt_angle;  /* degs */
float *mylongitude; /* degs, pan angle */
float *mylatitude; /* degs, tilt angle */
float *mylongitude_speed;
float *mylatitude_speed;


FD_teleoperatorgui *fd_teleoperatorgui;
GC teleoperatorgui_gc;
Window teleoperatorgui_win; 
unsigned long display_state;


void teleoperator_iteration()
{  
  double delta, deltapos;
  float speed_coef;

  speedcounter(teleoperator_id);

  if ((display_state & BASE_TELEOPERATOR)!=0)
    {
      /* ROTACION=ejeX: Ajusta a un % de joystick_maxRotVel. OJO no funcion lineal del desplazamiento visual, sino con el al cuadrado, para aplanarla en el origen y evitar cabeceos, conseguir suavidad en la teleoperacion */
      
      delta = (joystick_x-0.5)*2; /* entre +-1 */
      deltapos = fabs(delta); /* Para que no moleste el signo de delta en el factor de la funcion de control */

      if (delta<0) (*myw) = (float) joystick_maxRotVel*deltapos*deltapos*deltapos; 
      else (*myw) = (float) -1.*joystick_maxRotVel*deltapos*deltapos*deltapos;

      /* TRASLACION=ejeY: Ajusta a un % de +-joystick_maxTranVel. OJO no funcion lineal del desplazamiento visual, sino con el a la cuarta, para aplanarla en el origen */
      
      delta = (joystick_y-0.5)*2; /* entre +-1 */
      deltapos = fabs(delta);/* Para que no moleste el signo de delta en el factor de la funcion de control */
      if (delta<0) (*myv) = (float) -1.*joystick_maxTranVel*deltapos*deltapos*deltapos;
      else (*myv) = (float) joystick_maxTranVel*deltapos*deltapos*deltapos;
    }
  
  if ((display_state & PANTILT_TELEOPERATOR)!=0)      
    {
      /* pt_joystick_x and pt_joystick_y fall in [0,1], the default limits from Xforms */  
      latitude=MIN_TILT_ANGLE+pt_joystick_y*(MAX_TILT_ANGLE-MIN_TILT_ANGLE);
      longitude=MAX_PAN_ANGLE-pt_joystick_x*(MAX_PAN_ANGLE-MIN_PAN_ANGLE);
      
      speed_coef = fl_get_slider_value(fd_teleoperatorgui->ptspeed);
      longitude_speed=(1.-speed_coef)*MAX_SPEED_PANTILT;
      latitude_speed=(1.-speed_coef)*MAX_SPEED_PANTILT;
      /*printf("teleoperator: longitude speed %.2f, latitude speed %.2f\n",longitude_speed,latitude_speed);*/
    }
  
}


void teleoperator_suspend()
{
  if ((display_state & DISPLAY_SONARS)!=0) 
    sonarssuspend();
  if ((display_state & DISPLAY_LASER)!=0) 
    lasersuspend();
  if ((display_state & DISPLAY_ROBOT)!=0)
    encoderssuspend();
  if ((display_state & BASE_TELEOPERATOR)!=0)
    motorssuspend();

  pthread_mutex_lock(&(all[teleoperator_id].mymutex));
  put_state(teleoperator_id,slept);
  /* printf("teleoperator: off\n");*/
  pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
}


void teleoperator_resume(int father, int *brothers, arbitration fn)
{
  int i;
 
  pthread_mutex_lock(&(all[teleoperator_id].mymutex));
  /* this schema resumes its execution with no children at all */
  for(i=0;i<MAX_SCHEMAS;i++) all[teleoperator_id].children[i]=FALSE;
 
  all[teleoperator_id].father=father;
  if (brothers!=NULL)
    {
      for(i=0;i<MAX_SCHEMAS;i++) teleoperator_brothers[i]=-1;
      i=0;
      while(brothers[i]!=-1) {teleoperator_brothers[i]=brothers[i];i++;}
    }
  teleoperator_callforarbitration=fn;
  put_state(teleoperator_id,notready);

 
  /*  printf("teleoperator: on\n");*/
  pthread_cond_signal(&(all[teleoperator_id].condition));
  pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
}

void *teleoperator_thread(void *not_used) 
{
  struct timeval a,b;
  long diff, next;

  for(;;)
    {
      pthread_mutex_lock(&(all[teleoperator_id].mymutex));

      if (all[teleoperator_id].state==slept) 
	{
	  pthread_cond_wait(&(all[teleoperator_id].condition),&(all[teleoperator_id].mymutex));
	  pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
	}
      else 
	{
	  /* check preconditions. For now, preconditions are always satisfied*/
	  if (all[teleoperator_id].state==notready) put_state(teleoperator_id,ready);
	  else if (all[teleoperator_id].state==ready)	  /* check brothers and arbitrate. For now this is the only winner */
	    { 
	      put_state(teleoperator_id,winner);
	 
	      /* start the winner state from controlled motor values */ 
	      if ((display_state & DISPLAY_SONARS)!=0) 
		{
		  mysonars=(float *)myimport("sonars","us");
		  sonarsresume=(resumeFn)myimport("sonars","resume");
		  sonarssuspend=(suspendFn)myimport("sonars","suspend");
		  sonarsresume(teleoperator_id,NULL,NULL);
		  *myv=0; *myw=0;
		}
	      
	      if ((display_state & DISPLAY_LASER)!=0) 
		{
		  mylaser=(int *)myimport("laser","jde_laser");
		  laserresume=(resumeFn)myimport("laser","resume");
		  lasersuspend=(suspendFn *)myimport("laser","suspend");
		  laserresume(teleoperator_id,NULL,NULL);
		}
	      
	      if ((display_state & DISPLAY_ROBOT)!=0)
		{
		  myencoders=(float *)myimport("encoders","jde_robot");
		  encodersresume=(resumeFn)myimport("encoders","resume");
		  encoderssuspend=(suspendFn)myimport("encoders","suspend");
		  encodersresume(teleoperator_id,NULL,NULL);
		}
	      
	      if ((display_state & BASE_TELEOPERATOR)!=0)
		{
		  myv=(float *)myimport("motors","v");
		  myw=(float *)myimport("motors","w");
		  motorsresume=(resumeFn)myimport("motors","resume");
		  motorssuspend=(suspendFn)myimport("motors","suspend");
		  motorsresume(teleoperator_id,NULL,NULL);
		}
	    }
	  else if (all[teleoperator_id].state==winner);

	  if (all[teleoperator_id].state==winner)
	    /* I'm the winner and must execute my iteration */
	    {
	      pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
	      gettimeofday(&a,NULL);
	      teleoperator_iteration();
	      gettimeofday(&b,NULL);  

	      diff = (b.tv_sec-a.tv_sec)*1000000+b.tv_usec-a.tv_usec;
	      next = teleoperator_cycle*1000-diff-10000; 
	      if (next>0) 
		/* discounts 10ms taken by calling usleep itself */
		usleep(teleoperator_cycle*1000-diff);
	      else 
		/* just let this iteration go away. overhead time negligible */
		{/*printf("time interval violated: teleoperator\n"); */
		usleep(teleoperator_cycle*1000);
		}
	    }
	  else 
	    {
	      pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
	      usleep(teleoperator_cycle*1000);
	    }
	}
    }
}

void teleoperator_close()
{
  pthread_mutex_lock(&(all[teleoperator_id].mymutex));
  teleoperator_suspend();  
  pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
  sleep(2);
  fl_free_form(fd_teleoperatorgui->teleoperatorgui);
  free(imagenA_buf);
  free(imagenB_buf);
  free(imagenC_buf);
  free(imagenD_buf);  
}


void teleoperator_startup()
{
  samplesource=colorA;
  virtualcam.posx=-150;
  virtualcam.posy=-150.;
  virtualcam.posz=150.;
  virtualcam.foax=0.;
  virtualcam.foay=0.;
  virtualcam.foaz=0.;
  virtualcam.roll=0.;
  pthread_mutex_lock(&(all[teleoperator_id].mymutex));
  myexport("teleoperator","id",&teleoperator_id);
  myexport("teleoperator","resume",(void *) &teleoperator_resume);
  myexport("teleoperator","suspend",(void *) &teleoperator_suspend);
  printf("teleoperator schema started up\n");
  put_state(teleoperator_id,slept);
  pthread_create(&(all[teleoperator_id].mythread),NULL,teleoperator_thread,NULL);
  pthread_mutex_unlock(&(all[teleoperator_id].mymutex));
}

static int InitOGL(FL_OBJECT *ob, Window win,int w,int h, XEvent *xev, void *ud)
 /* Inicializa OpenGL con los parametros que diran como se visualiza. */
{
   GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat position[] = {0.0, 3.0, 3.0, 0.0};
   GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};
   GLfloat local_view[] = {0.0};
 
   glViewport(0,0,(GLint)w,(GLint)h);  
   /*  glDrawBuffer(GL_FRONT);*/
   glDrawBuffer(GL_BACK);
   glClearColor(0.6f, 0.8f, 1.0f, 0.0f);  
   glClearDepth(1.0);                           /* Enables Clearing Of The Depth Buffer */
   /* This Will Clear The Background Color To Light Blue */
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
   /* With this, the pioneer appears correctly, but the cubes don't */
   glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv (GL_LIGHT0, GL_POSITION, position);
   glLightModelfv (GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   glLightModelfv (GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
   glEnable (GL_LIGHT0);
   /*glEnable (GL_LIGHTING);*/
   
   glEnable(GL_TEXTURE_2D);     /* Enable Texture Mapping */
   glEnable (GL_AUTO_NORMAL);
   glEnable (GL_NORMALIZE);  
   glEnable(GL_DEPTH_TEST);     /* Enables Depth Testing */
   glDepthFunc(GL_LESS);  
   glShadeModel(GL_SMOOTH);     /* Enables Smooth Color Shading */
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   return 0;
}


static int image_displaysetup() 
/* Inicializa las ventanas, la paleta de colores y memoria compartida para visualizacion*/ 
{
    XGCValues gc_values;
    XWindowAttributes win_attributes;
    XColor nuevocolor;
    int pixelNum, numCols;
    int allocated_colors=0, non_allocated_colors=0;
   
    teleoperatorgui_win= FL_ObjWin(fd_teleoperatorgui->ventanaA);
    XGetWindowAttributes(display, teleoperatorgui_win, &win_attributes);  
    XMapWindow(display, teleoperatorgui_win);
    /*XSelectInput(display, teleoperatorgui_win, ButtonPress|StructureNotifyMask);*/   
    gc_values.graphics_exposures = False;
    teleoperatorgui_gc = XCreateGC(display, teleoperatorgui_win, GCGraphicsExposures, &gc_values);  
    
    /* Utilizan el Visual (=estructura de color) y el colormap con que este operando el programa principal con su Xforms. No crea un nuevo colormap, sino que modifica el que se estaba usando a traves de funciones de Xforms*/
    vmode= fl_get_vclass();
    if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
      {printf("teleoperator: truecolor 16 bpp\n");
      imagenA_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*2/4);    
      imagenA = XCreateImage(display,DefaultVisual(display,screen),win_attributes.depth, ZPixmap,0,imagenA_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenB_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*2/4);    
      imagenB = XCreateImage(display,DefaultVisual(display,screen),win_attributes.depth, ZPixmap,0,imagenB_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenC_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*2/4);    
      imagenC = XCreateImage(display,DefaultVisual(display,screen),win_attributes.depth, ZPixmap,0,imagenC_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenD_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*2/4);    
      imagenD = XCreateImage(display,DefaultVisual(display,screen),win_attributes.depth, ZPixmap,0,imagenD_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      return win_attributes.depth;
      sampleimage_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*2);    
      sampleimage = XCreateImage(display,DefaultVisual(display,screen),win_attributes.depth, ZPixmap,0,sampleimage_buf,SIFNTSC_COLUMNS, SIFNTSC_ROWS,8,0);
      }
    else if ((vmode==TrueColor)&&(fl_state[vmode].depth==24)) 
      { printf("teleoperator: truecolor 24 bpp\n");
      imagenA_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenA = XCreateImage(display,DefaultVisual(display,screen),24, ZPixmap,0,imagenA_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenB_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenB = XCreateImage(display,DefaultVisual(display,screen),24, ZPixmap,0,imagenB_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenC_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenC = XCreateImage(display,DefaultVisual(display,screen),24, ZPixmap,0,imagenC_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenD_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenD = XCreateImage(display,DefaultVisual(display,screen),24, ZPixmap,0,imagenD_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      sampleimage_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4); 
      sampleimage = XCreateImage(display,DefaultVisual(display,screen),24, ZPixmap,0,sampleimage_buf,SIFNTSC_COLUMNS, SIFNTSC_ROWS,8,0);
      return win_attributes.depth;
      }
    else if ((vmode==TrueColor)&&(fl_state[vmode].depth==32)) 
      { printf("teleoperator: truecolor 24 bpp\n");
      imagenA_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenA = XCreateImage(display,DefaultVisual(display,screen),32, ZPixmap,0,imagenA_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenB_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenB = XCreateImage(display,DefaultVisual(display,screen),32, ZPixmap,0,imagenB_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenC_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenC = XCreateImage(display,DefaultVisual(display,screen),32, ZPixmap,0,imagenC_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      imagenD_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4/4); 
      imagenD = XCreateImage(display,DefaultVisual(display,screen),32, ZPixmap,0,imagenD_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
      sampleimage_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS*4); 
      sampleimage = XCreateImage(display,DefaultVisual(display,screen),32, ZPixmap,0,sampleimage_buf,SIFNTSC_COLUMNS, SIFNTSC_ROWS,8,0);
      return win_attributes.depth;
      }
    else if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8)) 
      {
	numCols = 256;
	for (pixelNum=0; pixelNum<numCols; pixelNum++) 
	  {
	    nuevocolor.pixel=0;
	    nuevocolor.red=pixelNum<<8;
	    nuevocolor.green=pixelNum<<8;
	    nuevocolor.blue=pixelNum<<8;
	    nuevocolor.flags=DoRed|DoGreen|DoBlue;
	    
	    /*if (XAllocColor(display,DefaultColormap(display,screen),&nuevocolor)==False) tabla[pixelNum]=tabla[pixelNum-1];*/
	    if (XAllocColor(display,fl_state[vmode].colormap,&nuevocolor)==False) {tabla[pixelNum]=tabla[pixelNum-1]; non_allocated_colors++;}
	    else {tabla[pixelNum]=nuevocolor.pixel;allocated_colors++;}
	  }
	printf("teleoperator: depth= %d\n", fl_state[vmode].depth); 
	printf("teleoperator: colormap got %d colors, %d non_allocated colors\n",allocated_colors,non_allocated_colors);

	imagenA_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS/4);    
	imagenA = XCreateImage(display,DefaultVisual(display,screen),8, ZPixmap,0,imagenA_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
	imagenB_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS/4);    
	imagenB = XCreateImage(display,DefaultVisual(display,screen),8, ZPixmap,0,imagenB_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
	imagenC_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS/4);    
	imagenC = XCreateImage(display,DefaultVisual(display,screen),8, ZPixmap,0,imagenC_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
	imagenD_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS/4);    
	imagenD = XCreateImage(display,DefaultVisual(display,screen),8, ZPixmap,0,imagenD_buf,SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2,8,0);
	sampleimage_buf = (char *) malloc(SIFNTSC_COLUMNS*SIFNTSC_ROWS);    
	sampleimage = XCreateImage(display,DefaultVisual(display,screen),8, ZPixmap,0,sampleimage_buf,SIFNTSC_COLUMNS, SIFNTSC_ROWS,8,0);

	pixel8bpp_rojo = fl_get_pixel(FL_RED);
	pixel8bpp_blanco = fl_get_pixel(FL_WHITE);
	pixel8bpp_amarillo = fl_get_pixel(FL_YELLOW);
	return win_attributes.depth;
      }
    else 
      {
	perror("Unsupported color mode in X server");exit(1);
      }
    return win_attributes.depth;
}


int freeobj_ventanaAA_handle(FL_OBJECT *obj, int event, FL_Coord mx, FL_Coord my,int key, void *xev){
  if ((event==FL_PUSH)&&(key==MOUSELEFT)&&
      ((display_state&DISPLAY_COLORIMAGEA)!=0))
    samplesource=colorA;
  return 0;
}

int freeobj_ventanaBB_handle(FL_OBJECT *obj, int event, FL_Coord mx, FL_Coord my,int key, void *xev){
  if ((event==FL_PUSH)&&(key==MOUSELEFT)&&
      ((display_state&DISPLAY_COLORIMAGEB)!=0))
    samplesource=colorB;
  return 0;
}

int freeobj_ventanaCC_handle(FL_OBJECT *obj, int event, FL_Coord mx, FL_Coord my,int key, void *xev){
  if ((event==FL_PUSH)&&(key==MOUSELEFT)&&
      ((display_state&DISPLAY_COLORIMAGEC)!=0)) 
    samplesource=colorC;
  return 0;
}

int freeobj_ventanaDD_handle(FL_OBJECT *obj, int event, FL_Coord mx, FL_Coord my,int key, void *xev){
  if ((event==FL_PUSH)&&(key==MOUSELEFT)&&
      ((display_state&DISPLAY_COLORIMAGED)!=0))
    samplesource=colorD;
  return 0;
}


extern void teleoperator_guisuspend(void);

void teleoperator_guibuttons(FL_OBJECT *obj)
{
  float dpan=0.5,dtilt=0.5, speed_coef;
  float r,lati,longi,guix,guiy,guiz;
  float dx,dy,dz;

  if (track_robot==TRUE)
    {  
      virtualcam.foax=jde_robot[0]/100.;
      virtualcam.foay=jde_robot[1]/100.;
      virtualcam.foaz=0.;
      if ((fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED) ||
	  (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED))
	{
	  if (fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED)
	    {
	      guix=virtualcam.foax; 
	      guiy=virtualcam.foay; 
	      guiz=virtualcam.foaz;
	    }
	  else if (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED)
	    {
	      guix=virtualcam.foax-virtualcam.posx;
	      guiy=virtualcam.foay-virtualcam.posy;
	      guiz=virtualcam.foaz-virtualcam.posz;
	    }
	  fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
	  fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
	  fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
	  r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
	  lati=(float)asin(guiz/r)*360./(2.*PI);
	  longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);      
	  fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
	  fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
	  fl_set_slider_value(fd_teleoperatorgui->posR,(double)r);  
	}
    }

  if (obj==fd_teleoperatorgui->posOrigin) 
    { 
      guix=0.; guiy=0.; guiz=0.;
      fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
      fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
      fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
      fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double)0.);
      fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double)90.);
      fl_set_slider_value(fd_teleoperatorgui->posR,(double)0.); 
      if (fl_get_button(fd_teleoperatorgui->selectposition)==PUSHED)
	{
	  if (toggle==TRUE)
	    {
	      dx=virtualcam.foax - virtualcam.posx;
	      dy=virtualcam.foay - virtualcam.posy;
	      dz=virtualcam.foaz - virtualcam.posz;
	      virtualcam.foax=guix+dx;
	      virtualcam.foay=guiy+dy;
	      virtualcam.foaz=guiz+dz;
	    }
	  virtualcam.posx=guix; virtualcam.posy=guiy; virtualcam.posz=guiz;
	} 
      else if (fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED)
	{
	  virtualcam.foax=guix; 
	  virtualcam.foay=guiy; 
	  virtualcam.foaz=guiz;
	}
      else if (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED)
	{
	  virtualcam.foax=virtualcam.posx+guix; 
	  virtualcam.foay=virtualcam.posy+guiy; 
	  virtualcam.foaz=virtualcam.posz+guiz;
	}
    }
  else if ((obj==fd_teleoperatorgui->posX) ||
	   (obj==fd_teleoperatorgui->posY) || 
	   (obj==fd_teleoperatorgui->posZ))
    {
      guix=(float) fl_get_slider_value(fd_teleoperatorgui->posX);
      guiy=(float) fl_get_slider_value(fd_teleoperatorgui->posY);
      guiz=(float) fl_get_slider_value(fd_teleoperatorgui->posZ);
      if (fl_get_button(fd_teleoperatorgui->selectposition)==PUSHED)
	{
	  if (toggle==TRUE)
	    {
	      dx=virtualcam.foax - virtualcam.posx;
	      dy=virtualcam.foay - virtualcam.posy;
	      dz=virtualcam.foaz - virtualcam.posz;
	      virtualcam.foax=guix+dx;
	      virtualcam.foay=guiy+dy;
	      virtualcam.foaz=guiz+dz;
	    }
	  virtualcam.posx=guix; virtualcam.posy=guiy; virtualcam.posz=guiz;
	} 
      else if (fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED)
	{
	  virtualcam.foax=guix; 
	  virtualcam.foay=guiy; 
	  virtualcam.foaz=guiz;
	}
      else if (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED)
	{
	  virtualcam.foax=guix+virtualcam.posx;
	  virtualcam.foay=guiy+virtualcam.posy;
	  virtualcam.foaz=guiz+virtualcam.posz;
	}
      r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
      lati=(float)asin(guiz/r)*360./(2.*PI);
      longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);      
      fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
      fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
      fl_set_slider_value(fd_teleoperatorgui->posR,(double)r);  
    }
  else if ((obj==fd_teleoperatorgui->posR) ||
	   (obj==fd_teleoperatorgui->latlong))
    {
      longi=2*PI*fl_get_positioner_xvalue(fd_teleoperatorgui->latlong)/360.;
      lati=2*PI*fl_get_positioner_yvalue(fd_teleoperatorgui->latlong)/360.;
      r=fl_get_slider_value(fd_teleoperatorgui->posR);
      guix=r*cos(lati)*cos(longi);
      guiy=r*cos(lati)*sin(longi);
      guiz=r*sin(lati);
      fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
      fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
      fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
      if (fl_get_button(fd_teleoperatorgui->selectposition)==PUSHED)
	{
	  if (toggle==TRUE)
	    {
	      dx=virtualcam.foax - virtualcam.posx;
	      dy=virtualcam.foay - virtualcam.posy;
	      dz=virtualcam.foaz - virtualcam.posz;
	      virtualcam.foax=guix+dx;
	      virtualcam.foay=guiy+dy;
	      virtualcam.foaz=guiz+dz;
	    }
	  virtualcam.posx=guix; virtualcam.posy=guiy; virtualcam.posz=guiz;
	} 
      else if (fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED)
	{
	  virtualcam.foax=guix; 
	  virtualcam.foay=guiy; 
	  virtualcam.foaz=guiz;
	}
      else if (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED)
	{
	  virtualcam.foax=guix+virtualcam.posx;
	  virtualcam.foay=guiy+virtualcam.posy;
	  virtualcam.foaz=guiz+virtualcam.posz;
	}
    }
  else if (obj == fd_teleoperatorgui->track_robot) 
    {if (fl_get_button(obj)==PUSHED) 
      {
	track_robot=TRUE;
	fl_set_button(fd_teleoperatorgui->toggle,RELEASED);
	toggle=FALSE;
      }
    else track_robot=FALSE;
    } 
  else if (obj == fd_teleoperatorgui->toggle) 
    {if (fl_get_button(obj)==PUSHED) 
      {
	toggle=TRUE;
	fl_set_button(fd_teleoperatorgui->track_robot,RELEASED);
	track_robot=FALSE;
      }
    else toggle=FALSE;
    } 
  else if (obj == fd_teleoperatorgui->selectposition)
    {
      if (fl_get_button(fd_teleoperatorgui->selectposition)==PUSHED)
	{
	  fl_set_button(fd_teleoperatorgui->selectfoa,RELEASED);
	  fl_set_button(fd_teleoperatorgui->selectfoaRel,RELEASED);
	  guix=virtualcam.posx; guiy=virtualcam.posy; guiz=virtualcam.posz;	  
	  r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
	  lati=(float)asin(guiz/r)*360./(2.*PI);
	  longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);
	  fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
	  fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
	  fl_set_slider_value(fd_teleoperatorgui->posR,(double)r); 
	  fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
	  fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
	  fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
	}
    }
  else if (obj == fd_teleoperatorgui->selectfoa)
    {
      if (fl_get_button(fd_teleoperatorgui->selectfoa)==PUSHED)
	{
	  fl_set_button(fd_teleoperatorgui->selectposition,RELEASED);
	  fl_set_button(fd_teleoperatorgui->selectfoaRel,RELEASED);
	  guix=virtualcam.foax; 
	  guiy=virtualcam.foay; 
	  guiz=virtualcam.foaz;
	  r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
	  lati=(float)asin(guiz/r)*360./(2.*PI);
	  longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);
	  fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
	  fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
	  fl_set_slider_value(fd_teleoperatorgui->posR,(double)r); 
	  fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
	  fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
	  fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
	}
    }
  else if (obj == fd_teleoperatorgui->selectfoaRel)
    {
      if (fl_get_button(fd_teleoperatorgui->selectfoaRel)==PUSHED)
	{
	  fl_set_button(fd_teleoperatorgui->selectposition,RELEASED);
	  fl_set_button(fd_teleoperatorgui->selectfoa,RELEASED);
	  guix=virtualcam.foax-virtualcam.posx; 
	  guiy=virtualcam.foay-virtualcam.posy; 
	  guiz=virtualcam.foaz-virtualcam.posz;
	  r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
	  lati=(float)asin(guiz/r)*360./(2.*PI);
	  longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);
	  fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
	  fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
	  fl_set_slider_value(fd_teleoperatorgui->posR,(double)r); 
	  fl_set_slider_value(fd_teleoperatorgui->posX,(double)guix);
	  fl_set_slider_value(fd_teleoperatorgui->posY,(double)guiy);
	  fl_set_slider_value(fd_teleoperatorgui->posZ,(double)guiz);
	}
    }

  else if (obj == fd_teleoperatorgui->hide) 
    {
      teleoperator_guisuspend();
      /* it stops the robot when the teleoperatorGUI is disabled */
      if ((display_state & BASE_TELEOPERATOR)!=0)
	{
	  joystick_x=0.5;
	  joystick_y=0.5;
	}
    }
  else if (obj == fd_teleoperatorgui->joystick) 
    {
      if ((display_state & BASE_TELEOPERATOR)!=0) 
	{
	  if (fl_get_button(fd_teleoperatorgui->back)==RELEASED)
	    joystick_y=0.5+0.5*fl_get_positioner_yvalue(fd_teleoperatorgui->joystick);
	  else 
	    joystick_y=0.5-0.5*fl_get_positioner_yvalue(fd_teleoperatorgui->joystick);
	  joystick_x=fl_get_positioner_xvalue(fd_teleoperatorgui->joystick);
	  fl_redraw_object(fd_teleoperatorgui->joystick);
	}
    }    
   else if (obj == fd_teleoperatorgui->back) 
    {
      if (fl_get_button(fd_teleoperatorgui->back)==RELEASED)
	joystick_y=0.5+0.5*fl_get_positioner_yvalue(fd_teleoperatorgui->joystick);
      else 
	joystick_y=0.5-0.5*fl_get_positioner_yvalue(fd_teleoperatorgui->joystick);
      joystick_x=fl_get_positioner_xvalue(fd_teleoperatorgui->joystick);
      fl_redraw_object(fd_teleoperatorgui->joystick);
    }    
  else if (obj == fd_teleoperatorgui->stop) 
    {
      fl_set_positioner_xvalue(fd_teleoperatorgui->joystick,0.5);
      fl_set_positioner_yvalue(fd_teleoperatorgui->joystick,0.);
      joystick_x=0.5;
      joystick_y=0.5;
    }     
  else if (obj == fd_teleoperatorgui->pantilt_joystick) 
    {
      if ((display_state & PANTILT_TELEOPERATOR)!=0) 
	{pt_joystick_y=fl_get_positioner_yvalue(fd_teleoperatorgui->pantilt_joystick);
	pt_joystick_x=fl_get_positioner_xvalue(fd_teleoperatorgui->pantilt_joystick);
	/*  fl_redraw_object(fd_teleoperatorgui->pantilt_joystick);*/
	}
    }    
  else if (obj == fd_teleoperatorgui->pantilt_origin) 
    {
      if ((MAX_PAN_ANGLE - MIN_PAN_ANGLE) > 0.05) 
	pt_joystick_x= 1.-(0.-MIN_PAN_ANGLE)/(MAX_PAN_ANGLE-MIN_PAN_ANGLE);
      if ((MAX_TILT_ANGLE - MIN_TILT_ANGLE) > 0.05) 
	pt_joystick_y= (0.-MIN_TILT_ANGLE)/(MAX_TILT_ANGLE-MIN_TILT_ANGLE);   
    }     
  else if (obj == fd_teleoperatorgui->pantilt_stop) 
    {
      /* current pantilt position as initial command, to avoid any movement */
      if ((MAX_PAN_ANGLE - MIN_PAN_ANGLE) > 0.05) 
	pt_joystick_x= 1.-(pan_angle-MIN_PAN_ANGLE)/(MAX_PAN_ANGLE-MIN_PAN_ANGLE);
      if ((MAX_TILT_ANGLE - MIN_TILT_ANGLE) > 0.05) 
	pt_joystick_y= (tilt_angle-MIN_TILT_ANGLE)/(MAX_TILT_ANGLE-MIN_TILT_ANGLE);   
    }
  else if (obj == fd_teleoperatorgui->ptspeed)
    {
      speed_coef = fl_get_slider_value(fd_teleoperatorgui->ptspeed);
      longitude_speed=(1.-speed_coef)*MAX_SPEED_PANTILT;
      latitude_speed=(1.-speed_coef)*MAX_SPEED_PANTILT;
    }

  else if (obj == fd_teleoperatorgui->sonars)
    {
      if (fl_get_button(fd_teleoperatorgui->sonars)==PUSHED)
	{
	  display_state = display_state | DISPLAY_SONARS;
	  mysonars=(float *)myimport("sonars","us");
	  sonarsresume=(resumeFn)myimport("sonars","resume");
	  sonarssuspend=(suspendFn)myimport("sonars","suspend");
	  sonarsresume(teleoperator_id,NULL,NULL);
	}
      else 
	{
	  display_state = display_state & ~DISPLAY_SONARS;
	  sonarssuspend();
	}
    }
  else if (obj == fd_teleoperatorgui->laser)
    {
      if (fl_get_button(fd_teleoperatorgui->laser)==PUSHED)
	{
	  display_state = display_state | DISPLAY_LASER;
	  mylaser=(int *)myimport("laser","jde_laser");
	  laserresume=(resumeFn)myimport("laser","resume");
	  lasersuspend=(suspendFn *)myimport("laser","suspend");
	  laserresume(teleoperator_id,NULL,NULL);
	}
      else 
	{ 
	  display_state = display_state & ~DISPLAY_LASER;
	  lasersuspend();
	}
    }
  else if (obj == fd_teleoperatorgui->encoders)
    {
      if (fl_get_button(fd_teleoperatorgui->encoders)==PUSHED)
	{
	  display_state = display_state | DISPLAY_ROBOT;
	  myencoders=(float *)myimport("encoders","jde_robot");
	  encodersresume=(resumeFn)myimport("encoders","resume");
	  encoderssuspend=(suspendFn)myimport("encoders","suspend");
	  encodersresume(teleoperator_id,NULL,NULL);
	}
      else 
	{
	  display_state = display_state & ~DISPLAY_ROBOT;
	  encoderssuspend();
	}
    }
  else if (obj == fd_teleoperatorgui->motors)
    {
      if (fl_get_button(fd_teleoperatorgui->motors)==PUSHED)
	{
	  display_state = display_state | BASE_TELEOPERATOR;
	  myv=(float *)myimport("motors","v");
	  myw=(float *)myimport("motors","w");
	  motorsresume=(resumeFn)myimport("motors","resume");
	  motorssuspend=(suspendFn)myimport("motors","suspend");
	  motorsresume(teleoperator_id,NULL,NULL);
	}
      else
	{
	  v=0.; w=0.; /*safety stop when disabling the motors teleoperator */
	  display_state = display_state & ~BASE_TELEOPERATOR;
	  motorssuspend();
	}
    }
  else if (obj == fd_teleoperatorgui->PTmotors)
    {
      if (fl_get_button(fd_teleoperatorgui->PTmotors)==PUSHED)
	display_state = display_state | PANTILT_TELEOPERATOR;
      else 
	{
	  /*safety stop when disabling the teleoperator */
	  /* current pantilt position as initial command, to avoid any movement */
	  if ((MAX_PAN_ANGLE - MIN_PAN_ANGLE) > 0.05) 
	    pt_joystick_x= 1.-(pan_angle-MIN_PAN_ANGLE)/(MAX_PAN_ANGLE-MIN_PAN_ANGLE);
	  if ((MAX_TILT_ANGLE - MIN_TILT_ANGLE) > 0.05) 
	    pt_joystick_y= (tilt_angle-MIN_TILT_ANGLE)/(MAX_TILT_ANGLE-MIN_TILT_ANGLE);   
	  display_state = display_state & ~PANTILT_TELEOPERATOR;
	}
    }
  else if (obj == fd_teleoperatorgui->PTencoders)
    {
      if (fl_get_button(fd_teleoperatorgui->PTencoders)==PUSHED)
	display_state = display_state | DISPLAY_PANTILTENCODERS;
      else 
	display_state = display_state & ~DISPLAY_PANTILTENCODERS;
    }
  else if (obj == fd_teleoperatorgui->colorA)
    {
      if (fl_get_button(fd_teleoperatorgui->colorA)==PUSHED)
	display_state = display_state | DISPLAY_COLORIMAGEA;
      else 
	display_state = display_state & ~DISPLAY_COLORIMAGEA;
    }
  else if (obj == fd_teleoperatorgui->colorB)
    {
      if (fl_get_button(fd_teleoperatorgui->colorB)==PUSHED)
	display_state = display_state | DISPLAY_COLORIMAGEB;
      else 
	display_state = display_state & ~DISPLAY_COLORIMAGEB;
    }
  else if (obj == fd_teleoperatorgui->colorC)
    {
      if (fl_get_button(fd_teleoperatorgui->colorC)==PUSHED)
	display_state = display_state | DISPLAY_COLORIMAGEC;
      else 
	display_state = display_state & ~DISPLAY_COLORIMAGEC;
    }
  else if (obj == fd_teleoperatorgui->colorD)
    {
      if (fl_get_button(fd_teleoperatorgui->colorD)==PUSHED)
	display_state = display_state | DISPLAY_COLORIMAGED;
      else 
	display_state = display_state & ~DISPLAY_COLORIMAGED;
    }
  
  /* modifies pantilt positioner to follow pantilt angles. 
     It tracks the pantilt movement. It should be at
     display_poll, but there it causes a weird display behavior. */
  if ((MAX_PAN_ANGLE - MIN_PAN_ANGLE) > 0.05) 
    dpan= 1.-(pan_angle-MIN_PAN_ANGLE)/(MAX_PAN_ANGLE-MIN_PAN_ANGLE);
  if ((MAX_TILT_ANGLE - MIN_TILT_ANGLE) > 0.05) 
    dtilt= (tilt_angle-MIN_TILT_ANGLE)/(MAX_TILT_ANGLE-MIN_TILT_ANGLE);   
  fl_set_positioner_xvalue(fd_teleoperatorgui->pantilt_joystick,dpan);
  fl_set_positioner_yvalue(fd_teleoperatorgui->pantilt_joystick,dtilt);
  /*fl_redraw_object(fd_teleoperatorgui->pantilt_joystick);*/
}

void teleoperator_guidisplay()    
{
  int i,c,row,j,k;
  Tvoxel start,end;
  float r,lati,longi,dx,dy,dz;
  float matColors[4];
  float  Xp_sensor, Yp_sensor;

  fl_activate_glcanvas(fd_teleoperatorgui->canvas);
  /* Set the OpenGL state machine to the right context for this display */
  /* reset of the depth and color buffers */
  InitOGL(fd_teleoperatorgui->canvas, FL_ObjWin(fd_teleoperatorgui->canvas),fd_teleoperatorgui->canvas->w,fd_teleoperatorgui->canvas->h,NULL,NULL);
    
  /* Virtual camera */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  /* proyección ortográfica 
     glOrtho(-5.0,5.0,-5.0,5.0,1.0,100.0);
     glTranslatef(0,0,-5); */
  /* perspective projection. intrinsic parameters + frustrum */
  gluPerspective(45.,(GLfloat)640/(GLfloat)480,1.0,500.0);
  /* extrinsic parameters */
  gluLookAt(virtualcam.posx,virtualcam.posy,virtualcam.posz,virtualcam.foax,virtualcam.foay,virtualcam.foaz,0.,0.,1.);
  

  /** Absolute Frame of Reference **/  
  /* floor */ 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor3f( 0.6, 0.6, 0.6 );
  glBegin(GL_LINES);
  for(i=0;i<((int)MAXWORLD+1);i++)
    {
      v3f(-(int)MAXWORLD*10/2.+(float)i*10,-(int)MAXWORLD*10/2.,0.);
      v3f(-(int)MAXWORLD*10/2.+(float)i*10,(int)MAXWORLD*10/2.,0.);
      v3f(-(int)MAXWORLD*10/2.,-(int)MAXWORLD*10/2.+(float)i*10,0.);
      v3f((int)MAXWORLD*10/2.,-(int)MAXWORLD*10/2.+(float)i*10,0.);
    }
  glEnd();
  
  /* absolute axis */
  glLineWidth(3.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor3f( 0.7, 0., 0. );
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 10.0, 0.0, 0.0 );
  glEnd();
  glColor3f( 0.,0.7,0. );
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 0.0, 10.0, 0.0 );
  glEnd();
  glColor3f( 0.,0.,0.7 );
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 0.0, 0.0, 10.0 );
  glEnd();
  glLineWidth(1.0f);

  
  /** Robot Frame of Reference **/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  mypioneer.posx=jde_robot[0]/100.;
  mypioneer.posy=jde_robot[1]/100.;
  mypioneer.posz=0.;
  mypioneer.foax=jde_robot[0]/100.;
  mypioneer.foay=jde_robot[1]/100.;
  mypioneer.foaz=10.;
  mypioneer.roll=jde_robot[2]*RADTODEG;
  glTranslatef(mypioneer.posx,mypioneer.posy,mypioneer.posz);
  dx=(mypioneer.foax-mypioneer.posx);
  dy=(mypioneer.foay-mypioneer.posy);
  dz=(mypioneer.foaz-mypioneer.posz);
  longi=(float)atan2(dy,dx)*360./(2.*PI);
  glRotatef(longi,0.,0.,1.);
  r=sqrt(dx*dx+dy*dy+dz*dz);
  if (r<0.00001) lati=0.;
  else lati=acos(dz/r)*360./(2.*PI);
  glRotatef(lati,0.,1.,0.);
  glRotatef(mypioneer.roll,0.,0.,1.);
  
  /* X axis */
  glColor3f( 1., 0., 0. );
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 5.0, 0.0, 0.0 );
  glEnd();
  /* Y axis */
  glColor3f( 0., 1., 0. );  
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 0.0, 5.0, 0.0 );
  glEnd();
  /* Z axis */
  glColor3f( 0., 0., 1.);
  glBegin(GL_LINES);
  v3f( 0.0, 0.0, 0.0 );   
  v3f( 0.0, 0.0, 5.0 );
  glEnd();
  /* robot body */
  if ((display_state & DISPLAY_ROBOT)!=0)
    {
      glEnable (GL_LIGHTING);
      glPushMatrix();
      glTranslatef(1.,0.,0.);
      /* the body it is not centered. With this translation we center it */  
      loadModel();
      glPopMatrix();
      glDisable (GL_LIGHTING);
    }

  /* sonars */
  if ((display_state & DISPLAY_SONARS)!=0) 
    {
      glColor3f( 0., 0.8, 0. );
      glLineWidth(2.0f);
      for (k = 0; k < NUM_SONARS; k++) {
	start.x=us_coord[k][0];
	start.y=us_coord[k][1];
	Xp_sensor = us[k]; /* mm */
	Yp_sensor = 0.;
	/* Coordenadas del punto detectado por el US con respecto al sistema del sensor, eje x+ normal al sensor */
	end.x = us_coord[k][0] + Xp_sensor*us_coord[k][3] - Yp_sensor*us_coord[k][4];
	end.y = us_coord[k][1] + Yp_sensor*us_coord[k][3] + Xp_sensor*us_coord[k][4];
	glBegin(GL_LINES);
	glVertex3f (start.x/100., start.y/100., 2.0f);
	glVertex3f (end.x/100., end.y/100., 2.0f);
	glEnd();
      }
      glLineWidth(1.0f);
    }

  /* laser */
  if ((display_state & DISPLAY_LASER)!=0) 
    {
      glEnable (GL_LIGHTING);
      matColors[0] = 1.0;
      matColors[1] = 0.0;
      matColors[2] = 0.0;
      matColors[3] = 0.5;
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,matColors);
      /*
	glBegin(GL_POLYGON); 
	glVertex3f (laser_coord[0]*10./100., laser_coord[1]/100., 3.2);
      */
      start.x=laser_coord[0]*10.;
      start.y=laser_coord[1];
      for(k=0;k<NUM_LASER;k++) 
	{
	  Xp_sensor = jde_laser[k]*cos(((float)k-90.)*DEGTORAD); 
	  Yp_sensor = jde_laser[k]*sin(((float)k-90.)*DEGTORAD);
	  /* Coordenadas del punto detectado por el US con respecto al sistema del sensor, eje x+ normal al sensor */
	  end.x = laser_coord[0]*10. + Xp_sensor*laser_coord[3] - Yp_sensor*laser_coord[4];
	  end.y = laser_coord[1] + Yp_sensor*laser_coord[3] + Xp_sensor*laser_coord[4];
	  glBegin(GL_POLYGON); 
	  glVertex3f (laser_coord[0]*10./100., laser_coord[1]/100., 3.2);
	  glVertex3f (start.x/100., start.y/100., 3.2);
	  glVertex3f (end.x/100., end.y/100., 3.2);
	  glEnd();
	  start.x=end.x;
	  start.y=end.y;
	  /* glVertex3f (end.x/100., end.y/100., 3.2);*/
	}
      /*  glVertex3f (laser_coord[0]*10./100., laser_coord[1]/100., 3.2);*/
      glDisable (GL_LIGHTING);
    }
  
  /** intercambio de buffers **/
  glXSwapBuffers(fl_display, fl_get_canvas_id(fd_teleoperatorgui->canvas));

  /* sample image display */
  {
    /* Pasa de la imagen capturada a la imagen para visualizar (sampleimage_buf), "cambiando" de formato adecuadamente */
    if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8))
      {for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS; i++) 
	{ sampleimage_buf[i]= (unsigned char)tabla[(unsigned char)(samplesource[i*3])];}}
    else if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
      {
	for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS; i++)
	  { sampleimage_buf[i*2+1]=(0xf8&(samplesource[i*3+2]))+((0xe0&(samplesource[i*3+1]))>>5);
	  sampleimage_buf[i*2]=((0xf8&(samplesource[i*3]))>>3)+((0x1c&(samplesource[i*3+1]))<<3);
	  }
      }
    else if (((vmode==TrueColor)&&(fl_state[vmode].depth==24)) ||
	     ((vmode==TrueColor)&&(fl_state[vmode].depth==32)))
      {for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS; i++) 
	{ sampleimage_buf[i*4]=samplesource[i*3]; /* Blue Byte */
	sampleimage_buf[i*4+1]=samplesource[i*3+1]; /* Green Byte */
	sampleimage_buf[i*4+2]=samplesource[i*3+2]; /* Red Byte */
	sampleimage_buf[i*4+3]=0; /* dummy byte */  }
      }
  }
  
  /* color imageA display */
  if ((display_state&DISPLAY_COLORIMAGEA)!=0)
    {
      /* Pasa de la imagen capturada a la imagen para visualizar (imagenA_buf), "cambiando" de formato adecuadamente */
      if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenA_buf[i]= (unsigned char)tabla[(unsigned char)(colorA[j*3])];
	  }
	}
      else if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
	{
	  for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++)
	    { 
	      c=i%(SIFNTSC_COLUMNS/2);
	      row=i/(SIFNTSC_COLUMNS/2);
	      j=2*row*SIFNTSC_COLUMNS+2*c;
	      imagenA_buf[i*2+1]=(0xf8&(colorA[j*3+2]))+((0xe0&(colorA[j*3+1]))>>5);
	      imagenA_buf[i*2]=((0xf8&(colorA[j*3]))>>3)+((0x1c&(colorA[j*3+1]))<<3);
	    }
	}
      else if (((vmode==TrueColor)&&(fl_state[vmode].depth==24)) ||
	       ((vmode==TrueColor)&&(fl_state[vmode].depth==32)))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenA_buf[i*4]=colorA[j*3]; /* Blue Byte */
	    imagenA_buf[i*4+1]=colorA[j*3+1]; /* Green Byte */
	    imagenA_buf[i*4+2]=colorA[j*3+2]; /* Red Byte */
	    imagenA_buf[i*4+3]=0; /* dummy byte */  }
	}
    }
  
  /* color imageB display */
  if ((display_state&DISPLAY_COLORIMAGEB)!=0)
    {
      /* Pasa de la imagen capturada a la imagen para visualizar (imagenB_buf), "cambiando" de formato adecuadamente */
      if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenB_buf[i]= (unsigned char)tabla[(unsigned char)(colorB[j*3])];
	  }}
      else if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
	{
	  for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++)
	    { 
	      c=i%(SIFNTSC_COLUMNS/2);
	      row=i/(SIFNTSC_COLUMNS/2);
	      j=2*row*SIFNTSC_COLUMNS+2*c;
	      imagenB_buf[i*2+1]=(0xf8&(colorB[j*3+2]))+((0xe0&(colorB[j*3+1]))>>5);
	      imagenB_buf[i*2]=((0xf8&(colorB[j*3]))>>3)+((0x1c&(colorB[j*3+1]))<<3);
	    }
	}
      else if (((vmode==TrueColor)&&(fl_state[vmode].depth==24)) ||
	       ((vmode==TrueColor)&&(fl_state[vmode].depth==32)))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenB_buf[i*4]=colorB[j*3]; /* Blue Byte */
	    imagenB_buf[i*4+1]=colorB[j*3+1]; /* Green Byte */
	    imagenB_buf[i*4+2]=colorB[j*3+2]; /* Red Byte */
	    imagenB_buf[i*4+3]=0; /* dummy byte */  }
	}
    }
  
  /* color imageC display */
  if ((display_state&DISPLAY_COLORIMAGEC)!=0)
    {
      /* Pasa de la imagen capturada a la imagen para visualizar (imagenC_buf), "cambiando" de formato adecuadamente */
      if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenC_buf[i]= (unsigned char)tabla[(unsigned char)(colorC[j*3])];
	  }}
      else if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
	{
	  for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++)
	    { 
	      c=i%(SIFNTSC_COLUMNS/2);
	      row=i/(SIFNTSC_COLUMNS/2);
	      j=2*row*SIFNTSC_COLUMNS+2*c;
	      imagenC_buf[i*2+1]=(0xf8&(colorC[j*3+2]))+((0xe0&(colorC[j*3+1]))>>5);
	      imagenC_buf[i*2]=((0xf8&(colorC[j*3]))>>3)+((0x1c&(colorC[j*3+1]))<<3);
	    }
	}
      else if (((vmode==TrueColor)&&(fl_state[vmode].depth==24)) ||
	       ((vmode==TrueColor)&&(fl_state[vmode].depth==32)))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenC_buf[i*4]=colorC[j*3]; /* Blue Byte */
	    imagenC_buf[i*4+1]=colorC[j*3+1]; /* Green Byte */
	    imagenC_buf[i*4+2]=colorC[j*3+2]; /* Red Byte */
	    imagenC_buf[i*4+3]=0; /* dummy byte */  }
	}
    }
  
  /* color imageD display */
  if ((display_state&DISPLAY_COLORIMAGED)!=0)
    {
      /* Pasa de la imagen capturada a la imagen para visualizar (imagenD_buf), "cambiando" de formato adecuadamente */
      if ((vmode==PseudoColor)&&(fl_state[vmode].depth==8))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenD_buf[i]= (unsigned char)tabla[(unsigned char)(colorD[j*3])];
	  }}
      else if ((vmode==TrueColor)&&(fl_state[vmode].depth==16)) 
	{
	  for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++)
	    { 
	      c=i%(SIFNTSC_COLUMNS/2);
	      row=i/(SIFNTSC_COLUMNS/2);
	      j=2*row*SIFNTSC_COLUMNS+2*c;
	      imagenD_buf[i*2+1]=(0xf8&(colorD[j*3+2]))+((0xe0&(colorD[j*3+1]))>>5);
	      imagenD_buf[i*2]=((0xf8&(colorD[j*3]))>>3)+((0x1c&(colorD[j*3+1]))<<3);
	    }
	}
      else if (((vmode==TrueColor)&&(fl_state[vmode].depth==24)) ||
	       ((vmode==TrueColor)&&(fl_state[vmode].depth==32)))
	{for(i=0; i<SIFNTSC_ROWS*SIFNTSC_COLUMNS/4; i++) 
	  { 
	    c=i%(SIFNTSC_COLUMNS/2);
	    row=i/(SIFNTSC_COLUMNS/2);
	    j=2*row*SIFNTSC_COLUMNS+2*c;
	    imagenD_buf[i*4]=colorD[j*3]; /* Blue Byte */
	    imagenD_buf[i*4+1]=colorD[j*3+1]; /* Green Byte */
	    imagenD_buf[i*4+2]=colorD[j*3+2]; /* Red Byte */
	    imagenD_buf[i*4+3]=0; /* dummy byte */  }
	}
    }

  if ((display_state&DISPLAY_COLORIMAGEA)!=0)
    {    /* Draw screen onto display */
      XPutImage(display,teleoperatorgui_win,teleoperatorgui_gc,imagenA,0,0,fd_teleoperatorgui->ventanaA->x+1, fd_teleoperatorgui->ventanaA->y+1, SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2);
    }
  
  if ((display_state&DISPLAY_COLORIMAGEB)!=0)
    {    /* Draw screen onto display */
      XPutImage(display,teleoperatorgui_win,teleoperatorgui_gc,imagenB,0,0,fd_teleoperatorgui->ventanaB->x+1, fd_teleoperatorgui->ventanaB->y+1, SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2);
    }
  
  if ((display_state&DISPLAY_COLORIMAGEC)!=0)
    {    /* Draw screen onto display */
      XPutImage(display,teleoperatorgui_win,teleoperatorgui_gc,imagenC,0,0,fd_teleoperatorgui->ventanaC->x+1, fd_teleoperatorgui->ventanaC->y+1, SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2);
    }
  
  if ((display_state&DISPLAY_COLORIMAGED)!=0)
    {    /* Draw screen onto display */
      XPutImage(display,teleoperatorgui_win,teleoperatorgui_gc,imagenD,0,0,fd_teleoperatorgui->ventanaD->x+1, fd_teleoperatorgui->ventanaD->y+1, SIFNTSC_COLUMNS/2, SIFNTSC_ROWS/2);
    }
  
  /* Draw sample image onto display */
      XPutImage(display,teleoperatorgui_win,teleoperatorgui_gc,sampleimage,0,0,fd_teleoperatorgui->sampleimage->x+1, fd_teleoperatorgui->sampleimage->y+1, SIFNTSC_COLUMNS, SIFNTSC_ROWS);
}


void teleoperator_guisuspend(void)
{
  if ((display_state & BASE_TELEOPERATOR)!=0)
    {
      (*myv)=0; 
      (*myw)=0;
    }
  /* to make a safety stop when the robot is being teleoperated from GUI */
  delete_buttonscallback(teleoperator_guibuttons);
  delete_displaycallback(teleoperator_guidisplay);
  fl_hide_form(fd_teleoperatorgui->teleoperatorgui);
}

void teleoperator_guiresume(void)
{
  static int k=0;
  float r,lati,longi,guix,guiy,guiz;

  if (k==0) /* not initialized */
    {
      k++;
      fd_teleoperatorgui = create_form_teleoperatorgui();
      fl_set_form_position(fd_teleoperatorgui->teleoperatorgui,400,50);
      fl_show_form(fd_teleoperatorgui->teleoperatorgui,FL_PLACE_POSITION,FL_FULLBORDER,"teleoperator");
    
      image_displaysetup(); /* Tiene que ir despues de la inicializacion de Forms, pues hace uso de informacion que la libreria rellena en tiempo de ejecucion al iniciarse */
      fl_add_canvas_handler(fd_teleoperatorgui->canvas,Expose,InitOGL,0);
    }
  else 
    {
      fl_show_form(fd_teleoperatorgui->teleoperatorgui,FL_PLACE_POSITION,FL_FULLBORDER,"teleoperator");
    }

  fl_set_slider_bounds(fd_teleoperatorgui->posX,MAXWORLD*10,-MAXWORLD*10);
  fl_set_slider_bounds(fd_teleoperatorgui->posY,MAXWORLD*10,-MAXWORLD*10);
  fl_set_slider_bounds(fd_teleoperatorgui->posZ,MAXWORLD*10,-MAXWORLD*10);
  fl_set_positioner_xbounds(fd_teleoperatorgui->latlong,-180,180.);
  fl_set_positioner_ybounds(fd_teleoperatorgui->latlong,-89.99,89.99); 
  fl_set_slider_bounds(fd_teleoperatorgui->posR,MAXWORLD*10*2,0.);
  fl_set_button(fd_teleoperatorgui->selectfoaRel,RELEASED);
  fl_set_button(fd_teleoperatorgui->selectfoa,RELEASED);
  fl_set_button(fd_teleoperatorgui->selectposition,PUSHED);
  guix=(float) virtualcam.posx;
  guiy=(float) virtualcam.posy;
  guiz=(float) virtualcam.posz;
  r=(float)sqrt((double)(guix*guix+guiy*guiy+guiz*guiz));
  lati=(float)asin(guiz/r)*360./(2.*PI);
  longi=(float)atan2((float)guiy,(float)guix)*360./(2.*PI);
  fl_set_slider_value(fd_teleoperatorgui->posX,virtualcam.posx);
  fl_set_slider_value(fd_teleoperatorgui->posY,virtualcam.posy);
  fl_set_slider_value(fd_teleoperatorgui->posZ,virtualcam.posz);
  fl_set_positioner_xvalue(fd_teleoperatorgui->latlong,(double) longi);
  fl_set_positioner_yvalue(fd_teleoperatorgui->latlong,(double) lati);
  fl_set_slider_value(fd_teleoperatorgui->posR,(double)r); 
  if (track_robot==TRUE) fl_set_button(fd_teleoperatorgui->track_robot,PUSHED);
  else fl_set_button(fd_teleoperatorgui->track_robot,RELEASED);
  if (toggle==TRUE) fl_set_button(fd_teleoperatorgui->toggle,PUSHED);
  else fl_set_button(fd_teleoperatorgui->toggle,RELEASED);
  
  teleoperatorgui_win = FL_ObjWin(fd_teleoperatorgui->ventanaA);
  /* the window (teleoperatorgui_win) changes every time the form is hided and showed again. They need to be updated before displaying anything again */
  
  fl_set_positioner_xvalue(fd_teleoperatorgui->joystick,0.5);
  fl_set_positioner_yvalue(fd_teleoperatorgui->joystick,0.);
  joystick_x=0.5;
  joystick_y=0.5;	  
  fl_set_slider_value(fd_teleoperatorgui->ptspeed,(double)(1.-latitude_speed/MAX_SPEED_PANTILT));

  register_buttonscallback(teleoperator_guibuttons);
  register_displaycallback(teleoperator_guidisplay);
}
