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
// Generated from file `remoteCloud.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

public final class remoteCloudHolder extends Ice.ObjectHolderBase<remoteCloud>
{
    public
    remoteCloudHolder()
    {
    }

    public
    remoteCloudHolder(remoteCloud value)
    {
        this.value = value;
    }

    public void
    patch(Ice.Object v)
    {
        if(v == null || v instanceof remoteCloud)
        {
            value = (remoteCloud)v;
        }
        else
        {
            IceInternal.Ex.throwUOE(type(), v);
        }
    }

    public String
    type()
    {
        return _remoteCloudDisp.ice_staticId();
    }
}
