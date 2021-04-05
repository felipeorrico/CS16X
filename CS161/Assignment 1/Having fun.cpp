/******************************************************************************
 * Program: Assignment1PartC.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Print a calculation for a^b using pow if 0=<a=<10 and 0=<b=<10
 * Input: a, b
 * Output: The answer to a^b
 ******************************************************************************/

#include <iostream> //Input/Output functions
#include <math.h> //for math functions

using namespace std; //States that all the functions below will use std before them

int main () {
	
	double a;
	double b;
	
	cout << "Welcome! This program will print the answer to a^b!" << endl;
	cout << "Please input numbers between 0 and 10" << endl;
	
	bool trigger = 0; //boolean that defines trigger to be 0
	
	do {
		if (trigger) { //checks if bool trigger is = 0
			cout << "Please input a valid integer" << endl;
		}
		cout << "Please Enter Integer 'a'" << endl;
		cin >> a;
		trigger = 1; 
	} 
	while (a<0 || a>10);
	
	trigger = 0;
	
	do {
		if (trigger) {
			cout << "Please input a valid integer" << endl;
		}
		cout << "Please Enter Integer 'b'" << endl;
		cin >> b;
		trigger = 1; 
	} 
	while (b<0 || b>10);	

	cout << a << "^" << b << " is " << pow(a, b) << endl;
	
	return 0;
}