/*
 *
 *  Copyright (C) 1997-2010 JDE Developers Team
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
 *  Author : Roberto Calvo Palomino <rocapal@gmail.com>
 *
 */

#include "deviceRecorder.h"
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

void *record_function( void *ptr );

deviceRecorder::deviceRecorder(const jderobotice::Context& context,const jderobot::RecorderConfigPtr& recConfig,int recordingProvider) : GenericRecorder(context, recConfig, recordingProvider)
{

}

int deviceRecorder::doRecording()
{


	getContext().tracer().info ( "starting recording: Path = " +
								 getConfig()->path + " - FrameRate = " +
								 getConfig()->frameRate + " fps - " + " - device: " + getConfig()->device );


	//char *const parmList[] = {"mencoder","tv://","-tv", "driver=v4l:width=320:height=240:device=/dev/video0", "-ovc", "lavc", "-fps", "15.0", "-o", "webcam-15.mpg", NULL};

	if (getProvider() == RECORDING_PROVIDER_FFMPEG)
	{
		std::string v4lVersion, resolution;

		if (getConfig()->protocol == "v4l")
			v4lVersion = "video4linux";
		else
			v4lVersion = "video4linux2";

		resolution = getConfig()->width + "x" + getConfig()->height;

		char *parmList[] = {"ffmpeg","-loglevel","quiet","-y","-f","alsa","-r","16000","-f",
							(char*) v4lVersion.c_str(),"-s",(char*) resolution.c_str(),
							"-i",(char*) (getConfig()->device).c_str(),
							"-r",(char*) getConfig()->frameRate.c_str(),
							"-f","avi","-vcodec","mpeg4","-vtag","xvid","-sameq","-acodec","libmp3lame","-ab","96k",
							(char*) (getConfig()->path).c_str(),NULL};

		// Execute command
		execv("/usr/bin/ffmpeg", parmList);

	}
	else
	{
		getContext().tracer().error ("Recording Provider Unknow! - ");
		return -1;
	}


}






