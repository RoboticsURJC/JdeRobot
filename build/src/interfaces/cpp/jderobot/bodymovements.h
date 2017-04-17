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
// Generated from file `bodymovements.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __jderobot__root_JdeRobot_build_src_interfaces_cpp_jderobot_bodymovements_h__
#define __jderobot__root_JdeRobot_build_src_interfaces_cpp_jderobot_bodymovements_h__

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
#include <jderobot/common.h>
#include <jderobot/body.h>
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

class BodyMovementsData;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::jderobot::BodyMovementsData>&);
::IceProxy::Ice::Object* upCast(::IceProxy::jderobot::BodyMovementsData*);

class BodyMovements;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::jderobot::BodyMovements>&);
::IceProxy::Ice::Object* upCast(::IceProxy::jderobot::BodyMovements*);

}

}

namespace jderobot
{

class BodyMovementsData;
bool operator==(const BodyMovementsData&, const BodyMovementsData&);
bool operator<(const BodyMovementsData&, const BodyMovementsData&);
::Ice::Object* upCast(::jderobot::BodyMovementsData*);
typedef ::IceInternal::Handle< ::jderobot::BodyMovementsData> BodyMovementsDataPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::jderobot::BodyMovementsData> BodyMovementsDataPrx;
void __patch(BodyMovementsDataPtr&, const ::Ice::ObjectPtr&);

class BodyMovements;
bool operator==(const BodyMovements&, const BodyMovements&);
bool operator<(const BodyMovements&, const BodyMovements&);
::Ice::Object* upCast(::jderobot::BodyMovements*);
typedef ::IceInternal::Handle< ::jderobot::BodyMovements> BodyMovementsPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::jderobot::BodyMovements> BodyMovementsPrx;
void __patch(BodyMovementsPtr&, const ::Ice::ObjectPtr&);

}

namespace jderobot
{

struct ArmPosition
{
    ::jderobot::BodyMotor shoulder;
    ::jderobot::BodyMotor elbow;
};

struct LegPosition
{
    ::jderobot::BodyMotor hip;
    ::jderobot::BodyMotor knee;
    ::jderobot::BodyMotor ankle;
};

struct BodyPosition
{
    ::jderobot::ArmPosition lArm;
    ::jderobot::ArmPosition rArm;
    ::jderobot::LegPosition rLeg;
    ::jderobot::LegPosition lLeg;
    ::jderobot::BodyMotor head;
    ::Ice::Float time;
};

typedef ::std::vector< ::jderobot::BodyPosition> BodyMov;

}

namespace Ice
{
template<>
struct StreamableTraits< ::jderobot::ArmPosition>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 24;
    static const bool fixedLength = true;
};

template<class S>
struct StreamWriter< ::jderobot::ArmPosition, S>
{
    static void write(S* __os, const ::jderobot::ArmPosition& v)
    {
        __os->write(v.shoulder);
        __os->write(v.elbow);
    }
};

template<class S>
struct StreamReader< ::jderobot::ArmPosition, S>
{
    static void read(S* __is, ::jderobot::ArmPosition& v)
    {
        __is->read(v.shoulder);
        __is->read(v.elbow);
    }
};

template<>
struct StreamableTraits< ::jderobot::LegPosition>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 36;
    static const bool fixedLength = true;
};

template<class S>
struct StreamWriter< ::jderobot::LegPosition, S>
{
    static void write(S* __os, const ::jderobot::LegPosition& v)
    {
        __os->write(v.hip);
        __os->write(v.knee);
        __os->write(v.ankle);
    }
};

template<class S>
struct StreamReader< ::jderobot::LegPosition, S>
{
    static void read(S* __is, ::jderobot::LegPosition& v)
    {
        __is->read(v.hip);
        __is->read(v.knee);
        __is->read(v.ankle);
    }
};

template<>
struct StreamableTraits< ::jderobot::BodyPosition>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 136;
    static const bool fixedLength = true;
};

template<class S>
struct StreamWriter< ::jderobot::BodyPosition, S>
{
    static void write(S* __os, const ::jderobot::BodyPosition& v)
    {
        __os->write(v.lArm);
        __os->write(v.rArm);
        __os->write(v.rLeg);
        __os->write(v.lLeg);
        __os->write(v.head);
        __os->write(v.time);
    }
};

