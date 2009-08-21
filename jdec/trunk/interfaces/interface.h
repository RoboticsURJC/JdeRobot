#ifndef INTERFACE_H
#define INTERFACE_H
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <jde.h>

#ifdef __cplusplus
extern "C" {
#endif

/*forward declaration for private data and typedef*/
typedef struct JDEInterface_p JDEInterface_p;
typedef struct JDEInterfacePrx_p JDEInterfacePrx_p;
 

/*forward declaration for JDESchema see schema.h*/
struct JDESchema;


/** JDEInterface type*/
typedef struct JDEInterface{
  /** Interface name*/
  char *interface_name;
  /** Schema implementing this interface*/
  struct JDESchema *supplier;
  /** Private data*/
  struct JDEInterface_p *priv;
} JDEInterface;
  
/** JDEInterfacePrx type. It is used to access JDEInterface*/
typedef struct JDEInterfacePrx{
  /** Interfaced referred by this proxy*/
  JDEInterface *refers_to;
  /** Schema using this proxy*/
  struct JDESchema *user;
  /** Private data*/
  struct JDEInterfacePrx_p *priv;
}JDEInterfacePrx;


/**
 * JDEInterface constructor
 * 
 * Allocate a new interface structure given the name and the schema
 * that supplies (implements) this interface.
 *
 * @param interface_name the name the interface will be known in the
 * system
 * @paran supplier the schema suplying (implementing) this interface
 * @return the new allocated interface
 *
 */
JDEInterface* new_JDEInterface(const char *interface_name,
			       struct JDESchema *const supplier);

/**
 * JDEInterface destructor
 *
 * It destroys the interface instance.
 * If self is NULL nothing happens.
 *
 * @param self interface to destroy
 * @return void
 */
void delete_JDEInterface(JDEInterface *const self);


/**
 * JDEInterfacePrx constructor
 *
 * It creates a proxy to access an interface with the given name.
 * Optionally, it is possible to give a pointer to a interface
 * structure to register it.
 * @param interface_name name to the referred interface
 * @param user schema using this proxy
 * @param refers_to interface instance, proxy will free it when the
 * last proxy is deleted
 * @return proxy instance
 */
JDEInterfacePrx* new_JDEInterfacePrx(const char *interface_name,
				     struct JDESchema *const user,
				     JDEInterface *const refers_to);

/**
 * JDEInterfacePrx destructor
 *
 * It destroys the proxy instance.
 * If self is NULL nothing happens.
 * @param self instance to destroy
 * @return void
 */
void delete_JDEInterfacePrx(JDEInterfacePrx *const self);

/**
 * Add a reference to an interface instance
 *
 * @param self interface instance with the new reference
 * @param referral proxy instance referring to this interface
 * @return void
 */
void JDEInterface_addref(JDEInterface *const self,
			 JDEInterfacePrx *const referral);

/**
 * Delete a reference to an interface instance
 *
 * @param self interface instance to delete the reference
 * @param referral proxy instance referring to this interface
 * @return void
 */
void JDEInterface_delref(JDEInterface *const self,
			 JDEInterfacePrx *const referral);

/**
 *  Reference count an interface instance has
 *
 * @param self interface instance
 * @return the reference count
 */
unsigned int JDEInterface_refcount(JDEInterface *const self);


/**
 *  Run the schema supplying this interface
 *
 * @param self interface proxy instance
 * @return void
 */
void JDEInterfacePrx_run(const JDEInterfacePrx *self);

/**
 *  Stop the schema supplying this interface
 *
 * @param self interface proxy instance
 * @return void
 */
void JDEInterfacePrx_stop(const JDEInterfacePrx *self);

#ifdef __cplusplus
}
#endif

/** Cast a interface or interface proxy to JDEInterface or JDEInterfacePrx*/
#define SUPER(i) ((i)->super)
/** Returns the reffered interface of given a proxy*/
#define PRX_REFERS_TO(prx) ((prx)->refers_to)
/** Returns the name of given interface*/
#define INTERFACE_NAME(i) ((i)->super->interface_name)
/** Returns the name of given interface proxy*/
#define INTERFACEPRX_NAME(prx) ((prx)->super->refers_to->interface_name)



