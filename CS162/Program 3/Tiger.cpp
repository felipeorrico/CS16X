/*********************************************************************
** Program Filename: Tiger.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Implementation of Tiger Class
*********************************************************************/

#include <iostream>
#include <string>
#include "Animal.h"
#include "Tiger.h"

using namespace std;

/*********************************************************************
** Function: constructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::Tiger() {
	set_age(0);
	set_cost(12000);
	set_food_multiplier(5);
	set_sick(false);
	set_num_babies(3);
	set_bought(false);
}

/*********************************************************************
** Function: Destructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::~Tiger() {

}
