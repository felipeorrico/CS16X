/*****************************************************************
** Program: Hunt The Wumpus
** File: Wumpus.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Wumpus class implementation
******************************************************************/

#include "Wumpus.h"
#include "Event.h"
#include <iostream>
#include "Game.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: happens when this class is next to the player
** Parameters: none
** Pre-Conditions: player has to be next to the room that contains this function
** Post-Conditions: print message to player
*********************************************************************/
void Wumpus::percept() {
	cout << "\nYou smell a terrible stench.\n";
}

/*********************************************************************
** Function: encounter
** Description: happens when player is in the same room as this function
** Parameters: (if arrow was fired, if player is alive, if killed wumpus, the position,
	if has gold, the size of the grid, and if it is still in the cave)
** Pre-Conditions: has to be in the room to happen
** Post-Conditions: happens
*********************************************************************/
void Wumpus::encounter(bool& trigger, bool& alive, bool& killed, int& x, int& y, bool& gold, int& size, bool& cave) {
	if (trigger == true) {
		trigger = false;
		cout << "\nYou killed the WUMPUS!\n";
		alive = true;
		killed = true;
	}
	else {
		cout << "\nYou were killed by the WUMPUS!\n";
		alive = false;
		killed = false;
	}
	//if statements for the check if arrow was fired or not, if 
	//fired kill wumpus, if not, player dies.
}