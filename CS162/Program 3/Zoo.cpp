/*********************************************************************
** Program Filename: Zoo.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Implementation of zoo class
** Input: game choices
** Output: game events
*********************************************************************/
#include <iostream>
#include <string>
#include "Zoo.h"
#include <ctime>
#include <cstdlib>

using namespace std;

//constructors and destructors start here

/*********************************************************************
** Function: constructor
** Description:  none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Zoo::Zoo() { //default constructor =)
	current_time = 0;
	game_money = 100000;
	base_food_cost = 80;
	current_food_cost = 80;
	number_of_bears = 0;
	number_of_slions = 0;
	number_of_tigers = 0;
	tiger_list = new Tiger[1000];
	slion_list = new Slion[1000];
	bear_list = new Bear[1000];
	boom = false;
	bought_bears = 0;
	bought_slions = 0;
	bought_tigers = 0;
	tiger_contains_adult = false;
	slion_contains_adult = false;
	bear_contains_adult = false;
	number_adults_bear = 0;
	number_adults_slion = 0;
	number_adults_tiger = 0;
}

/*********************************************************************
** Function: destructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Zoo::~Zoo() { //destructor
	delete[] tiger_list;
	delete[] slion_list;
	delete[] bear_list;
	tiger_list = nullptr;
	slion_list = nullptr;
	bear_list = nullptr;
}

//constructors and destructors end here


//setters and getters start here

/*********************************************************************
** Function: get_time
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Zoo::get_time() const{
	return current_time;
}

/*********************************************************************
** Function: set time
** Description: none
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_time(int new_time) {
	current_time = new_time;
}

/*********************************************************************
** Function: get money
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Zoo::get_money() const{
	return game_money;
}

/*********************************************************************
** Function: set money
** Description: none
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_money(float new_money) {
	game_money = new_money;
}

/*********************************************************************
** Function: get base food cost
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Zoo::get_base_food_cost() const {
	return base_food_cost;
}

/*********************************************************************
** Function: get tigers
** Description: returns number of tigers
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Zoo::get_tigers() const{
	return number_of_tigers;
}

/*********************************************************************
** Function: set tigers
** Description: set number of tigers
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_tigers(unsigned int new_tigers) {
	number_of_tigers = new_tigers;
}

/*********************************************************************
** Function: get bears
** Description: get number bears
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Zoo::get_bears() const {
	return number_of_bears;
}

/*********************************************************************
** Function: set bears
** Description: none
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_bears(unsigned int new_bears) {
	number_of_bears = new_bears;
}

/*********************************************************************
** Function: get slions
** Description: get number sea lions
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Zoo::get_slions() const{
	return number_of_slions;
}

/*********************************************************************
** Function: set_slions
** Description: set number slions
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_slions(unsigned int new_slions) {
	number_of_slions = new_slions;
}

/*********************************************************************
** Function: get current food cost
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Zoo::get_current_food_cost() const {
	return current_food_cost;
}

/*********************************************************************
** Function: set current food cost
** Description: none
** Parameters: new
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::set_current_food_cost(float new_food) {
	current_food_cost = new_food;
}

//setters and getters end here

//Other functions start 

/*********************************************************************
** Function: contains adult
** Description: checks if there are adults for each animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::contains_adult() {
	bear_contains_adult = false;
	slion_contains_adult = false;
	tiger_contains_adult = false;
	int counter1 = 0;
	for (int i = 0; i < number_of_bears; i++) {
		if (bear_list[i].get_age() >= 48) {
			counter1++;
		}
	}
	if (counter1 >= 2) {
		bear_contains_adult = true;
	}
	number_adults_bear = counter1;
	counter1 = 0;
	for (int i = 0; i < number_of_slions; i++) {
		if (slion_list[i].get_age() >= 48) {
			counter1++;
		}
	}
	if (counter1 >= 2) {
		slion_contains_adult = true;
	}
	number_adults_slion = counter1;
	counter1 = 0;
	for (int i = 0; i < number_of_tigers; i++) {
		if (tiger_list[i].get_age() >= 48) {
			counter1++;
		}
	}
	if (counter1 >= 2) {
		tiger_contains_adult = true;
	}
	number_adults_tiger = counter1;
}

/*********************************************************************
** Function: get random multiplier
** Description: gets a number between lo and hi (random)
** Parameters: hi and lo
** Pre-Conditions:  none
** Post-Conditions: none
*********************************************************************/
float Zoo::get_random_multiplier(float LO, float HI) {
	//srand(time(NULL));
	float r3 = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	return r3;
}

