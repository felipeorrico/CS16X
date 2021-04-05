/*********************************************************************
** Program Filename: Sea_lion.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Implementation of Sea Lion Class
*********************************************************************/

#include <iostream>
#include <string>
#include "Animal.h"
#include "Sea_lion.h"

using namespace std;

/*********************************************************************
** Function: Slion
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Slion::Slion() {
	bonus_multiplier = 0;
	set_age(0);
	set_cost(700);
	set_food_multiplier(1);
	set_sick(false);
	set_num_babies(1);
	set_bought(false);
}

/*********************************************************************
** Function: destructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Slion::~Slion() {

}

/*********************************************************************
** Function: set_bonus	
** Description: sets bonus multiplier of animal
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Slion::set_bonus(float new_bonus) {
	bonus_multiplier = new_bonus;
}

/*********************************************************************
** Function: get bonus
** Description: gets multiplier
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Slion::get_bonus() {
	return bonus_multiplier;
}