/******************************************************
** Program: course.cpp
** Date: 10/26/2019
** Description:  course class implementation file
******************************************************/
#include <iostream>
#include "course.h"
#include "functions.h"
#include "university.h"
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

/*********************************************************************
** Function: Course()
** Description: default constructor
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: -
*********************************************************************/ 
Course::Course(){
	name = "";
	teacher = "";
	current_enrollment = 0;
	roster = nullptr;
	course_time= nullptr;
}

/*********************************************************************
** Function: Getter/setter functions
** Description: get/set values in course
** Parameters: getters: - setters: string
** Pre-Conditions: valid use
** Post-Conditions: return/update
*********************************************************************/ 
string Course::get_days(){
	return course_time[0].days;
}
string Course::get_start_time(){
	return course_time[0].start_time;
}
string Course::get_end_time(){
	return course_time[0].end_time;
}
string Course::get_term(){
	return course_time[0].term;
}
string Course::get_location(){
	return course_time[0].location;
}
void Course::set_days(string days){
	course_time[0].days = days;
}
void Course::set_start_time(string time){
	course_time[0].start_time = time;
}
void Course::set_end_time(string time){
	course_time[0].end_time = time;
}
void Course::set_term(string term){
	course_time[0].term = term;
}
void Course::set_location(string loc){
	course_time[0].location = loc;
}

/*********************************************************************
** Function: Course(args)
** Description: special constructor
** Parameters: strings
** Pre-Conditions: valid
** Post-Conditions: create and set values
*********************************************************************/ 
Course::Course(string name2, string teacher2, string start_time2, string end_time2, string days2, string term2, string location2){
	name = name2;
	teacher = teacher2;
	current_enrollment = 0;
	roster = new string[1];
	course_time = new schedule[1];
	course_time[0].days = days2;
	course_time[0].start_time = start_time2;
	course_time[0].end_time = end_time2;
	course_time[0].term = term2;
	course_time[0].location = location2;
	current_enrollment = 0;
}

/*********************************************************************
** Function:  get_course_time
** Description: getter function
*********************************************************************/ 
schedule* Course::get_course_time(){
	return course_time;
}

/*********************************************************************
** Function: fill_courses
** Description: fills course array with stuff from the file
** Parameters: course array 
*********************************************************************/ 
void Course::fill_courses(Course *courses_in){
	ifstream file("courses.txt");
	int num_lines = count_lines(file);
	reset_file(file);
	for (int i = 0; i < num_lines; i++){
		courses_in[i].course_time = new schedule[1];
		file >> courses_in[i].name >> courses_in[i].teacher >> courses_in[i].course_time[0].term >> courses_in[i].course_time[0].days >> courses_in[i].course_time[0].start_time >> courses_in[i].course_time[0].end_time >> courses_in[i].course_time[0].location >> courses_in[i].current_enrollment;
		courses_in[i].roster = new string[courses_in[i].current_enrollment];
		for (int j = 0; j < courses_in[i].current_enrollment; j++){
			file >> courses_in[i].roster[j];
		}
	}
	file.close();
}

/*********************************************************************
** Function: printAllCourses
** Description: prints all courses
** Parameters: course array, num courses
** Pre-Conditions: -
** Post-Conditions: -
*********************************************************************/ 
void Course::printAllCourses(const Course *courses,int num_courses){
	string course_names[num_courses];
	for(int i = 0; i < num_courses; i++){
		course_names[i] = courses[i].name;
	}
	check_for_repetition(course_names, num_courses);
	cout << "\n\nPrinting courses: \n\n";
	for (int i = 0; i < num_courses; i++){ //size of course_names array
		for (int j = 0; j < num_courses; j++){ //number of courses
			if (course_names[i] == courses[j].name){
				bool trigger = true;
				for (int x = j+1; x < num_courses; x++){ //checks if there are courses with the same name
					if (courses[x].name == courses[j].name && courses[x].teacher == courses[j].teacher){
						cout << courses[j].name << ", " << courses[j].teacher << endl;
						cout << " - " << courses[j].course_time[0].term << ", "<< courses[j].course_time[0].days << ", "<< courses[j].course_time[0].start_time << ", "<< courses[j].course_time[0].end_time << ", "<< courses[j].course_time[0].location << ", "<< courses[j].current_enrollment << endl;
						for (int k = 0; k < courses[j].current_enrollment; k++){
							cout << "   - "<< courses[j].roster[k] << endl;
						}
						cout << " - " << courses[x].course_time[0].term << ", "<< courses[x].course_time[0].days << ", "<< courses[x].course_time[0].start_time << ", "<< courses[x].course_time[0].end_time << ", "<< courses[x].course_time[0].location << ", "<< courses[x].current_enrollment << endl;
						for (int k = 0; k < courses[x].current_enrollment; k++){
								cout << "   - "<< courses[x].roster[k] << endl;
						}
						trigger = false;
						goto next;
					} else continue;
				}
				//here checks if was printed before and if so skips
				if (trigger){
					cout << courses[j].name << ", " << courses[j].teacher << endl;
					cout << " - " << courses[j].course_time[0].term << ", "<< courses[j].course_time[0].days << ", "<< courses[j].course_time[0].start_time << ", "<< courses[j].course_time[0].end_time << ", "<< courses[j].course_time[0].location << ", "<< courses[j].current_enrollment << endl;
					for (int k = 0; k < courses[j].current_enrollment; k++){
						cout << "   - "<< courses[j].roster[k] << endl;
					}	
				}
			} else continue;
		}
		next:;
	}
}