/*********************************************************************
** Function: get random
** Description: creates random number up to a max value
** Parameters: max
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Zoo::get_random(int max_value) {
	//srand(time(NULL));
	int output = (rand() % max_value) + 1;
	return output;
}

/*********************************************************************
** Function: get heal price
** Description: gets heal price for animal
** Parameters: type of animal and index
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Zoo::get_heal_price(int index_animal, int index_sick) {
	if (index_animal == 1) {//tiger
		if (tiger_list[index_sick].get_age() < 7) {
			cout << "\n\nA baby Tiger just got sick!\n\n";
			return tiger_list->get_cost();
		}
		cout << "\n\nA Tiger just got sick!\n\n";
		return (tiger_list->get_cost() / 2);
	}
	else if (index_animal == 2) {//bear
		if (bear_list[index_sick].get_age() < 7) {
			cout << "\n\nA baby Bear just got sick!\n\n";
			return bear_list->get_cost();
		}
		cout << "\n\nA Bear just got sick!\n\n";
		return (bear_list->get_cost() / 2);
	}
	else if (index_animal == 3) {//slion
		if (slion_list[index_sick].get_age() < 7) {
			return slion_list->get_age();
			cout << "\n\nA baby Sea Lion just got sick!\n\n";
		}
		cout << "\n\nA Sea Lion just got sick!\n\n";
		return (slion_list->get_cost() / 2);
	}
}

/*********************************************************************
** Function: heal animal
** Description: heals animal
** Parameters: index of animal and individual
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::heal_animal(int index_animal, int index_sick) {
	if (index_animal == 1) {
		tiger_list[index_sick].set_sick(false);
	}
	else if (index_animal == 2) {
		bear_list[index_sick].set_sick(false);
	}
	else if (index_animal == 3) {
		slion_list[index_sick].set_sick(false);
	}
}

/*********************************************************************
** Function: return selected
** Description: returns if an animal list contains two adults
** Parameters: number
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::return_selected(int number) {
	if (number == 1) {
		return tiger_contains_adult;
	}
	else if (number == 3) {
		return slion_contains_adult;
	}
	else if (number == 2) {
		return bear_contains_adult;
	}
}

/*********************************************************************
** Function: create baby
** Description: creates baby
** Parameters: type of animal
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::create_baby(int type) {
	int multiplier = 0;
	if (type == 1) {
		for (int i = number_of_tigers; i < (tiger_list->get_num_babies() + number_of_tigers); i++) {
			
		}
		cout << "\n\nThree Tiger babies Were Born!\n\n";
		number_of_tigers += tiger_list->get_num_babies();
	}
	else if (type == 3) {
		for (int i = number_of_slions; i < (slion_list->get_num_babies() + number_of_slions); i++) {

		}
		cout << "\n\nOne Sea Lion baby Was Born!\n\n";
		number_of_slions += slion_list->get_num_babies();
	}
	else if (type == 2) {
		for (int i = number_of_bears; i < (number_of_bears + bear_list->get_num_babies()); i++) {

		}
		cout << "\n\nTwo Bear babies Were Born!\n\n";
		number_of_bears += bear_list->get_num_babies();
	}
}

/*********************************************************************
** Function: birth
** Description: birth animal
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::birth() {
	int random = 0; 
	do { //check while in this loop
		random = get_random(3);
		//cout << "Choosing animal to give birth!" << endl;
	} while (!check_for_valid_random_animal(random) || !return_selected(random));
	create_baby(random);
}

/*********************************************************************
** Function: random_event
** Description: selects random event to happen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::random_event() {
	int random = get_random(4);
	if (random == 3 && !(number_adults_bear >= 2 || number_adults_slion >= 2 || number_adults_tiger >= 2)) {
		cout << "\n\nToday was a boring day... Nothing really happened\n\n";
	}
	if (random == 1) { //no event
		cout << "\n\nToday was a boring day... Nothing really happened\n\n";
		boom = false;
	}
	else if (random == 2) { //gets sick - babies cost double
		//cout << "Sick Happened" << endl;
		int index_sick, index_animal;
		make_sick(index_sick, index_animal);
		float heal_price = get_heal_price(index_animal, index_sick);
		if (game_money < heal_price) {
			cout << "You don't have money to heal this animal! It died!\n\n";
			kill_animal(index_animal, index_sick);
		}
		else {
			game_money = game_money - heal_price;
			cout << "You had enough money to heal this animal! It is now healed\n\n";
			heal_animal(index_animal, index_sick);
		}
	}
	else if (random == 3 && (number_adults_bear >= 2 || number_adults_slion >= 2 || number_adults_tiger >= 2)) { //gives birth
		cout << "A Birth has Happened!" << endl;
		birth();
	}
	else if (random == 4) { //zoo boom
		boom = true;
		cout << "A BOOM in attendance has occured!\n\n";
	}
}

/*********************************************************************
** Function: check for valid random animal
** Description: checks if animal is not there
** Parameters: random
** Pre-Conditions:  none
** Post-Conditions: none
*********************************************************************/
bool Zoo::check_for_valid_random_animal(int random) {
	if (random == 1 && number_of_tigers == 0) {
		return false;
	}
	else if (random == 3 && number_of_slions == 0) {
		return false;
	}
	else if (random == 2 && number_of_bears == 0) {
		return false;
	}
	else return true;
}

