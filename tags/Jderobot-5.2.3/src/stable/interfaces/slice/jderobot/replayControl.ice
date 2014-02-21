/*
 *  Copyright (C) 1997-2013 JDE Developers Team
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
 *  Authors : 
 *            Francisco Miguel Rivas Montero <franciscomiguel.rivas@urjc.es>	
 */

#ifndef REPLAYCONTROL_ICE
#define REPLAYCONTROL_ICE

module jderobot{  

	interface replayControl{
		
		bool pause();
		bool resume();
		void setReplay(bool replay);
		bool setStep(int step);
		long getTime();
		bool goTo(long seek);
	};
};
#endif 
