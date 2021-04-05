/******************************************************
** Program: prog.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 10/26/2019
** Description: driver file for this program 
** Input: -
** Output: -
******************************************************/

#include "course.h"
#include "functions.h"
#include "university.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


 // TODO:
	//when on edit course, print with student names?
	// Update enrollment file (after include and remove from course)
	// Student search and register for a course (also update enrollment file here);
	//for student just append to bottom the enrollment file

/*********************************************************************
** Function: main
** Description: main function
*********************************************************************/ 
int main(){
	int loop = 0;
	string restart = "N";
	
	do{
		system("clear");
		do{
			University U;
			int number_of_teachers = U.get_teacher_number();
			
			//login starts here
			int choice = 0, student_id = 0, dummy_counter = 0;
			cout << "Welcome to Scheduler! - Please Choose a type of Login\n\n - Every search Input is Case sensitive!\n\nUniversity Loaded: " << U.get_name() << "\n\nTerm: " << U.get_term() << "\n\n";
			loop_for_int(choice, "\n (1) Login as Teacher\n (2) Login as Student\n\nChoice: ", 2,1);
			
			if (choice == 1){ //teacher login
				teacher *teacher_list = U.get_teachers();
				int run, teacher_location;
				run = get_info_from_file(teacher_location, teacher_list, number_of_teachers);
				system("clear");
				if (run == 4){ //change this to login quit
					cout << "Teacher Login Quit! - Restart the program\n";
					return 0;
				}
				else if(run == 0){//if teacher login is successful
					U.after_login_teacher(teacher_list, teacher_location);
				}
				//U.enrollmentUPDT();
			}
			else if (choice == 2){ //student login
				//student stuff here
				string student_name = "", student_id_string= "";
				bool valid_id = false;
				//system("clear");
				cout << "Welcome Student!\nPlease Input your Name: "; //do not error check the student
				cin >> student_name;
				do{ //checks if the student ID is valid
					if (valid_id){
						cout << "****************************************\n* ERROR - Please Input a Valid ID. *\n****************************************\n";
						cin.clear();
						cin.ignore(10, '\n');
						valid_id = true;
					}
					cout << "\nPlease Input your ID: ";
					cin >> student_id_string;
					valid_id = check_id(student_id_string, student_id, valid_id, dummy_counter);
				} while (valid_id = false);
					U.after_login_student(student_name, student_id_string);
			}
			U.DeleteEmptyLines("courses.txt");
			U.DeleteEmptyLines("enrollment.txt");
		} while (loop == 1);
		do {
			cout << "Restart Program? - Y/N (case sensitive): ";
			cin >> restart;	
		} while (restart != "Y" && restart != "N");
	} while (restart == "Y");
	
	return 0;
}