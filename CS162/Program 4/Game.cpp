/*****************************************************************
** Program: Hunt The Wumpus
** File: Game.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Game class implementation
******************************************************************/

#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <termios.h>

/*********************************************************************
** Function: Game
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Game::Game() {
	cave_size = 4;
	current_x = 0;
	current_y = 0;
	arrows = 3;
	game_mode = false;
	past_x = 0;
	past_y = 0;
	cave.resize(cave_size);
	for (int i = 0; i < cave_size; i++) {
		cave.at(i).resize(cave_size);
	}
	//for (int i = 0; i < cave_size; i++) { //to initialize the rooms
	//	for (int j = 0; j < cave_size; j++)
	//		cave.at(i).at(j) = " "; //change this to room name?
	//}
}

/*********************************************************************
** Function: lookaround
** Description: checks adjacent rooms for percept
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::lookaround() {
	Event* e1; 

	if (current_y + 1 < cave_size) {
		e1 = cave.at((current_y + 1)).at(current_x).get_pointer();
		if (e1 != nullptr) {
			e1->percept();
		}
	}
	e1 = nullptr;
	if (current_y - 1 >= 0) {
		e1 = cave.at((current_y - 1)).at(current_x).get_pointer();
		if (e1 != nullptr) {
			e1->percept();
		}
	}
	e1 = nullptr;
	if (current_x + 1 < cave_size) {
		e1 = cave.at(current_y).at((current_x + 1)).get_pointer();
		if (e1 != nullptr) {
			e1->percept();
		}
	}
	e1 = nullptr;
	if (current_x - 1 >= 0) {
		e1 = cave.at(current_y).at((current_x- 1)).get_pointer();
		if (e1 != nullptr) {
			e1->percept();
		}
	}
	e1 = nullptr;
}

/*********************************************************************
** Function: gat_random
** Description: gets random value between 1 and desired
** Parameters: max value
** Pre-Conditions: none
** Post-Conditions: returns random number between 1 and max
*********************************************************************/
int get_random(int max_value) {
	int output = (rand() % max_value) + 1;
	return output;
}

/*********************************************************************
** Function: Game
** Description: constructor
** Parameters: size of the grid and mode (cheat or not)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Game::Game(int size, string mode)
{
	set_cave_size(size);
	set_mode_string(mode);
	arrows = 3;
	current_x = get_random(size) - 1;
	current_y = get_random(size) - 1;
	past_x = 0;
	past_y = 0;
	has_gold = false;
	killed = false;
	in_cave = true;
	initial_x = current_x;
	initial_y = current_y;
}

/*********************************************************************
** Function: get_trigger
** Description: returns trigger
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Game::get_trigger()
{
	return trigger;
}

/*********************************************************************
** Function: set_current_y
** Description: sets current y
** Parameters: y
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_current_y(int y)
{
	current_y = y;
}

/*********************************************************************
** Function: set_current_x
** Description: sets current x
** Parameters: x 
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_current_x(int x)
{
	current_x = x;
}

/*********************************************************************
** Function: set_past_x
** Description: sets past x
** Parameters: x
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_past_x(int x)
{
	past_x = x;
}

/*********************************************************************
** Function: set_past_y
** Description: sets past y
** Parameters: y
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_past_y(int y)
{
	past_y = y;
}

/*********************************************************************
** Function: set_cave_size
** Description: sets the sizeXsize of the cave
** Parameters: size
** Pre-Conditions:  none
** Post-Conditions: none
*********************************************************************/
void Game::set_cave_size(int size)
{
	cave_size = size;
	update_size();
}

/*********************************************************************
** Function: print_grid
** Description: prints the cave grid
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::print_grid() {
	cout << "\n--------------------------------------------------------------------------------------\n";
	cout << "Gold: " << has_gold << "\nKilled Wumpus: " << killed << "\nArrows: "<< arrows <<endl;
	for (int rows = 0; rows < cave_size; rows++) {
		for (int i = 0; i < cave_size; i++) {
			cout << "+---";
		}
		cout << "+" << endl;
		for (int x = 0; x < 3; x++) { //3 high
			for (int y = 0; y < cave_size; y++) { //cols
				if (x == 1 /*&& cave.at(rows).at(y).get_symbol() != " "*/) { //added cheat mode and functions that print the room name
					if (current_x == y && current_y == rows/*cave.at(rows).at(y).get_symbol() == "*"*/) {
						cout << "| * ";
					}
					else if (cave.at(rows).at(y).get_pointer() != nullptr && game_mode == true) {
						cout << "| " << cave.at(rows).at(y).get_symbol() << " ";
					}
					else {
						cout << "|   ";
					}
				}
				else {
					cout << "|   ";
				}
			}
			cout << "|" << endl;
		}
	}
	for (int i = 0; i < cave_size; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
}

