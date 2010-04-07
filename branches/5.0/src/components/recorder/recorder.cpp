/*
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

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <jderobot/recorder.h>
#include <jderobotice/component.h>
#include <jderobotice/application.h>
#include <list>

#include "ffmpegRecorder.h"

namespace RecorderProcess {

	class RecorderI: public jderobot::Recorder
	{
		public:
		  RecorderI(std::string& prefix,
					const jderobotice::Context& context)
			:prefix(prefix), context(context)
		  {

		  }


		  virtual Ice::Int startRecording(const jderobot::RecorderConfigPtr& recConfig,
										  const Ice::Current& c)
		  {

	    	  ffmpegRecorder* myRecorder = new ffmpegRecorder(context);
	    	  myRecorder->setConfig(recConfig);

	    	  myRecorder->startRecording();

	    	  std::cout << "Insert in list" << std::endl;
	    	  IceUtil::Mutex::Lock sync(listMutex);
	    	  recList.push_back(myRecorder);

	    	  // Return de Id of recording (id == pid)
	    	  return myRecorder->getId();

		  }

		  virtual Ice::Int stopRecording (Ice::Int recId, const Ice::Current& c)
		  {
			  IceUtil::Mutex::Lock sync(listMutex);
			  std::cout << "recList.size()=" << recList.size() << std::endl;


			  for (unsigned int i=0; i<recList.size(); i++)
			  {

				  std::cout << "recList[i]->getId(): " << recList[i]->getId() << " - recId: " << recId << std::endl;

				  if (recList[i]->getId() == recId)
				  {
					  std::cout << "Recorder::stopRecording, detele recording objetc ..." << std::endl;
					  recList[i]->stopRecording();
					  std::cout << "antes del delete" << std::endl;
					  delete (recList[i]);
					  std::cout << "antes del erase" << std::endl;
					  recList.erase(recList.begin()+i);

					  std::cout << "recList.size()=" << recList.size() << std::endl;

					  return 0;
				  }
			  }

			  context.tracer().info("Recorder::stopRecording - Warning: the recordId was not found!");

			  return 1;
		  }

		private:

		  std::string prefix;
		  jderobotice::Context context;

		  IceUtil::Mutex listMutex;
		  std::vector<GenericRecorder*> recList;

	};


	class Component: public jderobotice::Component
	{
	public:

		Component():jderobotice::Component("RecorderApp") {}

		virtual void start()
		{

			Ice::PropertiesPtr prop = context().properties();

			std::string objPrefix(context().tag() + ".Recorder.");
			std::string recorderName = prop->getProperty(objPrefix + "Name");

			//set the value
			prop->setProperty(objPrefix + "Name", recorderName);

			context().tracer().info("Creating recorder (" + objPrefix + "Name" +") " + recorderName);

			objRecorder = new RecorderI(objPrefix,context());
			context().createInterfaceWithString(objRecorder,recorderName);


		}

		virtual ~Component()
		{
		}

	private:

		Ice::ObjectPtr objRecorder;
	};

} //namespace

int main(int argc, char** argv)
{

	RecorderProcess::Component component;

	jderobotice::Application app(component);
	return app.jderobotMain(argc,argv);
}