template<class S>
struct StreamReader< ::jderobot::BodyPosition, S>
{
    static void read(S* __is, ::jderobot::BodyPosition& v)
    {
        __is->read(v.lArm);
        __is->read(v.rArm);
        __is->read(v.rLeg);
        __is->read(v.lLeg);
        __is->read(v.head);
        __is->read(v.time);
    }
};

}

namespace jderobot
{

class Callback_BodyMovements_doMovement_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_BodyMovements_doMovement_Base> Callback_BodyMovements_doMovementPtr;

class Callback_BodyMovements_getMovement_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_BodyMovements_getMovement_Base> Callback_BodyMovements_getMovementPtr;

}

namespace IceProxy
{

namespace jderobot
{

class BodyMovementsData : virtual public ::IceProxy::Ice::Object
{
public:
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_secure(bool __secure) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_twoway() const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_oneway() const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_batchOneway() const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_datagram() const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_batchDatagram() const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_compress(bool __compress) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_timeout(int __timeout) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovementsData> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<BodyMovementsData*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class BodyMovements : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr& data)
    {
        return doMovement(data, 0);
    }
    ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx)
    {
        return doMovement(data, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::IceInternal::Function<void (::Ice::Int)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_doMovement(data, 0, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_doMovement(data, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (::Ice::Int)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_doMovement(data, &__ctx, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_doMovement(data, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (::Ice::Int)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (::Ice::Int)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
                ::Ice::Int __ret;
                try
                {
                    __ret = __proxy->end_doMovement(__result);
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
            
            ::std::function<void (::Ice::Int)> _response;
        };
        return begin_doMovement(data, __ctx, new Cpp11CB(__response, __exception, __sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data)
    {
        return begin_doMovement(data, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx)
    {
        return begin_doMovement(data, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_doMovement(data, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_doMovement(data, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::jderobot::Callback_BodyMovements_doMovementPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_doMovement(data, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr& data, const ::Ice::Context& __ctx, const ::jderobot::Callback_BodyMovements_doMovementPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_doMovement(data, &__ctx, __del, __cookie);
    }

    ::Ice::Int end_doMovement(const ::Ice::AsyncResultPtr&);
    
private:

    ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:

    ::jderobot::BodyMovementsDataPtr getMovement()
    {
        return getMovement(0);
    }
    ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Context& __ctx)
    {
        return getMovement(&__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_getMovement(const ::IceInternal::Function<void (const ::jderobot::BodyMovementsDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getMovement(0, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_getMovement(const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getMovement(0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_getMovement(const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::jderobot::BodyMovementsDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getMovement(&__ctx, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_getMovement(const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getMovement(&__ctx, ::Ice::newCallback(__completed, __sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_getMovement(const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::jderobot::BodyMovementsDataPtr&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (const ::jderobot::BodyMovementsDataPtr&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
                ::jderobot::BodyMovementsDataPtr __ret;
                try
                {
                    __ret = __proxy->end_getMovement(__result);
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
            
            ::std::function<void (const ::jderobot::BodyMovementsDataPtr&)> _response;
        };
        return begin_getMovement(__ctx, new Cpp11CB(__response, __exception, __sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_getMovement()
    {
        return begin_getMovement(0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getMovement(const ::Ice::Context& __ctx)
    {
        return begin_getMovement(&__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getMovement(const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getMovement(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getMovement(const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getMovement(&__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getMovement(const ::jderobot::Callback_BodyMovements_getMovementPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getMovement(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getMovement(const ::Ice::Context& __ctx, const ::jderobot::Callback_BodyMovements_getMovementPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getMovement(&__ctx, __del, __cookie);
    }

    ::jderobot::BodyMovementsDataPtr end_getMovement(const ::Ice::AsyncResultPtr&);
    
private:

    ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_getMovement(const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_secure(bool __secure) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_twoway() const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_oneway() const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_batchOneway() const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_datagram() const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_batchDatagram() const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_compress(bool __compress) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_timeout(int __timeout) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<BodyMovements> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<BodyMovements*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
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

class BodyMovementsData : virtual public ::IceDelegate::Ice::Object
{
public:
};

class BodyMovements : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;

    virtual ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace jderobot
{

class BodyMovementsData : virtual public ::IceDelegate::jderobot::BodyMovementsData,
                          virtual public ::IceDelegateM::Ice::Object
{
public:
};

class BodyMovements : virtual public ::IceDelegate::jderobot::BodyMovements,
                      virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace jderobot
{

class BodyMovementsData : virtual public ::IceDelegate::jderobot::BodyMovementsData,
                          virtual public ::IceDelegateD::Ice::Object
{
public:
};

class BodyMovements : virtual public ::IceDelegate::jderobot::BodyMovements,
                      virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace jderobot
{

class BodyMovementsData : virtual public ::Ice::Object
{
public:

    typedef BodyMovementsDataPrx ProxyType;
    typedef BodyMovementsDataPtr PointerType;

    BodyMovementsData()
    {
    }

    explicit BodyMovementsData(const ::jderobot::BodyMov& __ice_mov) :
        mov(__ice_mov)
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

    ::jderobot::BodyMov mov;

protected:

    virtual ~BodyMovementsData() {}

    friend class BodyMovementsData__staticInit;
};

class BodyMovementsData__staticInit
{
public:

    ::jderobot::BodyMovementsData _init;
};

static BodyMovementsData__staticInit _BodyMovementsData_init;

inline bool operator==(const BodyMovementsData& l, const BodyMovementsData& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const BodyMovementsData& l, const BodyMovementsData& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

class BodyMovements : virtual public ::Ice::Object
{
public:

    typedef BodyMovementsPrx ProxyType;
    typedef BodyMovementsPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int doMovement(const ::jderobot::BodyMovementsDataPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___doMovement(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::jderobot::BodyMovementsDataPtr getMovement(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getMovement(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const BodyMovements& l, const BodyMovements& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const BodyMovements& l, const BodyMovements& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace jderobot
{

template<class T>
class CallbackNC_BodyMovements_doMovement : public Callback_BodyMovements_doMovement_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(::Ice::Int);

    CallbackNC_BodyMovements_doMovement(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_doMovement(__result);
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

template<class T> Callback_BodyMovements_doMovementPtr
newCallback_BodyMovements_doMovement(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_BodyMovements_doMovement<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_BodyMovements_doMovementPtr
newCallback_BodyMovements_doMovement(T* instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_BodyMovements_doMovement<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_BodyMovements_doMovement : public Callback_BodyMovements_doMovement_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(::Ice::Int, const CT&);

    Callback_BodyMovements_doMovement(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_doMovement(__result);
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

template<class T, typename CT> Callback_BodyMovements_doMovementPtr
newCallback_BodyMovements_doMovement(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_BodyMovements_doMovement<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_BodyMovements_doMovementPtr
newCallback_BodyMovements_doMovement(T* instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_BodyMovements_doMovement<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_BodyMovements_getMovement : public Callback_BodyMovements_getMovement_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const ::jderobot::BodyMovementsDataPtr&);

    CallbackNC_BodyMovements_getMovement(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
        ::jderobot::BodyMovementsDataPtr __ret;
        try
        {
            __ret = __proxy->end_getMovement(__result);
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

template<class T> Callback_BodyMovements_getMovementPtr
newCallback_BodyMovements_getMovement(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::jderobot::BodyMovementsDataPtr&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_BodyMovements_getMovement<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_BodyMovements_getMovementPtr
newCallback_BodyMovements_getMovement(T* instance, void (T::*cb)(const ::jderobot::BodyMovementsDataPtr&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_BodyMovements_getMovement<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_BodyMovements_getMovement : public Callback_BodyMovements_getMovement_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const ::jderobot::BodyMovementsDataPtr&, const CT&);

    Callback_BodyMovements_getMovement(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::jderobot::BodyMovementsPrx __proxy = ::jderobot::BodyMovementsPrx::uncheckedCast(__result->getProxy());
        ::jderobot::BodyMovementsDataPtr __ret;
        try
        {
            __ret = __proxy->end_getMovement(__result);
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

template<class T, typename CT> Callback_BodyMovements_getMovementPtr
newCallback_BodyMovements_getMovement(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::jderobot::BodyMovementsDataPtr&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_BodyMovements_getMovement<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_BodyMovements_getMovementPtr
newCallback_BodyMovements_getMovement(T* instance, void (T::*cb)(const ::jderobot::BodyMovementsDataPtr&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_BodyMovements_getMovement<T, CT>(instance, cb, excb, sentcb);
}

}

#endif
