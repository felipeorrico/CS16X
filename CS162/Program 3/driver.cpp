/******************************************************
** Program: Zoo Tycoon
** File Name: driver.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 11/03/2019
** Description: Game of Zoo Tycoon
** Input: Game inputs
** Output: game prints to console
******************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Zoo.h"
#include "Tiger.h"
#include "Bear.h"
#include "Animal.h"
#include "Sea_lion.h"

using namespace std;

int main() {

	srand(time(NULL));
	Zoo Z;
	cout << "Welcome to Zoo Tycoon!\n\n";
	Z.play_zoo();

	return 0;
}
