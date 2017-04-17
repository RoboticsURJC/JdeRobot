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
// Generated from file `replayControl.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

public interface _replayControlOperations
{
    boolean pause(Ice.Current __current);

    boolean resume(Ice.Current __current);

    void setReplay(boolean replay, Ice.Current __current);

    boolean setStep(int step, Ice.Current __current);

    long getTime(Ice.Current __current);

    boolean goTo(long seek, Ice.Current __current);

    ReplayerStatus getStatus(Ice.Current __current);
}
