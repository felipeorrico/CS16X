/*********************************************************************
** Program Filename: Animal.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Definition of Animal Class
*********************************************************************/

#ifndef animal_h
#define animal_h

using namespace std;

class Animal{
	private:
		int age;
		float cost;
		float food_multiplier;
		int num_babies;
		bool sick;
		bool bought;

	public:
		Animal();
		void set_age(int);
		int get_age() const;
		void set_cost(float);
		float get_cost() const;
		int get_num_babies() const;
		void set_num_babies(int);
		bool is_sick() const;
		void set_sick(bool);
		void set_food_multiplier(float);
		float get_food_multiplier();
		bool is_bought();
		void set_bought(bool);
		~Animal();
};

#endif