/**Private macros*/
#define __CONCAT2(a,b) a ## b
#define __CONCAT3(a,b,c) a ## b ## c
#define __CONCAT4(a,b,c,d) a ## b ## c ## d
#define __STR(a) #a

/** Given X macro it will be executed with all the params*/
#define ATTR_X(X,ifacename,attrname,attrtype,attrarg) X(ifacename,attrname,attrtype,attrarg)


/** struct entry for VARIABLE*/
#define INTERFACE_ATTR_STRUCT_VARIABLE(ifacename,attrname,attrtype,attrarg) attrtype attrname ;
/** struct entry for ARRAY*/
#define INTERFACE_ATTR_STRUCT_ARRAY(ifacename,attrname,attrtype,attrarg) attrtype attrname [ attrarg ] ;
/** struct entry for SYNTHETIC*/
#define INTERFACE_ATTR_STRUCT_SYNTHETIC(ifacename,attrname,attrtype,attrarg)

/** Generates attr inside the struct declaration*/
#define INTERFACE_ATTR_STRUCT(ifacename,attrname,attrtype,attralloc,attrarg) \
  ATTR_X(INTERFACE_ATTR_STRUCT_ ## attralloc,ifacename,attrname,attrtype,attrarg)


#define INTERFACEPRX_ATTR_DECLARATION_VARIABLE(ifacename,attrname,attrtype,attrarg) \
  attrtype __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self); \
  void __CONCAT4(ifacename,Prx_,attrname,_set) ( __CONCAT2(ifacename,Prx) *const self, \
						 attrtype __CONCAT2(new_,attrname) );

#define INTERFACEPRX_ATTR_DECLARATION_ARRAY(ifacename,attrname,attrtype,attrarg) \
  attrtype * __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self); \
  void __CONCAT4(ifacename,Prx_,attrname,_set) ( __CONCAT2(ifacename,Prx) *const self, \
						 attrtype * __CONCAT2(new_,attrname) );

#define INTERFACEPRX_ATTR_DECLARATION_SYNTHETIC(ifacename,attrname,attrtype,attrarg) \
  attrtype __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self);
  

/** Generates interface proxy declaration for get/set accessor functions*/ 
#define INTERFACEPRX_ATTR_DECLARATION(ifacename,attrname,attrtype,attralloc,attrarg) \
  ATTR_X( INTERFACEPRX_ATTR_DECLARATION_ ## attralloc, ifacename,attrname,attrtype,attrarg)

#define INTERFACEPRX_ATTR_DEFINITION_VARIABLE(ifacename,attrname,attrtype,attrarg) \
  attrtype __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self){ \
    ifacename *iface = 0;						\
    									\
    assert(self!=0);							\
    iface = PRX_REFERS_TO(self);					\
    assert(iface!=0);							\
    return iface->attrname;						\
  }									\
  void __CONCAT4(ifacename,Prx_,attrname,_set) ( __CONCAT2(ifacename,Prx) *const self, \
						 attrtype __CONCAT2(new_,attrname) ){ \
    assert(self!=0);							\
    if (PRX_REFERS_TO(self)){						\
      ifacename *iface = PRX_REFERS_TO(self);				\
      iface->attrname = __CONCAT2(new_,attrname);			\
    }									\
  }
  
#define INTERFACEPRX_ATTR_DEFINITION_ARRAY(ifacename,attrname,attrtype,attrarg) \
  attrtype * __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self){ \
    ifacename *iface = 0;						\
    									\
    assert(self!=0);							\
    iface = PRX_REFERS_TO(self);					\
    assert(iface!=0);							\
    return iface->attrname;						\
  }									\
  void __CONCAT4(ifacename,Prx_,attrname,_set) ( __CONCAT2(ifacename,Prx) *const self, \
						 attrtype * __CONCAT2(new_,attrname) ){ \
    assert(self!=0);							\
    if (PRX_REFERS_TO(self)){						\
      ifacename *iface = PRX_REFERS_TO(self);				\
      memmove(iface->attrname, __CONCAT2(new_,attrname) , sizeof(attrtype) * attrarg ); \
    }									\
  }

