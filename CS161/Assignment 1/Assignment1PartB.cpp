/******************************************************************************
 * Program: Assignment1PartB.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Print the size of primitive data types
 * Input: none
 * Output: Size of primitive data types.
 ******************************************************************************/

#include <iostream> //Input/Output functions

using namespace std; //States that all the functions below will use std before them

int main () { //Main functions with print statements
	
	cout << "Size of Integer is: " << sizeof(int) << endl; //displays size of integer
	cout << "Size of Unsigned Integer is: " << sizeof(unsigned int) << endl; //displays size of unsigned int
	cout << "Size of Character is: " << sizeof(char) << endl; //displays size of character
	cout << "Size of Unsigned Character is: " << sizeof(unsigned char) << endl; //displays size of unsigned char
	cout << "Size of Boolean is: " << sizeof(bool) << endl; //displays size of boolean
	cout << "Size of Floating Point is: " << sizeof(float) << endl; //displays size of floating point
	cout << "Size of Double Floating Point is: " << sizeof(double) << endl; //displays size of double floating point
	cout << "Size of Wide character is: " << sizeof(wchar_t) << endl; //displays size of wide character
	cout << "Size of Short Integer is: " << sizeof(short int) << endl; //displays size of short int
	cout << "Size of Unsigned Short Integer is: " << sizeof(unsigned short int) << endl; //displays size of unsigned short integer
	cout << "Size of Long Integer is: " << sizeof(long int) << endl; //displays size of long int
	cout << "Size of Unsigned Long Integer is: " << sizeof(unsigned long int) << endl; //displays size of unsigned long int
	cout << "Size of Long Long Integer is: " << sizeof(long long int) << endl; //displays size of long long int
	cout << "Size of Unsigned Long Long Integer is: " << sizeof(unsigned long long int) << endl; //displays size of unsigned long long int
	
	return 0;
}