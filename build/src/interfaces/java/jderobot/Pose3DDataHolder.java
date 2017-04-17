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
// Generated from file `pose3d.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

public final class Pose3DDataHolder extends Ice.ObjectHolderBase<Pose3DData>
{
    public
    Pose3DDataHolder()
    {
    }

    public
    Pose3DDataHolder(Pose3DData value)
    {
        this.value = value;
    }

    public void
    patch(Ice.Object v)
    {
        if(v == null || v instanceof Pose3DData)
        {
            value = (Pose3DData)v;
        }
        else
        {
            IceInternal.Ex.throwUOE(type(), v);
        }
    }

    public String
    type()
    {
        return Pose3DData.ice_staticId();
    }
}
