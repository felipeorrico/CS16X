/******************************************************
** Program: university.cpp
** Date: 10/26/2019
** Description:  university class implementation file
******************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "course.h"
#include "functions.h"
#include "university.h"
#include <vector>

using namespace std;

/*********************************************************************
** Function: getter function
** Description: gets name and returns
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: return name
*********************************************************************/ 
string University::get_name(){
	return name;
}

/*********************************************************************
** Function: add_to_catalog
** Description: adds a course to the catalog
** Parameters: course
** Pre-Conditions: -
** Post-Conditions: update file
*********************************************************************/ 
void University::add_to_catalog(Course course_to_add){ //works well!
	ofstream file("courses.txt", ios_base::app);
	string *p = nullptr;
	if (course_to_add.get_current_enrollment() != 0)
		p = course_to_add.get_roster();
	file << endl <<course_to_add.get_name() << " " << course_to_add.get_instructor()<< " " << course_to_add.get_term()<< " " << course_to_add.get_days()<< " " <<course_to_add.get_start_time()<< " " << course_to_add.get_end_time()<< " " << course_to_add.get_location()<< " " << course_to_add.get_current_enrollment();
	if (course_to_add.get_current_enrollment() == 0){
		goto end;	
	}	
	for (int i = 0; i < course_to_add.get_current_enrollment(); i++){
		file << " "<< p[i];
	}
	end:;
	file.close();
	DeleteEmptyLines("courses.txt");
}

