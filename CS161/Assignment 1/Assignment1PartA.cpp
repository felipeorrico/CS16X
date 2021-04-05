/******************************************************************************
 * Program: Assignment1PartA.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Print the size of data types using macros
 * Input: none
 * Output: size of data types
******************************************************************************/

#include <climits>  // imports macro constants.
#include <iostream> // print on screen macros.

using namespace std; //states that all the functions below will use std before them

int main () { //main function of the program
	
	//Short int
	cout << "Minimum value for signed short int: " << SHRT_MIN << endl;
	cout << "Maximum value for signed short int: " << SHRT_MAX << endl;
	//Short unsigned int
	cout << "Maximum value for unsigned short int: " << USHRT_MAX << endl;
	//Signed int
    cout << "Minimum value for signed int: " << INT_MIN << endl;
    cout << "Maximum value for signed int: " << INT_MAX << endl;
	//Unsigned int
	cout << "Maximum value for unsigned int: " << UINT_MAX << endl;
	//Long int
	cout << "Minimum value for signed long int: " << LONG_MIN << endl;
	cout << "Maximum value for signed long int: " << LONG_MAX << endl;
	//Long unsigned int
	cout << "Maximum value for long unsigned int: " << ULONG_MAX << endl;
	
	return 0;
}	