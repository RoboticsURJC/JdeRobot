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
// Generated from file `emSensor.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

public final class EMSensorDataPrxHelper extends Ice.ObjectPrxHelperBase implements EMSensorDataPrx
{
    public static EMSensorDataPrx checkedCast(Ice.ObjectPrx __obj)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            if(__obj instanceof EMSensorDataPrx)
            {
                __d = (EMSensorDataPrx)__obj;
            }
            else
            {
                if(__obj.ice_isA(ice_staticId()))
                {
                    EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static EMSensorDataPrx checkedCast(Ice.ObjectPrx __obj, java.util.Map<String, String> __ctx)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            if(__obj instanceof EMSensorDataPrx)
            {
                __d = (EMSensorDataPrx)__obj;
            }
            else
            {
                if(__obj.ice_isA(ice_staticId(), __ctx))
                {
                    EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static EMSensorDataPrx checkedCast(Ice.ObjectPrx __obj, String __facet)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId()))
                {
                    EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static EMSensorDataPrx checkedCast(Ice.ObjectPrx __obj, String __facet, java.util.Map<String, String> __ctx)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId(), __ctx))
                {
                    EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static EMSensorDataPrx uncheckedCast(Ice.ObjectPrx __obj)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            if(__obj instanceof EMSensorDataPrx)
            {
                __d = (EMSensorDataPrx)__obj;
            }
            else
            {
                EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
                __h.__copyFrom(__obj);
                __d = __h;
            }
        }
        return __d;
    }

    public static EMSensorDataPrx uncheckedCast(Ice.ObjectPrx __obj, String __facet)
    {
        EMSensorDataPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            EMSensorDataPrxHelper __h = new EMSensorDataPrxHelper();
            __h.__copyFrom(__bb);
            __d = __h;
        }
        return __d;
    }

    public static final String[] __ids =
    {
        "::Ice::Object",
        "::jderobot::EMSensorData"
    };

    public static String ice_staticId()
    {
        return __ids[1];
    }

    protected Ice._ObjectDelM __createDelegateM()
    {
        return new _EMSensorDataDelM();
    }

    protected Ice._ObjectDelD __createDelegateD()
    {
        return new _EMSensorDataDelD();
    }

    public static void __write(IceInternal.BasicStream __os, EMSensorDataPrx v)
    {
        __os.writeProxy(v);
    }

    public static EMSensorDataPrx __read(IceInternal.BasicStream __is)
    {
        Ice.ObjectPrx proxy = __is.readProxy();
        if(proxy != null)
        {
            EMSensorDataPrxHelper result = new EMSensorDataPrxHelper();
            result.__copyFrom(proxy);
            return result;
        }
        return null;
    }

    public static final long serialVersionUID = 0L;
}
