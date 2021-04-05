/*****************************************************************
** Program: Hunt The Wumpus
** File: Event.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Event class definition
******************************************************************/

#ifndef Event_h
#define Event_h

using namespace std;

class Event {
	public:
		virtual void percept() = 0;
		virtual void encounter(bool& trigger, bool& alive, bool& killed, int& x, int& y, bool& gold, int& size, bool& cave) = 0;
};
#endif // !Event_h
