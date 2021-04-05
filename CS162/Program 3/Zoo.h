/*********************************************************************
** Program Filename: Zoo.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Definition of Zoo Class
*********************************************************************/
#ifndef zoo_h
#define zoo_h

#include "Tiger.h"
#include "Sea_lion.h"
#include "Bear.h"
#include <iostream>
#include <string>
#include "Tiger.h"
#include "Bear.h"
#include "Sea_lion.h"

using namespace std;

class Zoo{
	private:
		int current_time;
		int number_adults_tiger;
		int number_adults_slion;
		int number_adults_bear;
		float game_money;
		float base_food_cost;
		float current_food_cost;
		unsigned int number_of_tigers;
		unsigned int number_of_bears;
		unsigned int number_of_slions;
		unsigned int bought_tigers;
		unsigned int bought_bears;
		unsigned int bought_slions;
		bool boom;
		bool tiger_contains_adult;
		bool slion_contains_adult;
		bool bear_contains_adult;
		Tiger* tiger_list;
		Slion* slion_list;
		Bear* bear_list;
	public:
		~Zoo();
		Zoo();
		int get_time() const;
		void set_time(int);
		float get_money() const;
		void set_money(float);
		float get_base_food_cost() const;
		unsigned int get_tigers() const;
		void set_tigers(unsigned int);
		unsigned int get_bears() const;
		void set_bears(unsigned int);
		unsigned int get_slions() const;
		void set_slions(unsigned int);
		float get_current_food_cost() const;
		void set_current_food_cost(float);
		void play_zoo();
		void print_endgame();
		void contains_adult();
		float get_random_multiplier(float LO, float HI);
		int get_random(int);
		float get_heal_price(int index_animal, int index_sick);
		void heal_animal(int index_animal, int index_sick);
		bool return_selected(int number);
		void create_baby(int type);
		void birth();
		void random_event();
		bool check_for_valid_random_animal(int random);
		void make_sick(int& index_sick, int& index_animal);
		void get_revenue();
		void print_game();
		void loop_for_int(int& input, string message, int max, int min);
		bool check_valid_buy(int animal_index);
		void create_bought(int index);
		void buy_animal();
		float total_food();
		void month_expense();
		void kill_animal(int animal_type, int animal_index);
};

#endif