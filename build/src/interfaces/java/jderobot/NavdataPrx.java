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

package jderobot;

public interface NavdataPrx extends Ice.ObjectPrx
{
    public NavdataData getNavdata();

    public NavdataData getNavdata(java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_getNavdata();

    public Ice.AsyncResult begin_getNavdata(java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_getNavdata(Ice.Callback __cb);

    public Ice.AsyncResult begin_getNavdata(java.util.Map<String, String> __ctx, Ice.Callback __cb);

    public Ice.AsyncResult begin_getNavdata(Callback_Navdata_getNavdata __cb);

    public Ice.AsyncResult begin_getNavdata(java.util.Map<String, String> __ctx, Callback_Navdata_getNavdata __cb);

    public NavdataData end_getNavdata(Ice.AsyncResult __result);
}
