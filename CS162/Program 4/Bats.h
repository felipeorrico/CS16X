/*****************************************************************
** Program: Hunt The Wumpus
** File: Bats.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Bats class definition
******************************************************************/

#ifndef Bats_h
#define Bats_h

#include "Event.h"

using namespace std;

class Bats : public Event {
	private:
	public:
		virtual void percept();
		virtual void encounter(bool&, bool&, bool&, int&, int&, bool&, int&, bool&);
};

#endif // !Bats_h

