/*****************************************************************
** Program: Hunt The Wumpus
** File: Game.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Game class definition
******************************************************************/

#ifndef Game_h 

#define Game_h

#include "Room.h"
#include <iostream>
#include <vector>
#include "Bats.h"
#include "Wumpus.h"
#include "Gold.h"
#include "Pits.h"
#include "Rope.h"

using namespace std;

class Game {
	private:
		vector <vector<Room>> cave;
		bool game_mode;
		int arrows;
		int current_y;
		int current_x;
		int past_x;
		int past_y;
		int initial_x;
		int initial_y;
		int cave_size;
		bool trigger;
		bool alive = true;
		bool in_cave = true;
		bool has_gold;
		bool killed;
		Wumpus w1;
		Bats b1;
		Pits p1;
		Gold g1;
		Rope r1;

	public:
		Game();
		Game(int size, string mode);
		void welcome();
		void lookaround();
		bool get_trigger();
		void set_current_y(int);
		void set_current_x(int);
		void set_past_x(int);
		void set_past_y(int);
		void set_cave_size(int);
		void print_grid();
		void update_location(char &);
		void get_valid_coords(int& x, int& y);
		void generate_events();
		void run_game();
		void run_game2(char&);
		void set_mode_string(string);
		void set_mode(bool);
		bool get_mode();
		void get_room_event();
		void wumpus_jump();
		void update_array();
		void update_size();
};

bool check_string(string input);
string get_string(char* a);
int get_random(int max_value);

//create function that generates random locations for the events and from that initializes the cave vector

#endif

