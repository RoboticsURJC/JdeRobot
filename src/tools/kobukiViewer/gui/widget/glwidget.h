/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>
#include <QtWidgets>

#include <GL/glut.h>
#include <GL/gl.h>
#include <jderobot/types/laserData.h>

#include "../stategui.h"
#include "../../robot/robot.h"

#include "../../pioneer/pioneer.h"
#include "../../pioneer/pioneeropengl.h"

#define v3f glVertex3f
#define MAXWORLD 30
#define PI 3.1416

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(StateGUI *stategui, Robot* robot, QWidget *parent = 0);
    ~GLWidget();

    void RunGraphicsAlgorithm();

    void UpdateRobot();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setToCamera1 ();

    void drawRobot();
    void drawLaser();

private:

    JdeRobotTypes::LaserData laserData;

    StateGUI *stategui;
    Robot* robot;

    float  glcam_pos_X;
    float  glcam_pos_Y;
    float  glcam_pos_Z;
    float  glcam_foa_X;
    float  glcam_foa_Y;
    float  glcam_foa_Z;

    float lati;
    float longi;

    float old_x;
    float old_y;

    float radius;

    int width;
    int height;

    QMutex mutex;
    float robot_x;
    float robot_y;
    float robot_theta;
    float rueda_theta;
signals:
    void on_Destino_changed(float, float);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
};

#endif
