/*****************************************************************
** Program: Hunt The Wumpus
** File: Rope.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Rope class definition
******************************************************************/

#ifndef Rope_h
#define Rope_h

#include "Event.h"

using namespace std;

class Rope :
	public Event
{
	virtual void percept();
	virtual void encounter(bool&, bool&, bool&, int&, int&, bool&, int&, bool&);
};

#endif // !Rope_h