/******************************************************
** Program: linked_list.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
** Description: This program implements a linked list class
** Input: numbers and choice for linked list
** Output: sorted list and number of prime numbers in list
******************************************************/

#include "Linked_List.h" //this inclusion is not necessary, but it is here in case the TA wants to test some of the other functions
#include "Node.h" //this inclusion is not necessary, but it is here in case the TA wants to test some of the other functions
#include "List_Program.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	
	List_Program Lp1; //this class is designed to basically put together all the functions required to run this program 
					  //(this class is not 100% necessary, it was just a design choice)
	Lp1.run(); //run program, this can be modified as if it was the main function.

	return 0;
}