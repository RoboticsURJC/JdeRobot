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
// Generated from file `jcm.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

public class FQExecutableName implements java.lang.Cloneable, java.io.Serializable
{
    public String executable;

    public String host;

    public FQExecutableName()
    {
    }

    public FQExecutableName(String executable, String host)
    {
        this.executable = executable;
        this.host = host;
    }

    public boolean
    equals(java.lang.Object rhs)
    {
        if(this == rhs)
        {
            return true;
        }
        FQExecutableName _r = null;
        if(rhs instanceof FQExecutableName)
        {
            _r = (FQExecutableName)rhs;
        }

        if(_r != null)
        {
            if(executable != _r.executable)
            {
                if(executable == null || _r.executable == null || !executable.equals(_r.executable))
                {
                    return false;
                }
            }
            if(host != _r.host)
            {
                if(host == null || _r.host == null || !host.equals(_r.host))
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    public int
    hashCode()
    {
        int __h = 5381;
        __h = IceInternal.HashUtil.hashAdd(__h, "::jderobot::FQExecutableName");
        __h = IceInternal.HashUtil.hashAdd(__h, executable);
        __h = IceInternal.HashUtil.hashAdd(__h, host);
        return __h;
    }

    public java.lang.Object
    clone()
    {
        java.lang.Object o = null;
        try
        {
            o = super.clone();
        }
        catch(CloneNotSupportedException ex)
        {
            assert false; // impossible
        }
        return o;
    }

    public void
    __write(IceInternal.BasicStream __os)
    {
        __os.writeString(executable);
        __os.writeString(host);
    }

    public void
    __read(IceInternal.BasicStream __is)
    {
        executable = __is.readString();
        host = __is.readString();
    }

    public static final long serialVersionUID = 5466950416377621140L;
}
