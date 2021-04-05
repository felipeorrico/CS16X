/*****************************************************************
** Program: Hunt The Wumpus
** File: Source.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/21/2019
** Description: Hunt the wumpus game
** Input: WASD for movement and (space) for firing arrow
** Output: Gameplay grid and actions based on movement and loction
******************************************************************/

#include <iostream>
#include <vector>

#include "Game.h"

#include <exception>
#include <stdexcept>
#include <string>
#include <cstring>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int apc, char** apd) {
	srand(time(NULL));
	try {
		//cout << "APC: " << apc << " apd 1: " << apd[1] << " apd 2: " << apd[2] << endl;
		if (apc != 3) {
			throw invalid_argument("Too many/little arguments in command!");
		}
		else if (get_string(apd[2]) != "true" && get_string(apd[2]) != "false"){
			throw invalid_argument("Invalid Game Mode!");
		}
		else if (check_string(get_string(apd[1])) || stoi(get_string(apd[1])) < 4) {
			throw invalid_argument("Invalid Value for grid size!");
		}
		Game G(stoi(get_string(apd[1])), get_string(apd[2]));
		G.welcome();
		G.run_game();
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	return 0;
}