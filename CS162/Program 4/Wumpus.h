/*****************************************************************
** Program: Hunt The Wumpus
** File: Wumpus.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Wumpus class definition
******************************************************************/

#ifndef Wumpus_h
#define Wumpus_h

#include "Event.h"

using namespace std;

class Wumpus : public Event {
	public:
		virtual void percept();
		virtual void encounter(bool&, bool&, bool&, int&, int&, bool&, int&, bool&);
};

#endif // !Wumpus_h

