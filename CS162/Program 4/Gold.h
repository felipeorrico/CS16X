/*****************************************************************
** Program: Hunt The Wumpus
** File: Gold.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Gold class definition
******************************************************************/

#ifndef Gold_h
#define Gold_h

#include "Event.h"

using namespace std;

class Gold : public Event {
	public:
	private:
		virtual void percept();
		virtual void encounter(bool&, bool&, bool&, int&, int&, bool&, int&, bool&);
};

#endif // !Gold_h