/*********************************************************************
** Function: set_name/set_instructor/set_current_enrollment
** Description: setter functions
** Parameters: string
** Pre-Conditions: -
** Post-Conditions: update value
*********************************************************************/ 
void Course::set_name(string new_name){
    name = new_name;
}

void Course::set_instructor(string new_name){
    teacher = new_name;
}

void Course::set_current_enrollment(int new_enrollment){
	current_enrollment = new_enrollment;
}

/*********************************************************************
** Function: get_name/get_current_enrollment
** Description: getter function	
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: returns string/int
*********************************************************************/ 
string Course::get_name(){
    return name;
}

int Course::get_current_enrollment(){
	return current_enrollment;
}

/*********************************************************************
** Function: print_course
** Description: prints course
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: cout
*********************************************************************/ 
void Course::print_course(){
	cout <<"\n\nCourse Selected: "<< name << ", " << teacher << "\n -Term: " << course_time[0].term << ", Days: " << course_time[0].days << ", Time: "<<course_time[0].start_time << " - "<< course_time[0].end_time << ", Location: "<< course_time[0].location << ", Students Enrolled: "<< current_enrollment<< "\n -Enrolled IDs: \n";
	for (int i = 0; i < current_enrollment; i++){ //enrolled ids in course
		cout << "   - " << roster[i] << endl;
	}
}

/*********************************************************************
** Function: enroll_student
** Description: enrolls student
** Parameters: string 
** Pre-Conditions: -
** Post-Conditions: adds student to course
*********************************************************************/ 
void Course::enroll_student(string new_student){
	int temp = current_enrollment;
	set_current_enrollment((temp+1));
	//cout << current_enrollment << " SET\n";
	resize_dynamic_string(&roster, current_enrollment, temp);
	roster[current_enrollment-1] = new_student;
	//cout << "Student Added to Array\n";
}

/*********************************************************************
** Function: create_roster
** Description: creates roster array
** Parameters: int
** Pre-Conditions: -
** Post-Conditions: updates roster
*********************************************************************/ 
void Course::create_roster(int number_of_students){
	roster = new string[number_of_students+1];
}

/*********************************************************************
** Function: resize_dynamic_string
** Description: increases syse to string array
** Parameters: string**, ints
** Pre-Conditions: -
** Post-Conditions: updates **arr
*********************************************************************/ 
void Course::resize_dynamic_string (string **arr, int new_size, int old_size){
	string* arr_cpy = new string[new_size];
	copy( *arr, *arr+min(old_size,new_size), arr_cpy );
	// for (int i = 0; i < old_size; i++){
		// arr_cpy[i] = *arr[i];
	// }
	delete[] *arr;
	*arr = arr_cpy;
}

/*********************************************************************
** Function: remove_student_course
** Description: removes student from course
** Parameters: string
** Pre-Conditions: -
** Post-Conditions: remove student with given id
*********************************************************************/ 
void Course::remove_student_course(string student_id){
	if (current_enrollment == 0){
		goto end;
	}
	for (int i = 0; i < current_enrollment; i++){
		if (roster[i] == student_id){
			int temp = current_enrollment - 1;
			reduce_dynamic_string(temp, current_enrollment, student_id);
			current_enrollment--;
			break;
		}
	}
	cout << "\nStudent Removed!\n\n"; 
	end:;
}

/*********************************************************************
** Function: reduce_dynamic_string
** Description: reduces the size of a dynamic string
** Parameters: ints and string
** Pre-Conditions: -
** Post-Conditions: update roster
*********************************************************************/ 
void Course::reduce_dynamic_string (int new_size, int old_size, string removed){
	bool trigger = false;
	string array[new_size];
	for (int i = 0; i < new_size; i++){
		if(roster[i] == removed && trigger == false){
			trigger = true;
			i--;
		} else if (trigger == false && roster[i] != removed){
			array[i] = roster[i];
		} else if (trigger){
			array[i] = roster[i+1];
		}
	}
	delete[] roster;
	roster = nullptr;
	roster = new string[new_size];
	for(int i = 0; i < new_size; i++){
		roster[i] = array[i];
	}
}

