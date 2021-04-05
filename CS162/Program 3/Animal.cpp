/*********************************************************************
** Program Filename: Animal.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Implementation of Animal Class
*********************************************************************/

#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

//constructors and destructors start here

/*********************************************************************
** Function: Animal()
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::Animal() {
	age = 0;
	cost = 0;
	food_multiplier = 0;
	num_babies = 0;
	sick = false;
	bought = false;
}


/*********************************************************************
** Function: ~Animal
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::~Animal() {

}
//constructors and destructors end here

//setters and getters start here

/*********************************************************************
** Function: set_age
** Description: sets age
** Parameters: new age
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::set_age(int new_age) {
	age = new_age;
}

/*********************************************************************
** Function: get_age
** Description: returns age
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int Animal::get_age() const {
	return age;
}

/*********************************************************************
** Function: set_cost
** Description: sets cost
** Parameters: new cost
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::set_cost(float new_cost) {
	cost = new_cost;
}

/*********************************************************************
** Function: get_cost
** Description: gets cost
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Animal::get_cost() const {
	return cost;
}

/*********************************************************************
** Function: get_num_babies
** Description: gets number of babies animal can have
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_num_babies() const {
	return num_babies;
}

/*********************************************************************
** Function: set_num_babies
** Description: sets num babies
** Parameters: new num
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
void Animal::set_num_babies(int new_num) {
	num_babies = new_num;
}

/*********************************************************************
** Function: is_sick
** Description: checks if anima is sick
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Animal::is_sick() const {
	return sick;
}

/*********************************************************************
** Function: set_sick
** Description: sets animal sick or not
** Parameters: state
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::set_sick(bool new_state) {
	sick = new_state;
}

/*********************************************************************
** Function: set food multiplier
** Description: sets food multiplier
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::set_food_multiplier(float new_mult) {
	food_multiplier = new_mult;
}

/*********************************************************************
** Function: get food multiplier
** Description: gets food multiplier
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Animal::get_food_multiplier() {
	return food_multiplier;
}

/*********************************************************************
** Function: is bought
** Description: checks if animal was bought
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Animal::is_bought() {
	return bought;
}

/*********************************************************************
** Function: set bought
** Description: sets if the animal was bought or not
** Parameters: is
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::set_bought(bool is) {
	bought = is;
}
//setters and getters end here