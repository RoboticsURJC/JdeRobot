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
// Generated from file `jointmotor.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package RoboCompJointMotor;

public final class _JointMotorDelM extends Ice._ObjectDelM implements _JointMotorDel
{
    public MotorParams[]
    getAllMotorParams(java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getAllMotorParams", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            __og.writeEmptyParams();
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                MotorParams[] __ret;
                __ret = MotorParamsListHelper.read(__is);
                __og.endReadParams();
                return __ret;
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public void
    getAllMotorState(MotorStateMapHolder mstateMap, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getAllMotorState", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            __og.writeEmptyParams();
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                mstateMap.value = MotorStateMapHelper.read(__is);
                __og.endReadParams();
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public BusParams
    getBusParams(java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getBusParams", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            __og.writeEmptyParams();
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                BusParams __ret;
                __ret = new BusParams();
                __ret.__read(__is);
                __og.endReadParams();
                return __ret;
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public MotorParams
    getMotorParams(String motor, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getMotorParams", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                __os.writeString(motor);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                MotorParams __ret;
                __ret = new MotorParams();
                __ret.__read(__is);
                __og.endReadParams();
                return __ret;
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public MotorState
    getMotorState(String motor, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getMotorState", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                __os.writeString(motor);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                MotorState __ret;
                __ret = new MotorState();
                __ret.__read(__is);
                __og.endReadParams();
                return __ret;
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public java.util.Map<java.lang.String, MotorState>
    getMotorStateMap(String[] mList, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("getMotorStateMap", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                MotorListHelper.write(__os, mList);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                IceInternal.BasicStream __is = __og.startReadParams();
                java.util.Map<java.lang.String, MotorState> __ret;
                __ret = MotorStateMapHelper.read(__is);
                __og.endReadParams();
                return __ret;
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public void
    setPosition(MotorGoalPosition goal, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               HardwareFailedException,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("setPosition", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                goal.__write(__os);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(HardwareFailedException __ex)
                    {
                        throw __ex;
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                __og.readEmptyParams();
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public void
    setSyncPosition(MotorGoalPosition[] listGoals, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               HardwareFailedException,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("setSyncPosition", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                MotorGoalPositionListHelper.write(__os, listGoals);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(HardwareFailedException __ex)
                    {
                        throw __ex;
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                __og.readEmptyParams();
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }

    public void
    setVelocity(MotorGoalVelocity goal, java.util.Map<String, String> __ctx, Ice.Instrumentation.InvocationObserver __observer)
        throws IceInternal.LocalExceptionWrapper,
               HardwareFailedException,
               UnknownMotorException
    {
        IceInternal.Outgoing __og = __handler.getOutgoing("setVelocity", Ice.OperationMode.Normal, __ctx, __observer);
        try
        {
            try
            {
                IceInternal.BasicStream __os = __og.startWriteParams(Ice.FormatType.DefaultFormat);
                goal.__write(__os);
                __og.endWriteParams();
            }
            catch(Ice.LocalException __ex)
            {
                __og.abort(__ex);
            }
            boolean __ok = __og.invoke();
            try
            {
                if(!__ok)
                {
                    try
                    {
                        __og.throwUserException();
                    }
                    catch(HardwareFailedException __ex)
                    {
                        throw __ex;
                    }
                    catch(UnknownMotorException __ex)
                    {
                        throw __ex;
                    }
                    catch(Ice.UserException __ex)
                    {
                        throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
                    }
                }
                __og.readEmptyParams();
            }
            catch(Ice.LocalException __ex)
            {
                throw new IceInternal.LocalExceptionWrapper(__ex, false);
            }
        }
        finally
        {
            __handler.reclaimOutgoing(__og);
        }
    }
}