/*********************************************************************
** Function: erase_file
** Description: erases contents of file2
** Parameters: file name
** Pre-Conditions: - 
** Post-Conditions: updates file
*********************************************************************/ 
void University::erase_file(string filename){
	ofstream ofs;
	ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

/*********************************************************************
** Function: DeleteEmptyLines
** Description: deletes empty lines from a file
** Parameters: string filename
** Pre-Conditions: -
** Post-Conditions: updates file
*********************************************************************/ 
void University::DeleteEmptyLines(const string &FilePath) //WORKING
{
	ifstream in(FilePath);
    string line, text;
    while (getline(in, line))
        if (!line.empty())
            text = text + line + "\n";
    in.close();
    ofstream out(FilePath);
    out << text;
	out.close();
}

/*********************************************************************
** Function: remove_from_catalog
** Description: removes course from catalog
** Parameters: index
** Pre-Conditions: -
** Post-Conditions: removes course from course file
*********************************************************************/ 
void University::remove_from_catalog(int index){ //WORKING
	cout << "\n\n"<<courses[index].get_name() << " Removed!\n\n";
	courses[index].set_name("BLANK");
	erase_file("courses.txt");
	ofstream file("courses.txt");

	for (int j = 0; j < num_courses; j++){
		if (courses[j].get_name() == "BLANK")
			continue;
		if (j > 0)
			file << endl;
		file << courses[j].get_name() << " "<< courses[j].get_instructor() << " "<< courses[j].get_term() << " "<< courses[j].get_days() << " "<<courses[j].get_start_time() << " "<< courses[j].get_end_time() << " "<< courses[j].get_location() << " "<< courses[j].get_current_enrollment();
		if (courses[j].get_current_enrollment() == 0)
			continue;
		
		string *p = courses[j].get_roster();
		for (int i = 0; i < courses[j].get_current_enrollment(); i++){
			file << " "<< p[i];
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
}

/*********************************************************************
** Function: get_term
** Description: gets university term and returns it
** Parameters: -
** Pre-Conditions: - 
** Post-Conditions: returns term
*********************************************************************/ 
string University::get_term(){
	if(current_term == "Fall"){
		return "F";
	} else if (current_term == "Winter"){
		return "W";
	} else if (current_term == "Spring"){
		return "S";
	} else if (current_term == "Summer"){
		return "U";
	}
}

/*********************************************************************
** Function: search_courses_by_term
** Description: search course by term
** Parameters: term
** Post-Conditions: returns array of sorted courses
*********************************************************************/ 
Course* University::search_courses_by_term(string term){ //working
	int number_courses_term = get_num_courses_term(term);
	string list[num_courses];
	for (int i = 0; i < num_courses; i++){
		if(courses[i].get_term() == term){
			list[i] = courses[i].get_name();
		}
	}
	Course *sorted = new Course[number_courses_term];
	int counter = 0;
	//cout << "Number of Courses in Term: " << number_courses_term << endl;
	for (int i = 0; i < num_courses; i++){
		if(courses[i].get_name() == list[i]){
			sorted[counter] = courses[i];
			counter++;
		}
	}
	
	return sorted;
}

/*********************************************************************
** Function: search_courses_by_term_2
** Description: like search_courses_by_term but with more args for advanced
** Parameters: string, course, int
** Pre-Conditions: valid input
** Post-Conditions: updates course array
*********************************************************************/ 
Course* University::search_courses_by_term_2(string term, Course *yo,int number_courses_term){ //working
	string list[num_courses];
	for (int i = 0; i < num_courses; i++){
		if(yo[i].get_term() == term){
			list[i] = yo[i].get_name();
		}
	}
	Course *sorted = new Course[number_courses_term];
	int counter = 0;
	for (int i = 0; i < num_courses; i++){
		if(yo[i].get_name() != "BLANK"){
			sorted[counter] = yo[i];
			counter++;
		}
	}
	return sorted;
}

/*********************************************************************
** Function:  get_num_courses_term
** Description: gets the number of courses in a term
** Parameters: term
** Pre-Conditions: valid input
** Post-Conditions: returns number
*********************************************************************/ 
int University::get_num_courses_term(string term){ //working
	int number_courses_term = 0;
	for (int i = 0; i < num_courses; i++){
		if(courses[i].get_term() == term){
			number_courses_term++;
		}
	}
	return number_courses_term;
}

/*********************************************************************
** Function:  get_course_time
** Description: get number of courses after time search
** Parameters: course array
** Pre-Conditions: valid input 
** Post-Conditions: returns number
*********************************************************************/ 
int University::get_num_courses_time(Course *yo){ //working
	int number_courses_term = 0;
	for (int i = 0; i < num_courses; i++){
		if(yo[i].get_name() != "BLANK"){
			number_courses_term++;
		}
	}
	return number_courses_term;
}

/*********************************************************************
** Function: printSorted_1
** Description: 1/4 printing functions for specific purpose
** Parameters: course array, num
** Pre-Conditions: valid input
** Post-Conditions: print
*********************************************************************/ 
void University::printSorted_1 (Course *sorted, int num){ //working
	cout << "\n\nSorting by Term:\n" << endl;
	for (int i = 0; i < num; i++){//courses
		string term_c = sorted[i].get_term();
		string name_c = sorted[i].get_name();
		string instructor_c = sorted[i].get_instructor();
		int current_c = sorted[i].get_current_enrollment();
		string days_c = sorted[i].get_days();
		string start_time_c = sorted[i].get_start_time();
		string end_time_c = sorted[i].get_end_time();
		cout << term_c <<", "<< name_c <<  ", " << instructor_c <<  ", " << current_c <<  ", " << days_c <<  ", " << start_time_c <<  ", " << end_time_c << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: printSorted_4
** Description: 4/4 printing function 
** Parameters: course array, int and term
** Pre-Conditions: valid input
** Post-Conditions: print
*********************************************************************/ 
void University::printSorted_4 (Course *sorted, int num, string term){ //working
	cout << "\n\nSorting by Term:\n" << endl;
	for (int i = 0; i < num; i++){//courses
		if (sorted[i].get_term() != term)
			continue;
		string term_c = sorted[i].get_term();
		string name_c = sorted[i].get_name();
		string instructor_c = sorted[i].get_instructor();
		int current_c = sorted[i].get_current_enrollment();
		string days_c = sorted[i].get_days();
		string start_time_c = sorted[i].get_start_time();
		string end_time_c = sorted[i].get_end_time();
		cout << term_c <<", "<< name_c <<  ", " << instructor_c <<  ", " << current_c <<  ", " << days_c <<  ", " << start_time_c <<  ", " << end_time_c << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: time_sort_term
** Description: sorts term after sorting time
** Parameters: course array, time array, number, sorted number
** Pre-Conditions: valid input
** Post-Conditions: return string
*********************************************************************/ 
string *University::time_sort_term(Course *sorted, string *times, int num_times, int num_sorted){ //working
	string *finite = new string[num_sorted];
	for (int i = 0; i < num_sorted; i++){
		finite[i] = sorted[i].get_name();
	}
	for (int i = 0; i < num_times; i++){
		for (int j = 0; j < num_sorted; j++){
			if (times[i] == sorted[j].get_start_time()){
				finite[j] = "BLANK";
			}
		}
	}
	return finite;
	
}

/*********************************************************************
** Function: search_courses_by_times
** Description: searches course by times
** Parameters: times array and number
** Pre-Conditions: valid input
** Post-Conditions: return string
*********************************************************************/ 
Course *University::search_courses_by_times(string* times, int num_times){
	Course *finite = courses;
	for (int i = 0; i < num_times; i++){
		for (int j = 0; j < num_courses; j++){
			if (times[i] == finite[j].get_start_time()){
				finite[j].set_name("BLANK");
			}
		}
	}
	return finite;
}

/*********************************************************************
** Function: printSorted_3
** Description: 3/4 specific print function	
** Parameters: course array
** Pre-Conditions: valid input
** Post-Conditions: save to screen
*********************************************************************/ 
void University::printSorted_3 (Course *sorted){
	cout << "\n\nSorting by Time:\n" << endl;
	for (int i = 0; i < num_courses; i++){
		for (int j = 0; j < num_courses; j++){
			if (courses[i].get_name() == sorted[j].get_name() && sorted[j].get_name() != "BLANK"){
				if (courses[i].get_name() == sorted[j].get_name() && courses[i].get_term() != sorted[j].get_term())
					continue;
				string term_c = courses[i].get_term();
				string name_c = courses[i].get_name();
				string instructor_c = courses[i].get_instructor();
				int current_c = courses[i].get_current_enrollment();
				string days_c = courses[i].get_days();
				string start_time_c = courses[i].get_start_time();
				string end_time_c = courses[i].get_end_time();
				cout << term_c <<", "<< name_c <<  ", " << instructor_c <<  ", " << current_c <<  ", " << days_c <<  ", " << start_time_c <<  ", " << end_time_c << endl;
			}
		}
	}
	cout << endl;
}

/*********************************************************************
** Function: add_a_course
** Description: adds a course to the catch
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: 
*********************************************************************/ 
void University::add_a_course(){
	string name_c, teacher, start_time, end_time, days, term_c, location;
	get_new_course_info(name_c, teacher,start_time,end_time, days, term_c, location);
	Course temp(name_c, teacher, start_time, end_time, days,term_c,location);
	add_to_catalog(temp);
}

/*********************************************************************
** Function: get_course_index
** Description: gets theindex of a given course
** Parameters: name, term instructor
** Pre-Conditions: valid input
** Post-Conditions: returns error or index
*********************************************************************/ 
int University::get_course_index(string course_name, string course_term, string course_teacher){
	for (int i = 0; i < num_courses; i++){
		if (courses[i].get_name() == course_name && courses[i].get_term() == course_term && courses[i].get_instructor() == course_teacher){
			//cout << "Course Index: " << i << endl;
			return i;
		} 
	}
	cout << "\n\nFailed To find Course with that information. please input again!\n\n";
	return 1000;
	//probably return something if error?
}

/*********************************************************************
** Function: removeStudent
** Description: removes student from course
** Parameters: course index
** Pre-Conditions: valid input
** Post-Conditions: save to file
*********************************************************************/ 
void University::removeStudent(int index){ //WORKS
	string id;
	cout << "Please Input Student id for removal: ";
	cin >> id;
	cout << endl;
	courses[index].remove_student_course(id);
	erase_file("courses.txt");
	ofstream file("courses.txt");
	for (int j = 0; j < num_courses; j++){
		if (j > 0)
			file << endl;
		file << courses[j].get_name() << " "<< courses[j].get_instructor() << " "<< courses[j].get_term() << " "<< courses[j].get_days() << " "<<courses[j].get_start_time() << " "<< courses[j].get_end_time() << " "<< courses[j].get_location() << " "<< courses[j].get_current_enrollment();
		if (courses[j].get_current_enrollment() == 0)
			continue;
		
		string *p = courses[j].get_roster();
		for (int i = 0; i < courses[j].get_current_enrollment(); i++){
			file << " "<< p[i];
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
}

/*********************************************************************
** Function: enrollStudent
** Description: enrolls student to course
** Parameters: course index
** Pre-Conditions: valid input
** Post-Conditions: saves to file
*********************************************************************/ 
void University::enrollStudent(int index){
	string stid, stname;
	cout << "Please Input Student id to enroll: ";
	cin >> stid;
	cout << endl;
	cout << "Please Input Student Name to enroll: ";
	cin >> stname;
	cout << endl;
	courses[index].enroll_student(stid);
	erase_file("courses.txt");
	ofstream file("courses.txt");
	for (int j = 0; j < num_courses; j++){
		if (j > 0)
			file << endl;
		file << courses[j].get_name() << " "<< courses[j].get_instructor() << " "<< courses[j].get_term() << " "<< courses[j].get_days() << " "<<courses[j].get_start_time() << " "<< courses[j].get_end_time() << " "<< courses[j].get_location() << " "<< (courses[j].get_current_enrollment());
		if (courses[j].get_current_enrollment() == 0)
			continue;
		
		string *p = courses[j].get_roster();
		for (int i = 0; i < courses[j].get_current_enrollment(); i++){
			file << " "<< p[i];
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
	ofstream file2("enrollment.txt", ios_base::app);
	file2 << "\n" << stname << " "<< stid << " "<< courses[index].get_name() << " "<< courses[index].get_term();
	file2.close();
	DeleteEmptyLines("enrollment.txt");
	cout << "Student " << stname << " Added to Course " << courses[index].get_name() << endl;
}

/*********************************************************************
** Function: edit_a_course
** Description: edit courses driver function
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: -
*********************************************************************/ 
void University::edit_a_course(){ 
	int choice = 0, index = 0;
	do {
		cin.clear();
		cin.ignore(10, '\n');
		string course_name, course_term, course_teacher;
		cout << "Please Input the Course Name: ";
		cin >> course_name;
		cout << "\n\nPlease input the Course Term: ";
		cin >> course_term;
		cout << "\n\nPlease input the Course Instructor: ";
		cin >> course_teacher;	
		index = get_course_index(course_name, course_term, course_teacher);
	} while (index == 1000);
	courses[index].print_course();
	loop_for_int(choice, "\n\nEdit Menu:\n (1)Remove course\n (2)Change Course Information\n (3)Add Student to Course\n", 3, 1);
	if (choice == 1){ // remove course
		remove_from_catalog(index);
	} else if (choice == 2){ // change course information
		int change;
		loop_for_int(change, "\n\nEdit Course Information:\n (1)Remove Student From Course\n (2)Change Name\n (3)Change Start Time\n (4)Change End Time\n (5)Change Term\n (6)Change Location\n (7)Change Instructor\n\n", 7, 1);
		switch (change){
			case 1: removeStudent(index);
					break;
			default: changeCourseInfo(index, change);
					break;
		}
	} else if (choice == 3){ // add student to course
		enrollStudent(index);
	}
}

/*********************************************************************
** Function: theifs
** Description: if statements to reduce space
** Parameters: index and choice
** Pre-Conditions: valid input
** Post-Conditions: update desired
*********************************************************************/ 
void University::theifs (int index, int choice){
	string alt;
	if (choice == 2){
		cout << "Please input new name: ";
		cin >> alt;
		courses[index].set_name(alt);
	} else if (choice == 3){
		cout << "Please input new Start Time: ";
		cin >> alt;
		courses[index].set_start_time(alt);
	} else if (choice == 4){
		cout << "Please input new End Time: ";
		cin >> alt;
		courses[index].set_end_time(alt);
	} else if (choice == 5){
		cout << "Please input new Term: ";
		cin >> alt;
		courses[index].set_term(alt);
	} else if (choice == 6){
		cout << "Please input new Location: ";
		cin >> alt;
		courses[index].set_location(alt);
	} else if (choice == 7){
		cout << "Please input new Instructor: ";
		cin >> alt;
		courses[index].set_instructor(alt);
	}
}

/*********************************************************************
** Function: changeCourseInfo
** Description: edits course information
** Parameters: index choice
** Pre-Conditions: valid input
** Post-Conditions: updates course
*********************************************************************/ 
void University::changeCourseInfo(int index, int choice){
	cout << "\n\n"<<courses[index].get_name() << " - Editor Mode!\n\n";
	theifs(index, choice);
	
	erase_file("courses.txt");
	ofstream file("courses.txt");

	for (int j = 0; j < num_courses; j++){
		if (j > 0)
			file << endl;
		file << courses[j].get_name() << " "<< courses[j].get_instructor() << " "<< courses[j].get_term() << " "<< courses[j].get_days() << " "<<courses[j].get_start_time() << " "<< courses[j].get_end_time() << " "<< courses[j].get_location() << " "<< courses[j].get_current_enrollment();
		if (courses[j].get_current_enrollment() == 0)
			continue;
		
		string *p = courses[j].get_roster();
		for (int i = 0; i < courses[j].get_current_enrollment(); i++){
			file << " "<< p[i];
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
	cout << "Course EDITED!" << endl;
}

/*********************************************************************
** Function: edit_remove_add
** Description: choice on edit remove or add driver function
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: calls proper function
*********************************************************************/ 
bool University::edit_remove_add(){
	int edit;
	loop_for_int(edit, "\n\nWould you like to Edit/Add a course?\n\n (1) Yes - Edit;\n (2) Yes - Add\n (3) No;\n\n",3, 1);
	if (edit == 1){
		edit_a_course();
		return false;
	}else if (edit == 2) {
		add_a_course();
		return false;
	} 
	else if (edit == 3){
		return true;
	}
}

/*********************************************************************
** Function: printSorted_2
** Description: print function 2/4
** Parameters: course array, time, array, num, num2, term
** Pre-Conditions: valid input
** Post-Conditions: updates search
*********************************************************************/ 
void University::printSorted_2 (Course *sorted, string *times,int num, string term_chosen, int num2){
	cout << "\n\nSorting by Time:\n" << endl;
	for (int i = 0; i < num_courses; i++){ //per course
		for (int j = 0; j < num2; j++){ //per time
			for (int k = 0; k < num; k++){
				if (courses[i].get_name() == sorted[j].get_name() && courses[i].get_start_time() != times[k] && courses[i].get_term() == term_chosen){
					string term_c = courses[i].get_term();
					string name_c = courses[i].get_name();
					string instructor_c = courses[i].get_instructor();
					int current_c = courses[i].get_current_enrollment();
					string days_c = courses[i].get_days();
					string start_time_c = courses[i].get_start_time();
					string end_time_c = courses[i].get_end_time();
					cout << term_c <<", "<< name_c <<  ", " << instructor_c <<  ", " << current_c <<  ", " << days_c <<  ", " << start_time_c <<  ", " << end_time_c << endl;
				}
			}
		}
	}
	cout << endl;
}

/*********************************************************************
** Function: after_login_teacher
** Description: driver function for the behavior after a teacher logs in
** Parameters: list of teachers, location of user
** Pre-Conditions: valid input
** Post-Conditions: drives program, calls correct function
*********************************************************************/ 
void University::after_login_teacher(teacher *teacher_list, int user_location){
	cout << "Welcome "<< teacher_list[user_location].first_name << " " << teacher_list[user_location].last_name<< "\n\n - ID: " << teacher_list[user_location].id << "\n\nAs a Teacher you can visualize all the courses in the University.\n\n";
	printCourses();
	int initial_choice;
	loop_for_int (initial_choice, "\n\nWould you like to:\n\n (1) Sort Courses;\n (2) Add a Course; \n (3) Edit a course;\n\n", 3, 1);
	if(initial_choice == 1){ //case wants to sort courses
		int sort_choice=0;
		loop_for_int (sort_choice, "\n\nWould you like to Sort By:\n\n (1) Term;\n (2) Times;\n\n", 2, 1);
		if (sort_choice == 1){ //sort by term
			teacher_separation_choice1();
		} else if(sort_choice == 2){ //sort by Times
			teacher_separation_choice2();
		}
	} else if (initial_choice == 2){ //case chose to add a course - WORKS!
		add_a_course();
		goto the_end;
		
	} else if (initial_choice == 3){ //case chose to edit a course - Finish This
		edit_a_course();
	}
	the_end:;
}

/*********************************************************************
** Function: teacher_separation_choice1
** Description: separates from choice
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: calls proper functions
*********************************************************************/ 
void University::teacher_separation_choice1(){
	string term_chosen = "";
	cout << "\nPlease Enter the TERM you want to filter (F, W, S, U): ";
	cin >> term_chosen;
	int number_courses_term = get_num_courses_term(term_chosen);
	Course *sorted = search_courses_by_term(term_chosen);
	printSorted_1(sorted, number_courses_term);
	int sort_choice_2 = 2;
	
	
	if (number_courses_term > 1) //checks if in that therm there is more than 1 course.
		loop_for_int (sort_choice_2, "\n\nWould you like to Sort By Time?\n\n (1) Yes;\n (2) No;\n\n", 2, 1);
	
	
	if (sort_choice_2 == 1){//sort by time
		int times = 1, edit;
		loop_for_int(times, "\n\nHow many times would you like the search to not include?(maximum of 5)\n\n",5, 1);
		string db[times];
		for (int i = 0; i < times; i++){
			cout << "Please input a time (Courses that are after that time will be displayed): ";
			cin >> db[i];
			cout << endl;
		}
		printSorted_2(sorted, db, times, term_chosen, number_courses_term);
		
		bool quit = edit_remove_add();//ask to edit course or Quit
		if (quit) goto end;
	
	} else if (sort_choice_2 == 2){ //ask to edit course or quit
		bool quit = edit_remove_add();
		if (quit) goto end;
	}

	
	end:;
	delete[] sorted;
}

/*********************************************************************
** Function: teacher_separation_choice2
** Description: separates from choice
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: calls proper functions
*********************************************************************/ 
void University::teacher_separation_choice2(){
	int times = 1;
	loop_for_int(times, "\n\nHow many times would you like the search to not include?(maximum of 5)\n\n",5, 1);
	string db[times];
	for (int i = 0; i < times; i++){
		cout << "Please input a time (Courses that are after that time will be displayed): ";
		cin >> db[i];
		cout << endl;
	}
	Course* test  = search_courses_by_times(db, times);
	printSorted_3(test);
	
	int number_of_courses_times = get_num_courses_time(test);
	int sort_choice_2 = 2;
	if (number_of_courses_times > 1){
		loop_for_int (sort_choice_2, "\n\nWould you like to Sort By Term?\n\n (1) Yes;\n (2) No;\n\n", 2, 1);
	}
	if (sort_choice_2 == 1){
		string term_chosen = "";
		cout << "\nPlease Enter the TERM you want to filter (F, W, S, U): ";
		cin >> term_chosen;
		Course *sorte = search_courses_by_term_2(term_chosen, test, number_of_courses_times);
		printSorted_4(sorte, number_of_courses_times, term_chosen);
		edit_remove_add();
	} else if (sort_choice_2 == 2){
		//edit/add/remove course
		edit_remove_add();
	}
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: valid input
** Post-Conditions: 
*********************************************************************/ 
void University::get_new_course_info (string &name_c, string &teacher, string &start_time, string &end_time, string &days, string &term_c, string &location){
	cout << "\nPlease input the Course Name: ";
	cin >> name_c;
	cout << "\nPlease input the Course Teacher: ";
	cin >> teacher;
	cout << "\nPlease input the Course start time: ";
	cin >> start_time;
	cout << "\nPlease input the Course end time: ";
	cin >> end_time;
	cout << "\nPlease input the Course days: ";
	cin >> days;
	cout << "\nPlease input the Course Term: ";
	cin >> term_c;
	cout << "\nPlease input the Course Location (no spaces):";
	cin >> location;
}

/*********************************************************************
** Function: printCourses
** Description: prints courses
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: print courses
*********************************************************************/ 
void University::printCourses() const{
	string course_names[num_courses];
	for(int i = 0; i < num_courses; i++){
		course_names[i] = courses[i].get_name();
	}
	check_for_repetition(course_names, num_courses);
	cout << "\n\nAvailable Courses: \n\n";
	for (int i = 0; i < num_courses; i++){ //size of course_names array
		for (int j = 0; j < num_courses; j++){ //number of courses
			if (course_names[i] == courses[j].get_name()){
				bool trigger = true;
				schedule *dummy = courses[j].get_course_time();
				for (int x = j+1; x < num_courses; x++){ //checks if there are courses with the same name
					if (courses[x].get_name() == courses[j].get_name()&& courses[x].get_instructor() == courses[j].get_instructor()){
						cout << courses[j].get_name() << ", " << courses[j].get_instructor() << endl;
						cout << " - " << dummy[0].term << ", "<< dummy[0].days << ", "<< dummy[0].start_time << ", "<< dummy[0].end_time << ", "<< dummy[0].location << ", "<< courses[j].get_current_enrollment() << endl;
						schedule *dummy = courses[x].get_course_time();
						cout << " - " << dummy[0].term << ", "<< dummy[0].days << ", "<< dummy[0].start_time << ", "<< dummy[0].end_time << ", "<< dummy[0].location << ", "<< courses[x].get_current_enrollment() << endl;
						trigger = false;
						goto next;
					} else continue;
				}
				//here checks if was printed before and if so skips
				if (trigger){
					cout << courses[j].get_name() << ", " << courses[j].get_instructor() << endl;
					cout << " - " << dummy[0].term << ", "<< dummy[0].days << ", "<< dummy[0].start_time << ", "<< dummy[0].end_time << ", "<< dummy[0].location << ", "<< courses[j].get_current_enrollment() << endl;
				}
			} else continue;
		}
		next:;
	}
}

/*********************************************************************
** Function: default constructor
** Description: default constructor
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: -
*********************************************************************/ 
University::University(){ //already assign courses to the university
	// cout << "Creating University Object" << endl;
	ifstream file("university.txt");
	getline(file, name);
	getline(file, address);
	getline(file, current_term);
	file.close();
	ifstream course_file("courses.txt");
	num_courses = count_lines(course_file);
	reset_file(course_file);
	courses = new Course[num_courses];
	courses->fill_courses(courses);
	course_file.close();
	ifstream teacher_file("teacher.txt");
	int teacher_number = count_lines(teacher_file);
	reset_file(teacher_file);
	teachers = new teacher[teacher_number];
	for(int i = 0; i < teacher_number; i++){
		teacher_file >> teachers[i].id >> teachers[i].password >> teachers[i].first_name >> teachers[i].last_name;
		// cout << teachers[i].id << " " << teachers[i].password << " " << teachers[i].first_name << " " << teachers[i].last_name<< endl;
	}
	teacher_file.close();
	// cout << "Name: " << name << "\nAddress: " << address << "\nTerm: " << current_term << endl;
}

/*********************************************************************
** Function: destructor
** Description: destructor
** Parameters: -
** Pre-Conditions: out of scope
** Post-Conditions: -
*********************************************************************/ 
University::~University(){
	delete[] courses;
	courses = nullptr;
	delete[] teachers;
	teachers = nullptr;
}

/*********************************************************************
** Function: get_teachers
** Description: returns teachers
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: returns  
*********************************************************************/ 
teacher* University::get_teachers(){
	ifstream teacher_file("teacher.txt");
	int teacher_number = count_lines(teacher_file);
	teacher_file.close();
	return teachers;
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: valid input
** Post-Conditions: 
*********************************************************************/ 
int University::get_teacher_number(){
	ifstream teacher_file("teacher.txt");
	int teacher_number = count_lines(teacher_file);
	teacher_file.close();
	return teacher_number;
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: valid input
** Post-Conditions: 
*********************************************************************/ 
University::University(const University& U){
    name = U.name;
	address = U.address;
	current_term = U.current_term;
	ifstream teacher_file("teacher.txt");
	int teacher_number = count_lines(teacher_file);
	teacher_file.close();
	teachers = new teacher[teacher_number];
	for(int i = 0; i < teacher_number; i++){
		teachers[i] = U.teachers[i];
	}
	num_courses = U.num_courses;
	courses = new Course[num_courses];
	for(int i = 0; i < num_courses; i++){
		courses[i] = U.courses[i];
	}
}

/*********************************************************************
** Function: assignmenr operator ovl
** Description: operloads =
** Parameters: university
** Pre-Conditions: valid input
** Post-Conditions: sets value to another obj
*********************************************************************/ 
University& University::operator= (const University &U){
    if (teachers){
		delete[] teachers;
		teachers = nullptr;
	}
	if (courses){
		delete[] courses;
		courses = nullptr;
	}
	name = U.name;
	address = U.address;
	current_term = U.current_term;
	ifstream teacher_file("teacher.txt");
	int teacher_number = count_lines(teacher_file);
	teacher_file.close();
	teachers = new teacher[teacher_number];
	for(int i = 0; i < teacher_number; i++){
		teachers[i] = U.teachers[i];
	}
	num_courses = U.num_courses;
	courses = new Course[num_courses];
	for(int i = 0; i < num_courses; i++){
		courses[i] = U.courses[i];
	}
    return *this;
}

/*********************************************************************
** Function: reg_student
** Description: register student - student side
** Parameters: name and id
** Pre-Conditions: valid input
** Post-Conditions: register student
*********************************************************************/ 
void University::reg_student(string stname, string stid){
	int index = 1000;
	do {
		cin.clear();
		cin.ignore(10, '\n');
		string course_name, course_term, course_teacher;
		cout << "Please Input the Course Name: ";
		cin >> course_name;
		cout << "\n\nPlease input the Course Term: ";
		cin >> course_term;
		cout << "\n\nPlease input the Course Instructor: ";
		cin >> course_teacher;	
		index = get_course_index(course_name, course_term, course_teacher);
	} while (index == 1000);
	courses[index].enroll_student(stid);
	erase_file("courses.txt");
	ofstream file("courses.txt");
	for (int j = 0; j < num_courses; j++){
		if (j > 0)
			file << endl;
		file << courses[j].get_name() << " "<< courses[j].get_instructor() << " "<< courses[j].get_term() << " "<< courses[j].get_days() << " "<<courses[j].get_start_time() << " "<< courses[j].get_end_time() << " "<< courses[j].get_location() << " "<< (courses[j].get_current_enrollment());
		if (courses[j].get_current_enrollment() == 0)
			continue;
		
		string *p = courses[j].get_roster();
		for (int i = 0; i < courses[j].get_current_enrollment(); i++){
			file << " "<< p[i];
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
	ofstream file2("enrollment.txt", ios_base::app);
	file2 << "\n" << stname << " "<< stid << " "<< courses[index].get_name() << " "<< courses[index].get_term();
	file2.close();
	cout << "\n\nRegistered!\n\n";
}

/*********************************************************************
** Function: after_login_student
** Description: student options after login
** Parameters: name and id
** Pre-Conditions: valid input
** Post-Conditions: chooses valid call
*********************************************************************/ 
void University::after_login_student(string student_name, string student_id_string){
	cout << "Welcome "<< student_name <<  "\n\n - ID: " << student_id_string << "\n\nAs a Student you can view and enroll to courses!\n\n";
	printCourses();
	int initial_choice;
	loop_for_int (initial_choice, "\n\nWould you like to:\n\n (1) Sort Courses;\n (2) Enroll to a Course;\n\n", 2, 1);
	if(initial_choice == 1){ //case wants to sort courses
		int sort_choice=0;
		loop_for_int (sort_choice, "\n\nWould you like to Sort By:\n\n (1) Term;\n (2) Times;\n\n", 2, 1);
		if (sort_choice == 1){ //sort by term
			student_separation_choice1(student_name, student_id_string);

		} else if(sort_choice == 2){ //sort by Times
			student_separation_choice2(student_name, student_id_string);

		}
	} else if (initial_choice == 2){//register for course here
		reg_student(student_name, student_id_string);
	}
	the_end:;
}

/*********************************************************************
** Function: student_separation_choice1
** Description: student separation of choice 1
** Parameters: name id
** Pre-Conditions: valid input
** Post-Conditions: chooses valid call
*********************************************************************/ 
void University::student_separation_choice1(string student_name, string student_id_string){
	string term_chosen = "";
	cout << "\nPlease Enter the TERM you want to filter (F, W, S, U): ";
	cin >> term_chosen;
	int number_courses_term = get_num_courses_term(term_chosen);
	Course *sorted = search_courses_by_term(term_chosen);
	printSorted_1(sorted, number_courses_term);
	int sort_choice_2 = 2;
	
	
	if (number_courses_term > 1) //checks if in that therm there is more than 1 course.
		loop_for_int (sort_choice_2, "\n\nWould you like to Sort By Time?\n\n (1) Yes;\n (2) No;\n\n", 2, 1);
	
	
	if (sort_choice_2 == 1){//sort by time
		int times = 1, edit;
		loop_for_int(times, "\n\nHow many times would you like the search to not include?(maximum of 5)\n\n",5, 1);
		string db[times];
		for (int i = 0; i < times; i++){
			cout << "Please input a time (Courses that are after that time will be displayed): ";
			cin >> db[i];
			cout << endl;
		}
		string* test = time_sort_term(sorted,db, times, number_courses_term);
		for (int i = 0; i < (number_courses_term-times); i++){
			cout << test[i];
		}
		cout << endl;
		printSorted_2(sorted, db, times, term_chosen, number_courses_term);
		
		reg_student(student_name, student_id_string);
	
	} else if (sort_choice_2 == 2){ //register for course here
		reg_student(student_name, student_id_string);
	}

	
	end:;
	delete[] sorted;
}
/*********************************************************************
** Function: student_separation_choice2
** Description: separation for choice 2 of student
** Parameters: name and id
** Pre-Conditions: valid input
** Post-Conditions: chooses valid option
*********************************************************************/ 
void University::student_separation_choice2(string student_name, string student_id_string){
	int times = 1;
	loop_for_int(times, "\n\nHow many times would you like the search to not include?(maximum of 5)\n\n",5, 1);
	string db[times];
	for (int i = 0; i < times; i++){
		cout << "Please input a time (Courses that are after that time will be displayed): ";
		cin >> db[i];
		cout << endl;
	}
	Course* test  = search_courses_by_times(db, times);
	printSorted_3(test);
	
	int number_of_courses_times = get_num_courses_time(test);
	int sort_choice_2 = 2;
	if (number_of_courses_times > 1){
		loop_for_int (sort_choice_2, "\n\nWould you like to Sort By Term?\n\n (1) Yes;\n (2) No;\n\n", 2, 1);
	}
	if (sort_choice_2 == 1){
		string term_chosen = "";
		cout << "\nPlease Enter the TERM you want to filter (F, W, S, U): ";
		cin >> term_chosen;
		Course *sorte = search_courses_by_term_2(term_chosen, test, number_of_courses_times);
		printSorted_4(sorte, number_of_courses_times, term_chosen);
		edit_remove_add();
	} else if (sort_choice_2 == 2){//register for course here
		reg_student(student_name, student_id_string);
	}
}

/*********************************************************************
** Function: enrollmentUPDT
** Description: updates enrollment file < supposed to
** Parameters: -
** Pre-Conditions: valid input
** Post-Conditions: updates file 
*********************************************************************/ 
void University::enrollmentUPDT(){ //update enrollment file <- do this and use at the end of the teacher part to sync
	
	student *student_list = get_student(student_list);
	
	ifstream file2("enrollment.txt");
	int num_students = count_lines(file2);
	cout << num_students << endl;
	file2.close();
	erase_file("enrollment.txt");
	ofstream file("enrollment.txt");
	
	for (int i = 0; i < num_students; i++){ //per student
		for (int j = 0; j < student_list[i].number_of_enrolled_courses; j++){//per numbers of courses in student
			for (int k = 0; j < num_courses; k++){ //per course
				int temp_enrollment = courses[k].get_current_enrollment();
				if (temp_enrollment == 0){
					continue;
				}
				string *temp_roster = courses[k].get_roster();
				if (courses[k].get_name() == student_list[i].enrolled[j].name && courses[k].get_term() == student_list[i].enrolled[j].term){
					for (int m = 0; m < courses[k].get_current_enrollment(); m++){
						if (temp_roster[m] == student_list[i].id){
							file << student_list[i].name << " " << student_list[i].id << " "<< courses[k].get_name() << " " << courses[k].get_term();
						}
					}
				}
				delete[] temp_roster;
			}
		}
	}
	file.close();
	DeleteEmptyLines("courses.txt");
	delete[] student_list;
}

/*********************************************************************
** Function: get_student
** Description: get stuff from file enrollment and pass to struct
** Parameters: list of students
** Pre-Conditions: valid input
** Post-Conditions: returns student array
*********************************************************************/ 
student *University::get_student(student *student_list){ //fix this
	
	ifstream file("enrollment.txt");
	int number_of_students = count_lines(file);
	reset_file(file);
	cout << number_of_students << endl;
	student_list = new student[number_of_students];

	for (int i = 0; i < number_of_students; i++){
		file >> student_list[i].name >> student_list[i].id;
		cout << "Student info:" << endl;
		cout << student_list[i].name << " " << student_list[i].id << endl;
		student_list[i].number_of_enrolled_courses = 0;
		
		for (int m = 0; m < num_courses; m++){
			// if (courses[m].get_name() == "BLANK")
				// continue;
			string *temp_roster =  courses[m].get_roster();
			for (int r = 0; r < courses[m].get_current_enrollment(); r++){
				if (temp_roster[r] == student_list[i].id){
					student_list[i].number_of_enrolled_courses++;
				}
			}
			delete[] temp_roster;
		}
		
		cout << student_list[i].name << " enrolled to " << student_list[i].number_of_enrolled_courses << " courses\n";
		student_list[i].enrolled = new studentCourses[student_list[i].number_of_enrolled_courses];
		for (int j = 0; j < student_list[i].number_of_enrolled_courses; j++){
			file >> student_list[i].enrolled[j].name >> student_list[i].enrolled[j].term;
		}
		for (int k = 0; k < student_list[i].number_of_enrolled_courses; k++){
			cout << student_list[i].name << " " << student_list[i].id << " "<< student_list[i].enrolled[k].name << " "<< student_list[i].enrolled[k].term << endl;
		}
	}
	file.close();
	
	cout << "\nGot students from file\n";
	return student_list;
}