/*********************************************************************
** Function: print_roster
** Description: prints roster
** Parameters: -
** Pre-Conditions: - 
** Post-Conditions: cout
*********************************************************************/ 
void Course::print_roster(){
	cout << "Roster:\n";
	for (int i = 0; i < current_enrollment; i++){
		cout << " - "<<roster[i] << endl;
	}
}

/*********************************************************************
** Function: get_instructor
** Description: gets instructor
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: returns string
*********************************************************************/ 
string Course::get_instructor(){
	return teacher;
}

/*********************************************************************
** Function: Course destructor
** Description: destroys =P
** Parameters: -
** Pre-Conditions: out of scope
** Post-Conditions: deletes all dynamic arrays
*********************************************************************/ 
Course::~Course(){
	delete[] roster;
	roster = nullptr;
	delete[] course_time;
	course_time = nullptr;
}

/*********************************************************************
** Function: operator ovld 
** Description: overloads = operator
** Parameters: course to be copied
** Pre-Conditions: valid use
** Post-Conditions: copies to other course
*********************************************************************/ 
void Course::operator= (const Course &C){
	delete[] this->roster;
	delete[] this->course_time;
	name = C.name;
	teacher = C.teacher;
	this->current_enrollment = C.current_enrollment;
	this->roster = new string[C.current_enrollment];
	for(int i = 0; i < C.current_enrollment; i++){
		this->roster[i] = C.roster[i];
	}
	this->course_time = new schedule[1];
	this->course_time[0].days = C.course_time[0].days;
	this->course_time[0].start_time = C.course_time[0].start_time;
	this->course_time[0].end_time = C.course_time[0].end_time;
	this->course_time[0].term = C.course_time[0].term;
	this->course_time[0].location = C.course_time[0].location;
    //return *this;
}

/*********************************************************************
** Function: copy constructor
** Description: copies stuff from in to course
** Parameters: course
** Pre-Conditions: -
** Post-Conditions: create & set values to new course
*********************************************************************/ 
Course::Course(const Course &C){

	name = C.name;
	teacher = C.teacher;
	current_enrollment = C.current_enrollment;
	roster = new string[current_enrollment];
	for(int i = 0; i < current_enrollment; i++){
		roster[i] = C.roster[i];
	}
	course_time = new schedule[1];
	course_time[0].days = C.course_time[0].days;
	course_time[0].start_time = C.course_time[0].start_time;
	course_time[0].end_time = C.course_time[0].end_time;
	course_time[0].term = C.course_time[0].term;
	course_time[0].location = C.course_time[0].location;
	
}

/*********************************************************************
** Function: get_student
** Description: gets the stuff from enrollment file
** Parameters: student struct
** Pre-Conditions: -
** Post-Conditions: updates student struct
*********************************************************************/ 
void Course::get_student(student *student_list){
	vector<string> vec;
	ifstream files("courses.txt");
	int num_courses = count_lines(files);
	files.close();
	for (int i= 0; i < num_courses; i++){
		int temp_enrollment = current_enrollment;
		string *temp_roster =  roster;
		for (int j = 0; j < temp_enrollment; j++){
			vec.push_back(temp_roster[j]);
		}
		delete[] temp_roster;
		temp_roster = nullptr;
	}
	int student_enroll = vec.size();
	int number_of_students = get_number_of_students();
	student_list = new student[number_of_students];
	ifstream file("enrollment.txt");
	for (int i = 0; i < number_of_students; i++){//number of students
		file >> student_list[i].name >> student_list[i].id;
		for (int j = 0; j < student_enroll; j++){ //checks the amount of enrollments that student has
			if (student_list[i].id == vec[j]){
				student_list[i].number_of_enrolled_courses++;
			}
		}
		student_list[i].enrolled = new studentCourses[student_list[i].number_of_enrolled_courses];
		for (int k = 0; k < student_list[i].number_of_enrolled_courses; k++){
			file >> student_list[i].enrolled[k].name >> student_list[i].enrolled[k].term;
		}
	}
	file.close();
}

/*********************************************************************
** Function: get_roster
** Description: getter
** Parameters: -
** Pre-Conditions: - 
** Post-Conditions: returns roster pointer
*********************************************************************/ 
string* Course::get_roster(){
	return roster;
}
