/******************************************************************************
 * Program: Assignment1PartC.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Print a calculation for a^b using pow and inputs a and b
 * Input: a and b
 * Output: The answer to a^b
 ******************************************************************************/

#include <iostream> //Input/Output functions
#include <math.h> //for math functions

using namespace std; //States that all the functions below will use std before them

int main () { //main function of the program. Receives inputs and assign them to respective int and outputs answer.
	
	int a; //defines int a
	int b; // defines int b
	
	cout << "Welcome! This program will print the answer to a^b!" << endl; //prints welcome message

	cout << "Please Enter Integer 'a'" << endl; //prints message requesting input for a
	cin >> a; //receives input and assigns it to int a
	
	cout << "Please Enter Integer 'b'" << endl; //prints message requesting input for b
	cin >> b; //receives input and assigns it to int b
	
	cout << a << "^" << b << " is " << pow(a, b) << endl; //Prints out the answer for a^b
	
	
	return 0;
}