/*********************************************************************
** Function: update_location
** Description: using the WASD input changes location of player
** Parameters: &e
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::update_location(char &e) {
	if (e == 119) { //up boundary at y = 0
		if (current_y == 0) { //upper boundary here
			goto out;
		}
		//cout << "UP\n";
		past_y = current_y;
		current_y--;
	}
	if (e == 115) {//down boundary at y = -2
		if (current_y == cave_size-1) {//lower boundary here
			goto out;
		}
		//cout << "DOWN\n";
		past_y = current_y;
		current_y++;
	}
	if (e == 100) { //right
		if (current_x == cave_size-1) { //right boundary here
			goto out;
		}
		//cout << "RIGHT\n";
		past_x = current_x;
		current_x++;
	}
	if (e == 97) { //left
		if (current_x == 0) { //left boundary here
			goto out;
		}
		//cout << "LEFT\n";
		past_x = current_x;
		current_x--;
	}
out:;
}

/*********************************************************************
** Function: get_valid_coords
** Description: gets you random valid random coords
** Parameters: x, y
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::get_valid_coords(int& x, int& y) {
	begin:x = get_random(cave_size) - 1;
	y = get_random(cave_size) - 1;
	if (cave.at(y).at(x).get_event_type() != 0 || cave.at(y).at(x).get_pointer() != nullptr) {
		goto begin;
	}
}

/*********************************************************************
** Function: generate_events
** Description: generate events in grid for gameplay
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::generate_events() {
	cave.at(initial_y).at(initial_x).set_event_type(5);
	cave.at(initial_y).at(initial_x).set_event(w1, b1, p1, g1, r1);
	for (int i = 0; i < 6; i++) {
		int x, y;
		get_valid_coords(x, y);
		if (i == 0) { //wumpus generation
			//set_symbol, set_event, 
			//cave.at(y).at(x).set_symbol("W");
			cave.at(y).at(x).set_event_type(1);
			cave.at(y).at(x).set_event(w1, b1, p1, g1, r1);
		}
		else if (i == 1) { //gold generation
			//cave.at(y).at(x).set_symbol("G");
			cave.at(y).at(x).set_event_type(3);
			cave.at(y).at(x).set_event(w1, b1, p1, g1, r1);
		}
		else if (i > 1 && i <= 3) { //pits generation
			//cave.at(y).at(x).set_symbol("P");
			cave.at(y).at(x).set_event_type(2);
			cave.at(y).at(x).set_event(w1, b1, p1, g1, r1);
		}
		else if (i > 3 && i <= 5) { //bats generation
			//cave.at(y).at(x).set_symbol("B");
			cave.at(y).at(x).set_event_type(4);
			cave.at(y).at(x).set_event(w1, b1, p1, g1, r1);
		}
	}
}

/*********************************************************************
** Function: welcome()
** Description: displeys welcome message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::welcome() {
	cout << "Welcome to 'Hunt the Wumpus'! Use W,A,S,D to move around the cave!\n If you want to shoot an arrow, press space and then W,A,S,D!\nHave a good time!\n";
	cout << "You chose a cave with " << cave_size << " by "<< cave_size << " Rooms! (" << cave_size*cave_size << " rooms)"<<  endl;
}

/*********************************************************************
** Function: run_game
** Description: runs game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::run_game() //function to run the game
{
	//black magic here
	struct termios t;
	tcgetattr(0, &t);
	t.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &t);
	generate_events();
	trigger = false;
	char e;
	do {
		print_grid();
		run_game2(e); //gets input
		get_room_event();
		if (!killed && trigger) wumpus_jump();
		if (alive && in_cave) lookaround();
		//check for trigger with the function of the wumpus < fire arrow or not
		trigger = false;
	} while (alive && in_cave);
}

/*********************************************************************
** Function: run_game2
** Description: runs the WASD(space) input register
** Parameters: &e
** Pre-Conditions:  none
** Post-Conditions: none
*********************************************************************/
void Game::run_game2(char &e) {
	again:e = '\0';
	e = getchar();
	if (e == ' ' && trigger == true) {
		cout << "\nYou already chose to fire an arrow! Please choose where to move now!\n";
		goto again;
	}
	//check if movement is valid here! if it is not goto again
	if (e != ' ') { //if arrow not fired
		update_location(e);
	}
	else if (e == ' ' && trigger == false) { //if arrow fired
		if (arrows == 0) {
			cout << "\nYou don't have any arrows left!\n";
			goto again;
		}
		cout << "\nArrow will be Fired\n";
		cout << "Now press W,A,S,D to chose the direction you will move!\n";
		trigger = true;
		arrows--;
		goto again;
	}
	else goto again;
}

