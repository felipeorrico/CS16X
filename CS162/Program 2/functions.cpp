/******************************************************
** Program: functions.cpp
** Date: 10/26/2019
** Description:  functions implementation file
******************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "course.h"
#include "functions.h"
#include "university.h"

using namespace std;

/*********************************************************************
** Function: get_number_of_students
** Description: gets number of students in enrollment file
** Parameters: -
** Pre-Conditions: expects valid file
** Post-Conditions: returns int
*********************************************************************/ 
int get_number_of_students(){
	ifstream file ("enrollment.txt");
	int number_of_students = count_lines(file);
	file.close();
	return number_of_students;
}

/*********************************************************************
** Function: check_for_repetition
** Description: checks for repetition is string
** Parameters: array of strings and size
** Pre-Conditions: expected int and array
** Post-Conditions: expected update array
*********************************************************************/ 
void check_for_repetition (string *arr, int number){
	for (int i = 0; i < number; i++){
		for (int j = i+1; j < number; j++){
			if (arr[i] == arr[j]){
				arr[j] = "";
			}
		}
	}
}

/*********************************************************************
** Function: reset_file
** Description: moves the cursor to the beginning of the file
** Parameters:  filestream
** Pre-Conditions: valid filestream
** Post-Conditions: update filestream
*********************************************************************/ 
void reset_file (ifstream &file){
	file.clear();
	file.seekg (0, ios::beg);
}

/*********************************************************************
** Function: waste_line
** Description: wastes a line in a file
** Parameters: filestream
** Pre-Conditions: expects valid filestream
** Post-Conditions: updates filestream
*********************************************************************/ 
void waste_line(ifstream &file){
	string dummyLine;
	for (int i = 0; i < 2; i++){
		getline(file, dummyLine);
		dummyLine = "";
	}
}

/*********************************************************************
** Function: count_lines
** Description: coutn lines in a file
** Parameters: filestream
** Pre-Conditions: valid filestream
** Post-Conditions: return int
*********************************************************************/ 
int count_lines(ifstream &file){
	int counter = 0;
	string line;
	while (getline(file, line))
        ++counter;
	//counter = counter+1;
	return counter;
}

/*********************************************************************
** Function: get_info_from_file
** Description: get teacher info from file
** Parameters: ints and teacher struct
** Pre-Conditions: valid input
** Post-Conditions: returns code for error
*********************************************************************/ 
int get_info_from_file(int &user_location,  teacher *teacher_list, int number_of_teachers){

	int login, id;
	
	string pw;
	
	cout << "Teachers Loaded: " << number_of_teachers << "\n\n";
	
	
	login = get_login_credentials(id, pw, teacher_list, number_of_teachers, user_location);
	
	if (login == 1){
		return 4;
	}
		
	return 0;
}

/*********************************************************************
** Function: check_id
** Description: checks if ID has invalid 
** Parameters: string, ints, boolean
** Pre-Conditions: valid input
** Post-Conditions: update id
*********************************************************************/ 
bool check_id (string id_input, int &id, bool &trigger, int &counter){
	for (int i = 0; i < id_input.length(); i++){
		if (string::npos != id_input.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*,.;:?+-=_ ")){
			trigger = true;
			--counter;
			return true;
			break;
		}
	}
	id = stoi(id_input);
	return false;
}

/*********************************************************************
** Function: login_separation
** Description: separate login function because of size
** Parameters: boll, int string
** Pre-Conditions: valid input	
** Post-Conditions: run
*********************************************************************/ 
void login_separation (bool &trigger, int &counter, string &id_input){
	if (trigger){
			trigger = false;
			cout << "\n\033[22;31mError, Invalid ID or PASSWORD!\033[01;37m\n\nPlease input valid ID or PASSWORD\n\n";
			cin.clear();
			cin.ignore(10, '\n');
			counter++;
		}
		cout << "Login Attempts: "<< counter <<endl;
		cout << "ID: ";
		cin >> id_input;
}

/*********************************************************************
** Function: get_login_credentials
** Description: drives login functionality
** Parameters: ints, strings, teacher
** Pre-Conditions: valid input
** Post-Conditions: int
*********************************************************************/ 
int get_login_credentials(int &id, string &pw, teacher *teacher_list, int number_of_teachers, int &user_location){
	bool trigger = false, quiting = false;
	int counter = 0;
	string id_input;
	do{
		start: login_separation (trigger, counter, id_input);
		
		bool restart = check_id(id_input, id, trigger, counter);
		
		if (restart){goto start;}
		
		cout << "Password: ";
		
		cin >> pw;
		
		for (int i = 0; i < number_of_teachers; i++){
			if (id == teacher_list[i].id && pw == teacher_list[i].password){
				user_location = i;
				return 0;
			}
			else trigger = true;
		}
		if (counter > 0){ //this should ask if you want to quit the program if login attempts are greater than 0
			int quit_int;
			loop_for_int(quit_int, "\nYour Login was Invalid more than one time!\nWould you like to QUIT login?\n(1) Quit\n(2) Continue Login\n",2,1);
			if(quit_int == 1){
				return 1;
			}
			if(quit_int==2) {
				cin.clear();
				cin.ignore(10, '\n');
				trigger = false;
				goto start;
			}
		}
	} while (trigger == true /*&& counter < 2*/&& quiting == false);
	
	if (quiting == true){
		return 1;
	} else 
		return 0;
}

/*********************************************************************
** Function: loop_for_int
** Description: Is a loop that checks for valid input and updates the variable
** Parameters: int input, string message, int min and max
** Pre-Conditions: expected int as input 
** Post-Conditions: expected update of int
*********************************************************************/ 
void loop_for_int (int &input, string message, int max, int min){//loops for int, useful when dealing with choices
	
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
	} while ( input < min || input > max);
	
}

