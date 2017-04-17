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
// Generated from file `visualization.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package jderobot;

/**
 * Interface to the Visualization interaction.
 **/
public interface VisualizationPrx extends Ice.ObjectPrx
{
    public void drawSegment(Segment seg, Color c);

    public void drawSegment(Segment seg, Color c, java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c, java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c, Ice.Callback __cb);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c, java.util.Map<String, String> __ctx, Ice.Callback __cb);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c, Callback_Visualization_drawSegment __cb);

    public Ice.AsyncResult begin_drawSegment(Segment seg, Color c, java.util.Map<String, String> __ctx, Callback_Visualization_drawSegment __cb);

    public void end_drawSegment(Ice.AsyncResult __result);

    public void drawPoint(Point p, Color c);

    public void drawPoint(Point p, Color c, java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c, java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c, Ice.Callback __cb);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c, java.util.Map<String, String> __ctx, Ice.Callback __cb);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c, Callback_Visualization_drawPoint __cb);

    public Ice.AsyncResult begin_drawPoint(Point p, Color c, java.util.Map<String, String> __ctx, Callback_Visualization_drawPoint __cb);

    public void end_drawPoint(Ice.AsyncResult __result);

    public void clearAll();

    public void clearAll(java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_clearAll();

    public Ice.AsyncResult begin_clearAll(java.util.Map<String, String> __ctx);

    public Ice.AsyncResult begin_clearAll(Ice.Callback __cb);

    public Ice.AsyncResult begin_clearAll(java.util.Map<String, String> __ctx, Ice.Callback __cb);

    public Ice.AsyncResult begin_clearAll(Callback_Visualization_clearAll __cb);

    public Ice.AsyncResult begin_clearAll(java.util.Map<String, String> __ctx, Callback_Visualization_clearAll __cb);

    public void end_clearAll(Ice.AsyncResult __result);
}