/*********************************************************************
** Function:set_mode
** Description: sets game mode
** Parameters: mode
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_mode(bool new_mode) {
	game_mode = new_mode;
}

/*********************************************************************
** Function: get_mode
** Description: gets game mode
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Game::get_mode() {
	return game_mode;
}

/*********************************************************************
** Function: get_room_event
** Description: checks the room you are in and performs event accordingly
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::get_room_event()
{
	//if the room has an event, it will play here
	cout << "\n--------------------------------------------------------------------------------------\n";
	if (cave.at(current_y).at(current_x).get_event_type() != 0 && cave.at(current_y).at(current_x).get_pointer() != nullptr ) {
		Event* p = cave.at(current_y).at(current_x).get_pointer();
		bool new_trig = false;
		if (cave.at(current_y).at(current_x).get_event_type() == 4) new_trig = true;
		int localx = current_x, localy = current_y;
		p->encounter(trigger, alive, killed, current_x, current_y, has_gold, cave_size, in_cave); //bat encounter not registering other rooms entered
		if ((cave.at(current_y).at(current_x).get_event_type() == 3 || cave.at(current_y).at(current_x).get_event_type() == 1) && new_trig == false) {
			cave.at(current_y).at(current_x).set_event_type(0);
			cave.at(current_y).at(current_x).set_symbol(" ");
			cave.at(current_y).at(current_x).set_to_null();
			goto end;
		}
		if (cave.at(current_y).at(current_x).get_event_type() == 5) {
			goto end;
		}
		if (cave.at(current_y).at(current_x).get_event_type() != 0 && cave.at(current_y).at(current_x).get_pointer() != nullptr && cave.at(localy).at(localx).get_event_type() == 4) {
			get_room_event();
		}
		end:;
	}
}

/*********************************************************************
** Function: wumpus_jump
** Description: when you miss an arrow there is 75% chance wumpus will wake up and change places
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: changes where the wumpus is
*********************************************************************/
void Game::wumpus_jump() {
	int chance = get_random(4);
	if (chance < 4) {
		cout << "\nYou missed an arrow! The Wumpus woke up and changed rooms!\n";
		bool done = false;
		int new_x = 0, new_y = 0;
		for (int y = 0; y < cave_size; y++) {
			for (int x = 0; x < cave_size; x++) {
				if (cave.at(y).at(x).get_pointer() != nullptr && cave.at(y).at(x).get_event_type() == 1) {
					get_valid_coords(new_x, new_y);
					cave.at(y).at(x).set_to_null();
					cave.at(y).at(x).set_symbol(" ");
					cave.at(y).at(x).set_event_type(0);
					cave.at(new_y).at(new_x).set_event_type(1);
					cave.at(new_y).at(new_x).set_event(w1, b1, p1, g1, r1);
					done = true;
				}
			}
			if (done) break;
		}
	}
}

/*********************************************************************
** Function: update_Array
** Description: changes player position in array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::update_array()
{
	cave.at(past_y).at(past_x).set_symbol(" ");
	cave.at(current_y).at(current_x).set_symbol("*");
}

/*********************************************************************
** Function: update_size
** Description: resizes the cave to desired size
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::update_size()
{
	cave.resize(cave_size);
	for (int i = 0; i < cave_size; i++) {
		cave.at(i).resize(cave_size);
	}
}

/*********************************************************************
** Function:set_mode_string
** Description: sets the game mode based on the string you input
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::set_mode_string(string mode) {
	if (mode == "true")
		game_mode = true;
	else if (mode == "false")
		game_mode = false;
}


//other functions not related to class GAME

/*********************************************************************
** Function: check_string
** Description: checks if the string has any invalid chars
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool check_string(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (string::npos != input.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*,.;:?+-=_ ")) {
			return true;
			break;
		}
	}
	return false;
}

/*********************************************************************
** Function: get_string
** Description: gets the string form a char pointer
** Parameters: char pointer
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string get_string(char* a) {
	string s(a);
	return s;
}
