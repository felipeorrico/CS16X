/*****************************************************************
** Program: Hunt The Wumpus
** File: Rope.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Rope class implementation
******************************************************************/

#include "Rope.h"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: percept
** Description: happens when this class is next to the player
** Parameters: none
** Pre-Conditions: player has to be next to the room that contains this function
** Post-Conditions: print message to player
*********************************************************************/
void Rope::percept() {

}

/*********************************************************************
** Function: encounter
** Description: happens when player is in the same room as this function
** Parameters: (if arrow was fired, if player is alive, if killed wumpus, the position, 
	if has gold, the size of the grid, and if it is still in the cave)
** Pre-Conditions: has to be in the room to happen
** Post-Conditions: happens
*********************************************************************/
void Rope::encounter(bool& trigger, bool& alive, bool& killed, int& x, int& y, bool& gold, int& size, bool &cave) {
	if (gold == true && cave == true) {
		cout << "\nYou left the cave!\n";
		cave = false;
	}
	else {
		cout << "\nYou must kill the Wumpus and retrieve the gold or just retrieve the gold in order to leave the cave!\n";
	}
}