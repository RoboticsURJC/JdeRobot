/*
 *
 *  Copyright (C) 1997-2009 JDERobot Developers Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/. 
 *
 *  Authors : David Lobato Bravo <dav.lobato@gmail.com>
 *
 */

#ifndef CAMERAVIEW_VIEWER_H
#define CAMERAVIEW_VIEWER_H

#include <gtkmm.h>
#include <libglademm.h>
#include <IceUtil/Thread.h>
#include <IceUtil/Time.h>
#include <string>
#include <opencv2/core/core.hpp>

  class Viewer
  {
  public:
    Viewer();
    ~Viewer();
  
    bool isVisible();

    //! function that actually displays the image in a window
    void display( cv::Mat& image, int rf, int gf, int bf );

  private:
    Glib::RefPtr<Gnome::Glade::Xml> refXml;
    Gtk::EventBox* eventbox;
    Gtk::Image* gtkimage;
    Gtk::Window* mainwindow;
    Gtk::Label* fpslabel;
    Gtk::Main gtkmain;
  
    //! display the frame rate of the received images
    void displayFrameRate();
    
    bool on_window_event ( GdkEvent* event );
    
    cv::Mat myImage;
    int r, g, b;
    int rF, gF, bF;
      
    //! time variables for calculating number of frames per second 
    IceUtil::Time currentFrameTime,oldFrameTime;
    double fps;
    int frameCount;
  };

#endif //CAMERAVIEW_VIEWER_H
