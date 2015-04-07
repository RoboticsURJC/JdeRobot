// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `navdata.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __navdata_h__
#define __navdata_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace jderobot
{

class NavdataData;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::jderobot::NavdataData>&);
::IceProxy::Ice::Object* upCast(::IceProxy::jderobot::NavdataData*);

class Navdata;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::jderobot::Navdata>&);
::IceProxy::Ice::Object* upCast(::IceProxy::jderobot::Navdata*);

}

}

namespace jderobot
{

class NavdataData;
bool operator==(const NavdataData&, const NavdataData&);
bool operator<(const NavdataData&, const NavdataData&);
::Ice::Object* upCast(::jderobot::NavdataData*);
typedef ::IceInternal::Handle< ::jderobot::NavdataData> NavdataDataPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::jderobot::NavdataData> NavdataDataPrx;
void __patch(NavdataDataPtr&, const ::Ice::ObjectPtr&);

class Navdata;
bool operator==(const Navdata&, const Navdata&);
bool operator<(const Navdata&, const Navdata&);
::Ice::Object* upCast(::jderobot::Navdata*);
typedef ::IceInternal::Handle< ::jderobot::Navdata> NavdataPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::jderobot::Navdata> NavdataPrx;
void __patch(NavdataPtr&, const ::Ice::ObjectPtr&);

}

namespace jderobot
{

typedef ::std::vector< ::Ice::Int> arrayInt;

typedef ::std::vector< ::Ice::Float> arrayFloat;

}

namespace jderobot
{

class Callback_Navdata_getNavdata_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Navdata_getNavdata_Base> Callback_Navdata_getNavdataPtr;

}

namespace IceProxy
{

namespace jderobot
{

class NavdataData : virtual public ::IceProxy::Ice::Object
{
public:
    