#define INTERFACEPRX_ATTR_DEFINITION_SYNTHETIC(ifacename,attrname,attrtype,attrarg) \
  attrtype __CONCAT4(ifacename,Prx_,attrname,_get) (const __CONCAT2(ifacename,Prx) *self){ \
    ifacename *iface = 0;						\
    									\
    assert(self!=0);							\
    iface = PRX_REFERS_TO(self);					\
    assert(iface!=0);							\
    return attrarg;							\
  }
  
/** 
 * Generates interface proxy declarations for get/set accessor
 * functions
 */ 
#define INTERFACEPRX_ATTR_DEFINITION(ifacename,attrname,attrtype,attralloc,attrarg) \
  ATTR_X( INTERFACEPRX_ATTR_DEFINITION_ ## attralloc, ifacename,attrname,attrtype,attrarg)

  
/** 
 * Declares all the stuff around an interface. It should be included
 * in the interface header. It will declare the next things:
 *    -struct declaration for interface and proxy with all the
 *     attributes listed in attrs. They will be named like 'ifacename' and 'ifacename'Prx
 *    -constructors/destructors for interface and proxy. They will be
 *     named new_/delete_ followed by the struct name.
 *    -get/set accesors for the attributes through the proxy.
 *    .
 * The interface attributes (attrs argument) are supplied like a macro which will
 * expand to all the needed code. This macro have to be like that:
 *     #define iface_attrs(ATTR,I)		\
 *        ATTR(I,attr1,int,VARIABLE,0)		\
 *        ATTR(I,attr2,int,ARRAY,10)
 * where each ATTR line represent an interface atribute. ATTR and I
 * are macros that will be supplied on each step, if you don't want to
 * explore the internals just do it like in the example and forget
 * them. If you want to know more see X-macros. Given a ATTR declaration like this:
 * ATTR(I,attrname,attrtype,attralloc,attrarg)
 *    -attrname: attribute name
 *    -attrtype: attribute type. Any C type is allowed, even pointers.
 *    -attralloc: attribute allocation. It could be VARIABLE for
 *     normal attribute. ARRAY for array atributes, set method for
 *     these attributes will copy the whole array. SYNTHETIC for syntetic
 *     atributes which will be got from an expresion, only get method
 *     will be generated in these attributes.
 *    -attrarg: Each kind of attribute use this argument in a
 *     different way. VARIABLE doesn't use it. ARRAY use it to supply the
 *     array size. SYNTHETIC use it to supply the expresion. Inside the
 *     expresion is possible to refer any interface attribute using
 *     'iface->' and the attribute name. So, if we have an attribute X and
 *     we want to declare a synthetic attribute SQUARE, we just supply the
 *     expresion 'iface->X*iface->X'.
 *    .
 * Once defined the macro with the attributes we just have to call
 * INTERFACE_DECLARATION(name,attrs) that will generate all the code
 * for you.
 * A full example with all the generated declarations will be like
 * that:
 * 
 * #define A_attrs(ATTR,I)			\
 *    ATTR(I,x,int,VARIABLE,0)			\
 *    ATTR(I,v,float,ARRAY,8)			\
 *    ATTR(I,square,int,SYNTHETIC,iface->x*iface->x)
 * INTERFACE_DECLARATION(A,A_attrs)
 *
 * The generated declarations will be:
 *   typedef struct A{
 *     int x;
 *     float v[8];
 *     JDEInterface *super;
 *   } A;
 *   A *new_A (const char *interface_name, struct JDESchema *const supplier);
 *   void delete_A (A * const self);
 *
 *   typedef struct APrx{
 *     A *refers_to;
 *     JDEInterfacePrx *super;
 *   } APrx;
 *   APrx *new_APrx (const char *interface_name, struct JDESchema *const user,
 *                   A * const refers_to);
 *   void delete_APrx (APrx * const self);
 *
 *   int APrx_x_get (const APrx * self);
 *   void APrx_x_set (APrx * const self, int new_x);
 *
 *   float *APrx_v_get (const APrx * self);
 *   void APrx_v_set (APrx * const self, float *new_v);
 *
 *   int APrx_square_get (const APrx * self);
 *
 * 
 * @param ifacename is the name for this interface
 * @param attrs atribute macro list
 */
#define INTERFACE_DECLARATION(ifacename,attrs)				\
  typedef struct ifacename {						\
    attrs(INTERFACE_ATTR_STRUCT,ifacename)				\
    JDEInterface *super;						\
  } ifacename ;								\
									\
  ifacename * __CONCAT2(new_,ifacename) (const char *interface_name,	\
					 struct JDESchema *const supplier);	\
  void __CONCAT2(delete_,ifacename) ( ifacename *const self);		\
									\
  typedef struct __CONCAT2(ifacename,Prx) {				\
    ifacename *refers_to;/*if 0->backward compatibility*/		\
    JDEInterfacePrx *super;						\
  } __CONCAT2(ifacename,Prx) ;						\
  									\
  __CONCAT2(ifacename,Prx) * __CONCAT3(new_,ifacename,Prx) (const char *interface_name, \
							    struct JDESchema *const user, \
							    ifacename *const refers_to); \
  void __CONCAT3(delete_,ifacename,Prx) ( __CONCAT2(ifacename,Prx) *const self); \
  									\
  attrs(INTERFACEPRX_ATTR_DECLARATION,ifacename)
  

/** 
 * Define all the stuff around an interface. It should be included in
 * the code file, after  INTERFACE_DECLARATION. It takes the same
 * arguments than the related declaration.
 */
#define INTERFACE_DEFINITION(ifacename,attrs)				\
  ifacename * __CONCAT2(new_,ifacename) (const char *interface_name,	\
					 struct JDESchema *const supplier){	\
    ifacename * i;							\
    									\
    assert(supplier!=0);						\
    i = ( ifacename *)calloc(1,sizeof( ifacename ));			\
    assert(i!=0);							\
    SUPER(i) = new_JDEInterface(interface_name,supplier);		\
    assert(SUPER(i) != 0);						\
    return i;								\
  }									\
  void __CONCAT2(delete_,ifacename) ( ifacename * const self){		\
    if (self==0)							\
      return;								\
    free(self);								\
  }									\
									\
  __CONCAT2(ifacename,Prx) * __CONCAT3(new_,ifacename,Prx) (const char *interface_name, \
							    struct JDESchema *const user, \
							    ifacename *const refers_to){ \
    __CONCAT2(ifacename,Prx) * iprx;					\
    									\
    assert(user!=0);							\
    iprx = ( __CONCAT2(ifacename,Prx) *)calloc(1,sizeof( __CONCAT2(ifacename,Prx) )); \
    assert(iprx!=0);							\
    if (refers_to == 0){						\
      PRX_REFERS_TO(iprx) = ( ifacename *)myimport(interface_name,__STR(ifacename)); \
      SUPER(iprx) = new_JDEInterfacePrx(interface_name,user,0);		\
    }else{								\
      PRX_REFERS_TO(iprx) = refers_to;					\
      SUPER(iprx) = new_JDEInterfacePrx( INTERFACE_NAME(refers_to) ,	\
					user,				\
					SUPER(refers_to));		\
      myexport( INTERFACE_NAME(refers_to) ,__STR(ifacename),refers_to);	\
    }									\
    return iprx;							\
  }									\
  									\
  void __CONCAT3(delete_,ifacename,Prx) ( __CONCAT2(ifacename,Prx) *const self){ \
    if (self==0)							\
      return;								\
    									\
    if (PRX_REFERS_TO(self)){						\
      if (JDEInterface_refcount(PRX_REFERS_TO(SUPER(self)))==1){/*last reference*/ \
	/*FIXME: delete exported symbols*/				\
	__CONCAT2(delete_,ifacename) (PRX_REFERS_TO(self)); \
	PRX_REFERS_TO(SUPER(self)) = 0;/*JDEInterface has been destroyed*/ \
      }									\
    }									\
    delete_JDEInterfacePrx(SUPER(self));				\
    free(self);								\
  }									\
  attrs(INTERFACEPRX_ATTR_DEFINITION,ifacename)
  

#endif /*INTERFACE_H*/
