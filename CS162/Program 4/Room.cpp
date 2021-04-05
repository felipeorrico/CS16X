/*****************************************************************
** Program: Hunt The Wumpus
** File: Room.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Room class implementation
******************************************************************/

#include "Room.h"
#include "Wumpus.h"
#include "Gold.h"
#include "Bats.h"
#include "Pits.h"

/*********************************************************************
** Function: set_event
** Description: sets the event based on the event type of the room
** Parameters: references to objects of each possible event
** Pre-Conditions: assumes none are nullptr
** Post-Conditions: sets the room event to the desired type
*********************************************************************/
void Room::set_event(Wumpus& w1, Bats& b1, Pits& p1, Gold& g1, Rope& r1) //sets the type of event pointer in that room
{
	if (event_type == 1) { //wumpus
		room_event = &w1;
		symbol = "W";
	}
	else if (event_type == 2) { //pit
		//room_event = new Pits;
		room_event = &p1;
		symbol = "P";
	}
	else if (event_type == 3) { //Gold
		//room_event = new Gold;
		room_event = &g1;
		symbol = "G";
	}
	else if (event_type == 4) { //bats
		//room_event = new Bats;
		room_event = &b1;
		symbol = "B";
	}
	else if (event_type == 5) { //rope
		room_event = &r1;
		symbol = "R";
	}
}

/*********************************************************************
** Function: get_event_type
** Description: returns the event type of that room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns event type
*********************************************************************/
int Room::get_event_type()
{
	return event_type;
}

/*********************************************************************
** Function: set_event_type
** Description: sets the type of event in that room
** Parameters: event type int
** Pre-Conditions: assumes valid int
** Post-Conditions: sets value
*********************************************************************/
void Room::set_event_type(int event_int)
{
	event_type = event_int;
}

/*********************************************************************
** Function: get_symbol
** Description: gets the room symbol to be displayed on the cheat grid
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns string
*********************************************************************/
string Room::get_symbol()
{
	return symbol;
}

/*********************************************************************
** Function: set_symbol
** Description: sets symbol
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: sets symbol
*********************************************************************/
void Room::set_symbol(string symbolic)
{
	symbol = symbolic;
}

/*********************************************************************
** Function: get_pointer
** Description: returns the pointer to the room event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns pointer
*********************************************************************/
Event* Room::get_pointer()
{
	return room_event;
}

/*********************************************************************
** Function: set_to_null
** Description: sets event pointer to null
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sets to null
*********************************************************************/
void Room::set_to_null()
{
	room_event = nullptr;
}

/*********************************************************************
** Function: Room
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Room::Room() {
	event_type = 0;
	symbol = " ";
}