/*********************************************************************
** Function: make sick
** Description: makes animal sick
** Parameters: index of animal and individual
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::make_sick(int &index_sick, int &index_animal) {
	int random = 0;
	do {
		random = get_random(3);
	} while (!check_for_valid_random_animal(random));

	if (random == 1 && number_of_tigers > 0) { //Tiger
		//cout << "\n\nA tiger got Sick!\n\n";
		int random2 = get_random(number_of_tigers) - 1;
		tiger_list[random2].set_sick(true);
		index_sick = random2;
	}
	else if (random == 2 && number_of_bears > 0) { //Bear
		//cout << "\n\nA Bear just got sick!\n\n";
		int random2 = get_random(number_of_bears) - 1;
		bear_list[random2].set_sick(true);
		index_sick = random2;
	}
	else if (random == 3) { //Slion
		//cout << "\n\nA Sea Lion just got sick!\n\n";
		int random2 = get_random(number_of_slions) - 1;
		slion_list[random2].set_sick(true);
		index_sick = random2;
	}
	index_animal = random;
}

/*********************************************************************
** Function: get_revenue
** Description: gets revenue for thaat month
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::get_revenue() { //gets revenue for that month
	float month_revenue = 0;
	if (number_of_tigers > 0) {
		for (int i = 0; i < number_of_tigers; i++) {
			if (tiger_list[i].get_age() < 7) {
				month_revenue += 2400;
			}
			else  {
				month_revenue += 1200;
			}
		}
	}
	if (number_of_slions > 0) {
		for (int i = 0; i < number_of_slions; i++) {
			if (slion_list[i].get_age() < 7) {
				month_revenue += 280;
			}
			else {
				month_revenue += 140;
			}
			if (boom) { //in case of boom, this will add the random value to the month revenue
				float multiplier = get_random_multiplier(1, 2.6);
				month_revenue += (150 * multiplier);
			}
		}
	}
	if (number_of_bears > 0) {
		for (int i = 0; i < number_of_bears; i++) {
			if (bear_list[i].get_age() < 7) {
				month_revenue += 1000;
			}
			else {
				month_revenue += 500;
			}
		}
	}
	float temp = game_money;
	game_money += month_revenue;
	if ((game_money - temp) > 0)
		cout << "\n\nYou earned $" << game_money - temp << " this month!\n\n";
}

/*********************************************************************
** Function: print game
** Description: print function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_game() {
	cout << "Money: " << game_money << "\nBase Food Cost: " << base_food_cost << "\nCurrent Food Cost: " << current_food_cost << "\nNumber of Tigers: " << number_of_tigers << "\nNumber of Sea Lions: " << number_of_slions << "\nNumber of Black Bears: " << number_of_bears << endl;
	cout << "Current Month: " << current_time << endl;
}

/*********************************************************************
** Function: loop for int
** Description: gets valid int
** Parameters: message max min and input
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::loop_for_int(int& input, string message, int max, int min) {//loops for int, useful when dealing with choices

	bool trigger = 0;

	do { //loop that checks for valid input
		if (trigger) {
			cout << "****************************************\n* ERROR - Please Input a Valid Option. *\n****************************************\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;
		trigger = 1;
	} while (input < min || input > max);

}

/*********************************************************************
** Function: check valid buy
** Description: checks if user can buy animal
** Parameters: type of animal
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::check_valid_buy(int animal_index) {
	if (animal_index == 1 && bought_tigers == 1000)
		return false;
	else if (animal_index == 2 && bought_bears == 1000)
		return false;
	else if (animal_index == 3 && bought_slions == 1000)
		return false;
	else
		return true;
}

/*********************************************************************
** Function: create bought
** Description: creates animal you buy in array
** Parameters: type
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::create_bought(int index) { //adds to the array the just bought animal
	int choice;
	loop_for_int(choice, "How Many Animals do you want to buy? ", 2, 1);
	if (index == 1) { //tiger
		bought_tigers++;
		tiger_list[number_of_tigers].set_age(48);
		tiger_list[number_of_tigers].set_bought(true);
		if (choice == 2) {
			tiger_list[number_of_tigers + 1].set_age(48);
			tiger_list[number_of_tigers + 1].set_bought(true);
		}
		number_of_tigers = number_of_tigers + choice;
		game_money = game_money - (tiger_list->get_cost())*choice;
	}
	else if (index == 2) { //bear
		bought_bears++;
		bear_list[number_of_bears].set_age(48);
		bear_list[number_of_bears].set_bought(true);
		if (choice == 2) {
			bear_list[number_of_bears+1].set_age(48);
			bear_list[number_of_bears+1].set_bought(true);
		}
		number_of_bears = number_of_bears + choice;
		game_money = game_money - (bear_list->get_cost())*choice;
	}
	else if (index == 3) { //slion
		bought_slions++;
		slion_list[number_of_slions].set_age(48);
		slion_list[number_of_slions].set_bought(true);
		if (choice == 2) {
			bear_list[number_of_bears+1].set_age(48);
			bear_list[number_of_bears+1].set_bought(true);
		}
		number_of_slions = number_of_slions + choice;
		game_money = game_money - (slion_list->get_cost())*choice;
	}
}


//this function goes on play_zoo function
/*********************************************************************
** Function: buy animal
** Description: buy animal menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::buy_animal() {//if wants to buy animal, checks if right amount can be bought
	int animal_index = 0;

	again:loop_for_int(animal_index, "What Type of animal would you like to buy?\n\n (1) Tiger ($12000.00)\n\n (2) Bear ($5000.00)\n\n (3) Sea Lion ($700.00)\n\n", 3, 1);
	
	if (!check_valid_buy(animal_index)) {
		cout << "You already purchased the maximum amount of that type of animal! - Make another choice!\n\n";
		goto again;
	}
	else {
		create_bought(animal_index);
	}
}

/*********************************************************************
** Function: totao_food
** Description: gets total food cost for the month
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
float Zoo::total_food() {//calculates how much the feeding is for this month
	float total_food_cost = 0;
	if (number_of_bears > 0) {
		total_food_cost += (current_food_cost * bear_list->get_food_multiplier()) * number_of_bears;
	}
	if (number_of_slions > 0) {
		total_food_cost += (current_food_cost * slion_list->get_food_multiplier()) * number_of_slions;
	}
	if (number_of_tigers > 0) {
		total_food_cost += (current_food_cost * tiger_list->get_food_multiplier()) * number_of_tigers;
	}
	return total_food_cost;
}

/*********************************************************************
** Function: month expense
** Description: gets total month espense for the zoo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::month_expense() { //this function will take care of monthly expenses regarding animals
	float total_food_cost = total_food();
	cout << "Food Cost: " << total_food_cost << endl;
	game_money = game_money - total_food_cost;
	cout << "A month has passed" << endl;
	//use sick index to check for monay and type of animal so that you can say if it is dead or not.
}

/*********************************************************************
** Function: kill animal
** Description: kills animal
** Parameters: type of animal and index in array
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::kill_animal(int animal_type, int animal_index) { //kills certain animal type and takes money, in case of baby, takes double, or in case of bought takes that from the bought quantity.
	//animal types: 1 - Tiger, 2- Bear, 3- Slion
	int dummy = 0;
	if (animal_type == 1) { // kill tiger here
		if (tiger_list[animal_index].is_bought())
			bought_tigers--;
		number_of_tigers--;
		dummy = number_of_tigers;
	}
	else if (animal_type == 2) { //kill bear here
		if (bear_list[animal_index].is_bought())
			bought_bears--;
		number_of_bears--;
		dummy = number_of_bears;
	}
	else if (animal_type == 3) { //kill slion here
		if (slion_list[animal_index].is_bought())
			bought_slions--;
		number_of_slions--;
		dummy = number_of_slions;
	}
	for (int i = 0; i < dummy; i++) { //loop to shift animals back on array if animal dies
		if (i >= animal_index && animal_type == 1) {
			tiger_list[i] = tiger_list[i + 1];
		}
		else if (i >= animal_index && animal_type == 2) {
			bear_list[i] = bear_list[i + 1];
		}
		else if (i >= animal_index && animal_type == 3) {
			slion_list[i] = slion_list[i + 1];
		}
	}

}

/*********************************************************************
** Function: play zoo
** Description: plays zoo game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::play_zoo() {	
	do {
		//system("clear");
		int choice = 0;
		boom = false;
		contains_adult();
		get_revenue();
		current_food_cost = (base_food_cost * get_random_multiplier(0.8, 1.2));
		if (current_time > 0 && (number_of_bears > 0 || number_of_slions > 0 || number_of_tigers > 0)) {
			random_event();
		}
		print_game();
		base_food_cost = current_food_cost;
		loop_for_int(choice, "Action Menu:\n\n (1) Buy Animal\n (2) Pass the Month\n (3) Quit Game\n\n", 3, 1);

		if (choice == 1) {
			buy_animal();
		}
		else if (choice == 2) {
			cout << "\n\nYou Skipped the day\n\n";
		}
		else if (choice == 3) {
			break;
		}

		current_time++;
		month_expense();
	} while (game_money > 0);
	if (game_money <= 0) {
		cout << "\n\nYour Zoo ran out of money! - \n\n-- Game Over --\n\n";
		print_endgame();
	}
	else {
		cout << "\n\nYou left the game! We hope to see you back soon!\n\n";
		print_endgame();
	}
}

/*********************************************************************
** Function: print endgame
** Description: prints end game scores
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_endgame() {
	if (game_money > 0) {
		cout << "Endgame Stats:\n\n";
		cout << "Money: " << game_money << "\nNumber of Tigers: " << number_of_tigers << "\nNumber of Sea Lions: " << number_of_slions << "\nNumber of Black Bears: " << number_of_bears << endl;
	}
	else {
		cout << "Endgame Bankrupcy Stats:\n\n";
		cout << "Money: 0.00"<< "\nNumber of Tigers: " << number_of_tigers << "\nNumber of Sea Lions: " << number_of_slions << "\nNumber of Black Bears: " << number_of_bears << endl;
	}
}