/*
 *  Copyright (C) 1997-2013 JDE Developers TeamrgbdViewer.camRGB
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 *  Author : Jose María Cañas <jmplaza@gsyc.es>
			Francisco Miguel Rivas Montero <franciscomiguel.rivas@urjc.es>

 */





#include <iostream>
#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <jderobot/pointcloud.h>
#include "rgbdViewergui.h"
#include "pthread.h"
#include "parallelIce/cameraClient.h"
#include "parallelIce/pointcloudClient.h"



#define MAX_COMPONENTS 20	

rgbdViewer::rgbdViewergui* rgbdViewergui_ptx;

jderobot::cameraClient* camRGB=NULL;
jderobot::cameraClient* camDEPTH=NULL;
jderobot::pointcloudClient* pcClient=NULL;




void *gui_thread(void* arg){
	try{
		//local data
		std::vector<jderobot::RGBPoint> cloud;
		cv::Mat rgb,depth;

		struct timeval post;
		long long int totalpre=0;
		long long int totalpost=0;

		//std::cout << "******************************** entro" << std::endl;
		while(rgbdViewergui_ptx->isVisible() && ! rgbdViewergui_ptx->isClosed()){
			//std::cout << "******************************** entro1" << std::endl;
			gettimeofday(&post,NULL);
			totalpost=post.tv_sec*1000000+post.tv_usec;

			if (camRGB!=NULL)
				rgb=camRGB->getImage();
			if (camDEPTH!=NULL)
				depth=camDEPTH->getImage();
			if (pcClient!=NULL)
				cloud=pcClient->getData();


			if ((rgb.rows!=0)&&(depth.rows!=0)){
				rgbdViewergui_ptx->updateAll(rgb,depth, cloud);
			}
			else if (rgb.rows!=0){
				rgbdViewergui_ptx->updateRGB(rgb);
			}
			else if (depth.rows!=0){
				rgbdViewergui_ptx->updateDEPTH(depth);
			}
			else{	
				rgbdViewergui_ptx->updatePointCloud(cloud);
			}
			if (totalpre !=0){
				if ((totalpost - totalpre) > rgbdViewergui_ptx->getCycle() ){
					std::cout<<"-------- rgbdViewer: timeout-" << std::endl;
				}
				else{
					usleep(rgbdViewergui_ptx->getCycle() - (totalpost - totalpre));
				}
			}
			totalpre=totalpost;


		}
	}catch (const Ice::Exception& ex) {
		std::cerr << ex << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
	pthread_exit(NULL);
	return NULL;
}

/**
 * \brief Main program function code
 */
int main(int argc, char** argv){

	int status,i;
	Ice::CommunicatorPtr ic;
	int n_components=0;
	pthread_t threads[MAX_COMPONENTS];
	pthread_attr_t attr;
	Ice::PropertiesPtr prop;
	bool create_gui=false;



	bool rgbCamSelected=false;
	bool depthCamSelected=false;
	bool pointCloudSelected=false;
	int globalWidth;
	int globalHeight;

	

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	try{
		ic = Ice::initialize(argc,argv);
		prop = ic->getProperties();
	}catch (const Ice::Exception& ex) {
		std::cerr << ex << std::endl;
		return 1;
	}
	catch (const char* msg) {
		std::cerr <<"Error :" << msg << std::endl;
		return 1;
	}
	if (prop->getPropertyAsIntWithDefault("rgbdViewer.CameraRGBActive",0)){
		camRGB = new jderobot::cameraClient(ic,"rgbdViewer.CameraRGB.",false);
		if (camRGB != NULL){
			rgbCamSelected=true;
			camRGB->start();
			create_gui=true;
		}

	}
	if (prop->getPropertyAsIntWithDefault("rgbdViewer.CameraDEPTHActive",0)){
		camDEPTH = new jderobot::cameraClient(ic,"rgbdViewer.CameraDEPTH.",false);
		if (camDEPTH != NULL){
			depthCamSelected=true;
			camDEPTH->start();
			create_gui=true;
		}
	}


	if (prop->getPropertyAsIntWithDefault("rgbdViewer.pointCloudActive",0)){
		pcClient = new jderobot::pointcloudClient(ic,"rgbdViewer.pointCloud.",false);
		if (pcClient!= NULL){
			pcClient->start();
			pointCloudSelected=true;
			create_gui=true;
		}
	}

	globalHeight=prop->getPropertyAsIntWithDefault("rgbdViewer.Height",240);
	globalWidth=prop->getPropertyAsIntWithDefault("rgbdViewer.Width",320);
	int fps=prop->getPropertyAsIntWithDefault("rgbdViewer.Fps",10);
	float cycle=(float)(1/(float)fps)*1000000;


	std::cout << rgbCamSelected <<", " << depthCamSelected << ", " << pointCloudSelected << std::endl;

	rgbdViewergui_ptx = new rgbdViewer::rgbdViewergui(rgbCamSelected,depthCamSelected, pointCloudSelected, prop->getProperty("rgbdViewer.WorldFile"), prop->getProperty("rgbdViewer.camRGB"), prop->getProperty("rgbdViewer.camIR"),globalWidth,globalHeight, cycle);
	
	if (create_gui){
		pthread_create(&threads[n_components], &attr, gui_thread,NULL);
		n_components++;
	}


	if (rgbdViewergui_ptx == NULL)
		throw "rgbdViewer: Could not create the grafic interface";
	for (i = 0; i < n_components; i++) {
		pthread_join(threads[i], NULL);
	}

	if (camRGB!=NULL)
		delete camRGB;
	if (camDEPTH!=NULL)
		delete camDEPTH;
	if (pcClient!=NULL)
		delete pcClient;


	if (ic)
		ic->destroy();
	return status;
}
