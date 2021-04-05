/******************************************************
** File: List_Program.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
******************************************************/

#include "List_Program.h"
#include "Linked_List.h"
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

/*********************************************************************
** Function: run
** Description: runs the program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void List_Program::run() { //program runs here, you can edit this function as if it was the main function
	string again = "n";
	do {
		string choice = "n";
		Linked_List L1;
		do {
			choice = "n";
			int temp = 0;
			loop_for_int(temp, "\nPlease Enter a Number: ", 99999999, -99999999); //gets intergers
			L1.push_back(temp);
			temp = 0;
			loop_for_string2(choice, "\nWould you like to add another number (y/n) (case sentitive): "); //gets y or n inputs
		} while (choice == "y");
		string ad;
		loop_for_string(ad, "\nSort ascending or descending (a/d) (case sensitive): ");//gets a or d inputs
		cout << "Your list Before Sorting:\n";
		L1.print();
		sort(L1, ad);
		cout << "Your list:\n";
		L1.print();
		cout << "\nYou have " << L1.countPrime() << " Prime Number(s) in your list.\n";
		loop_for_string2(again, "\nDo you want to do this again (y or n)? ");
	} while (again == "y" || again != "n"); //loops while you want to list your numbers =)
}


/*********************************************************************
** Function: sort
** Description: calls the sorting function depending on the choice of sorting
** Parameters: Accepts a Linked list and a string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void sort(Linked_List& l1, string ad) {
	if (ad == "a") {
		l1.sort_ascending();
	}
	else if (ad == "d") {
		l1.sort_descending();
	}
}

/*********************************************************************
** Function: loop_for_string
** Description: gets and checkd inputs for ascending or descending
** Parameters: input and message
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void loop_for_string(string& input, string message) {
	bool trigger = false;
	do {
		if (trigger) {
			trigger = false;
			cout << "\nInvalid option!\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;

	} while (input != "a" && input != "d");
}

/*********************************************************************
** Function: loop_for_string2
** Description: same as loop_for_string but for y or n
** Parameters: input and message
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void loop_for_string2(string& input, string message) {
	bool trigger = false;
	do {
		if (trigger) {
			trigger = false;
			cout << "\nInvalid option!\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;

	} while (input != "y" && input != "n");
}

/*********************************************************************
** Function: loop_for_int
** Description: gets input for int (this case used for the numbers in the list)
** Parameters: input, message, maximum vaue, and minimum value
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void loop_for_int(int& input, string message, int max, int min) {//loops for int, useful when dealing with choices

	bool trigger = 0;

	do { //loop that checks for valid input
		if (trigger) {
			cout << "****************************************\n* ERROR - Please Input a Valid Option. *\n****************************************\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;
		trigger = 1;
	} while (input < min || input > max|| cin.fail()); //checks if the value is within valid numbers and if the input was a valid int.

}