/*****************************************************************
** Program: Hunt The Wumpus
** File: Room.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Room class definition
******************************************************************/

#ifndef Room_h
#define Room_h

#include <string>
#include "Event.h"
#include "Bats.h"
#include "Wumpus.h"
#include "Gold.h"
#include "Pits.h"
#include "Rope.h"

using namespace std;

class Room {
	private:
		int event_type;
		string symbol;
		Event* room_event = nullptr;
	public:
		Room();
		void set_event(Wumpus &w1, Bats &b1, Pits &p1, Gold &g1, Rope &r1); //sets the Event pointer room_event using event type
		int get_event_type(); //1- wumpus, 2- pit, 3-gold, 4-bats, 5-rope
		void set_event_type(int);
		string get_symbol();
		void set_symbol(string);
		Event* get_pointer();
		void set_to_null();
};
#endif // !Room_h
