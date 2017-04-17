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
// Generated from file `kinectleds.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <jderobot/kinectleds.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

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

namespace
{

const ::std::string __jderobot__KinectLeds__setLedActive_name = "setLedActive";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::jderobot::upCast(::IceProxy::jderobot::KinectLeds* p) { return p; }

void
::IceProxy::jderobot::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::jderobot::KinectLeds>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::jderobot::KinectLeds;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::jderobot::KinectLeds::setLedActive(::jderobot::KinectLedsAvailable led, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __jderobot__KinectLeds__setLedActive_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::jderobot::KinectLeds* __del = dynamic_cast< ::IceDelegate::jderobot::KinectLeds*>(__delBase.get());
            __del->setLedActive(led, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::jderobot::KinectLeds::begin_setLedActive(::jderobot::KinectLedsAvailable led, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __jderobot__KinectLeds__setLedActive_name, __del, __cookie);
    try
    {
        __result->__prepare(__jderobot__KinectLeds__setLedActive_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(led);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::jderobot::KinectLeds::end_setLedActive(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __jderobot__KinectLeds__setLedActive_name);
}

const ::std::string&
IceProxy::jderobot::KinectLeds::ice_staticId()
{
    return ::jderobot::KinectLeds::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::jderobot::KinectLeds::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::jderobot::KinectLeds);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::jderobot::KinectLeds::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::jderobot::KinectLeds);
}

::IceProxy::Ice::Object*
IceProxy::jderobot::KinectLeds::__newInstance() const
{
    return new KinectLeds;
}

void
IceDelegateM::jderobot::KinectLeds::setLedActive(::jderobot::KinectLedsAvailable led, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __jderobot__KinectLeds__setLedActive_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(led);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::jderobot::KinectLeds::setLedActive(::jderobot::KinectLedsAvailable led, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::jderobot::KinectLedsAvailable __p_led, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_led(__p_led)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::jderobot::KinectLeds* servant = dynamic_cast< ::jderobot::KinectLeds*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->setLedActive(_m_led, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::jderobot::KinectLedsAvailable _m_led;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __jderobot__KinectLeds__setLedActive_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(led, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* jderobot::upCast(::jderobot::KinectLeds* p) { return p; }

namespace
{
const ::std::string __jderobot__KinectLeds_ids[2] =
{
    "::Ice::Object",
    "::jderobot::KinectLeds"
};

}

bool
jderobot::KinectLeds::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__jderobot__KinectLeds_ids, __jderobot__KinectLeds_ids + 2, _s);
}

::std::vector< ::std::string>
jderobot::KinectLeds::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__jderobot__KinectLeds_ids[0], &__jderobot__KinectLeds_ids[2]);
}

const ::std::string&
jderobot::KinectLeds::ice_id(const ::Ice::Current&) const
{
    return __jderobot__KinectLeds_ids[1];
}

const ::std::string&
jderobot::KinectLeds::ice_staticId()
{
    return __jderobot__KinectLeds_ids[1];
}

::Ice::DispatchStatus
jderobot::KinectLeds::___setLedActive(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::jderobot::KinectLedsAvailable led;
    __is->read(led);
    __inS.endReadParams();
    setLedActive(led, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __jderobot__KinectLeds_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setLedActive"
};

}

::Ice::DispatchStatus
jderobot::KinectLeds::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__jderobot__KinectLeds_all, __jderobot__KinectLeds_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __jderobot__KinectLeds_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___setLedActive(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
jderobot::KinectLeds::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
jderobot::KinectLeds::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
jderobot::__patch(KinectLedsPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::jderobot::KinectLedsPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::jderobot::KinectLeds::ice_staticId(), v);
    }
}