    ::IceInternal::ProxyHandle<NavdataData> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_secure(bool __secure) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_twoway() const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_oneway() const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_batchOneway() const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_datagram() const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_batchDatagram() const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_compress(bool __compress) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_timeout(int __timeout) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<NavdataData> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<NavdataData*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class Navdata : virtual public ::IceProxy::Ice::Object
{
public:

    ::jderobot::NavdataDataPtr getNavdata()
    {
        return getNavdata(0);
    }
    ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Context& __ctx)
    {
        return getNavdata(&__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_getNavdata(const ::IceInternal::Function<void (const ::jderobot::NavdataDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getNavdata(0, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_getNavdata(const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getNavdata(0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_getNavdata(const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::jderobot::NavdataDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getNavdata(&__ctx, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_getNavdata(const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getNavdata(&__ctx, ::Ice::newCallback(__completed, __sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_getNavdata(const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::jderobot::NavdataDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (const ::jderobot::NavdataDataPtr&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::jderobot::NavdataPrx __proxy = ::jderobot::NavdataPrx::uncheckedCast(__result->getProxy());
                ::jderobot::NavdataDataPtr __ret;
                try
                {
                    __ret = __proxy->end_getNavdata(__result);
                }
                catch(::Ice::Exception& ex)
                {
                    Cpp11FnCallbackNC::__exception(__result, ex);
                    return;
                }
                if(_response != nullptr)
                {
                    _response(__ret);
                }
            }
        
        private:
            
            ::std::function<void (const ::jderobot::NavdataDataPtr&)> _response;
        };
        return begin_getNavdata(__ctx, new Cpp11CB(__response, __exception, __sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_getNavdata()
    {
        return begin_getNavdata(0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getNavdata(const ::Ice::Context& __ctx)
    {
        return begin_getNavdata(&__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getNavdata(const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getNavdata(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getNavdata(const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getNavdata(&__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getNavdata(const ::jderobot::Callback_Navdata_getNavdataPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getNavdata(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getNavdata(const ::Ice::Context& __ctx, const ::jderobot::Callback_Navdata_getNavdataPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getNavdata(&__ctx, __del, __cookie);
    }

    ::jderobot::NavdataDataPtr end_getNavdata(const ::Ice::AsyncResultPtr&);
    
private:

    ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_getNavdata(const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<Navdata> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_secure(bool __secure) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_twoway() const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_oneway() const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_batchOneway() const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_datagram() const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_batchDatagram() const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_compress(bool __compress) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<Navdata> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<Navdata*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace jderobot
{

class NavdataData : virtual public ::IceDelegate::Ice::Object
{
public:
};

class Navdata : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace jderobot
{

class NavdataData : virtual public ::IceDelegate::jderobot::NavdataData,
                    virtual public ::IceDelegateM::Ice::Object
{
public:
};

class Navdata : virtual public ::IceDelegate::jderobot::Navdata,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace jderobot
{

class NavdataData : virtual public ::IceDelegate::jderobot::NavdataData,
                    virtual public ::IceDelegateD::Ice::Object
{
public:
};

class Navdata : virtual public ::IceDelegate::jderobot::Navdata,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace jderobot
{

class NavdataData : virtual public ::Ice::Object
{
public:

    typedef NavdataDataPrx ProxyType;
    typedef NavdataDataPtr PointerType;

    NavdataData()
    {
    }

    NavdataData(::Ice::Int __ice_vehicle, ::Ice::Int __ice_state, ::Ice::Float __ice_batteryPercent, ::Ice::Int __ice_magX, ::Ice::Int __ice_magY, ::Ice::Int __ice_magZ, ::Ice::Int __ice_pressure, ::Ice::Int __ice_temp, ::Ice::Float __ice_windSpeed, ::Ice::Float __ice_windAngle, ::Ice::Float __ice_windCompAngle, ::Ice::Float __ice_rotX, ::Ice::Float __ice_rotY, ::Ice::Float __ice_rotZ, ::Ice::Int __ice_altd, ::Ice::Float __ice_vx, ::Ice::Float __ice_vy, ::Ice::Float __ice_vz, ::Ice::Float __ice_ax, ::Ice::Float __ice_ay, ::Ice::Float __ice_az, ::Ice::Int __ice_tagsCount, const ::jderobot::arrayInt& __ice_tagsType, const ::jderobot::arrayInt& __ice_tagsXc, const ::jderobot::arrayInt& __ice_tagsYc, const ::jderobot::arrayInt& __ice_tagsWidth, const ::jderobot::arrayInt& __ice_tagsHeight, const ::jderobot::arrayFloat& __ice_tagsOrientation, const ::jderobot::arrayFloat& __ice_tagsDistance, ::Ice::Float __ice_tm) :
        vehicle(__ice_vehicle),
        state(__ice_state),
        batteryPercent(__ice_batteryPercent),
        magX(__ice_magX),
        magY(__ice_magY),
        magZ(__ice_magZ),
        pressure(__ice_pressure),
        temp(__ice_temp),
        windSpeed(__ice_windSpeed),
        windAngle(__ice_windAngle),
        windCompAngle(__ice_windCompAngle),
        rotX(__ice_rotX),
        rotY(__ice_rotY),
        rotZ(__ice_rotZ),
        altd(__ice_altd),
        vx(__ice_vx),
        vy(__ice_vy),
        vz(__ice_vz),
        ax(__ice_ax),
        ay(__ice_ay),
        az(__ice_az),
        tagsCount(__ice_tagsCount),
        tagsType(__ice_tagsType),
        tagsXc(__ice_tagsXc),
        tagsYc(__ice_tagsYc),
        tagsWidth(__ice_tagsWidth),
        tagsHeight(__ice_tagsHeight),
        tagsOrientation(__ice_tagsOrientation),
        tagsDistance(__ice_tagsDistance),
        tm(__ice_tm)
    {
    }

    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();


    static const ::Ice::ObjectFactoryPtr& ice_factory();

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif

public:

    ::Ice::Int vehicle;

    ::Ice::Int state;

    ::Ice::Float batteryPercent;

    ::Ice::Int magX;

    ::Ice::Int magY;

    ::Ice::Int magZ;

    ::Ice::Int pressure;

    ::Ice::Int temp;

    ::Ice::Float windSpeed;

    ::Ice::Float windAngle;

    ::Ice::Float windCompAngle;

    ::Ice::Float rotX;

    ::Ice::Float rotY;

    ::Ice::Float rotZ;

    ::Ice::Int altd;

    ::Ice::Float vx;

    ::Ice::Float vy;

    ::Ice::Float vz;

    ::Ice::Float ax;

    ::Ice::Float ay;

    ::Ice::Float az;

    ::Ice::Int tagsCount;

    ::jderobot::arrayInt tagsType;

    ::jderobot::arrayInt tagsXc;

    ::jderobot::arrayInt tagsYc;

    ::jderobot::arrayInt tagsWidth;

    ::jderobot::arrayInt tagsHeight;

    ::jderobot::arrayFloat tagsOrientation;

    ::jderobot::arrayFloat tagsDistance;

    ::Ice::Float tm;

protected:

    virtual ~NavdataData() {}

    friend class NavdataData__staticInit;
};

class NavdataData__staticInit
{
public:

    ::jderobot::NavdataData _init;
};

static NavdataData__staticInit _NavdataData_init;

inline bool operator==(const NavdataData& l, const NavdataData& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const NavdataData& l, const NavdataData& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

class Navdata : virtual public ::Ice::Object
{
public:

    typedef NavdataPrx ProxyType;
    typedef NavdataPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::jderobot::NavdataDataPtr getNavdata(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getNavdata(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const Navdata& l, const Navdata& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const Navdata& l, const Navdata& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace jderobot
{

template<class T>
class CallbackNC_Navdata_getNavdata : public Callback_Navdata_getNavdata_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const ::jderobot::NavdataDataPtr&);

    CallbackNC_Navdata_getNavdata(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::NavdataPrx __proxy = ::jderobot::NavdataPrx::uncheckedCast(__result->getProxy());
        ::jderobot::NavdataDataPtr __ret;
        try
        {
            __ret = __proxy->end_getNavdata(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::CallbackNC<T>::callback.get()->*response)(__ret);
        }
    }

    Response response;
};

template<class T> Callback_Navdata_getNavdataPtr
newCallback_Navdata_getNavdata(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::jderobot::NavdataDataPtr&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Navdata_getNavdata<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Navdata_getNavdataPtr
newCallback_Navdata_getNavdata(T* instance, void (T::*cb)(const ::jderobot::NavdataDataPtr&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Navdata_getNavdata<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_Navdata_getNavdata : public Callback_Navdata_getNavdata_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const ::jderobot::NavdataDataPtr&, const CT&);

    Callback_Navdata_getNavdata(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::NavdataPrx __proxy = ::jderobot::NavdataPrx::uncheckedCast(__result->getProxy());
        ::jderobot::NavdataDataPtr __ret;
        try
        {
            __ret = __proxy->end_getNavdata(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::Callback<T, CT>::callback.get()->*response)(__ret, CT::dynamicCast(__result->getCookie()));
        }
    }

    Response response;
};

template<class T, typename CT> Callback_Navdata_getNavdataPtr
newCallback_Navdata_getNavdata(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::jderobot::NavdataDataPtr&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Navdata_getNavdata<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Navdata_getNavdataPtr
newCallback_Navdata_getNavdata(T* instance, void (T::*cb)(const ::jderobot::NavdataDataPtr&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Navdata_getNavdata<T, CT>(instance, cb, excb, sentcb);
}

}

#endif