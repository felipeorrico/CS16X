/*****************************************************************
** Program: Hunt The Wumpus
** File: Pits.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Pits class definition
******************************************************************/

#ifndef Pits_h
#define Pits_h

#include "Event.h"

using namespace std;

class Pits : public Event {
	
	public:
		virtual void percept();
		virtual void encounter(bool&, bool&, bool&, int&, int&, bool&, int&, bool&);
	private:

};

#endif // !Pits_h
