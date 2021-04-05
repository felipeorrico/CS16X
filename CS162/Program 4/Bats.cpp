/*****************************************************************
** Program: Hunt The Wumpus
** File: Bats.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Bats class implementation
******************************************************************/

#include "Bats.h"
#include "Game.h"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: percept
** Description: happens when this class is next to the player
** Parameters: none
** Pre-Conditions: player has to be next to the room that contains this function
** Post-Conditions: print message to player
*********************************************************************/
void Bats::percept()
{
	cout << "\nYou hear wings flapping.\n";
}

/*********************************************************************
** Function: encounter
** Description: happens when player is in the same room as this function
** Parameters: (if arrow was fired, if player is alive, if killed wumpus, the position,
	if has gold, the size of the grid, and if it is still in the cave)
** Pre-Conditions: has to be in the room to happen
** Post-Conditions: happens
*********************************************************************/
void Bats::encounter(bool& trigger, bool& alive, bool& killed, int& x, int& y, bool& gold, int& size, bool& cave)
{
	cout << "\nYou were Picked up by a Super Bat!\n";
	x = get_random(size) - 1;
	y = get_random(size) - 1;
}
