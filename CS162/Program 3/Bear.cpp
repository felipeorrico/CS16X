/*********************************************************************
** Program Filename: Bear.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Implementation of Bear Class
*********************************************************************/

#include <iostream>
#include <string>
#include "Animal.h"
#include "Bear.h"

using namespace std;

/*********************************************************************
** Function: constructor
** Description: none
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Bear::Bear() {
	set_age(0);
	set_cost(5000);
	set_food_multiplier(3);
	set_sick(false);
	set_num_babies(2);
	set_bought(false);
}

/*********************************************************************
** Function: destructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Bear::~Bear() {

}