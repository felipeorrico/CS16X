/******************************************************
** Program: course.h
** Date: 10/26/2019
** Description: Header File for course class
** Input: -
** Output: -
******************************************************/

#ifndef course_h
#define course_h
#include "functions.h"
#include <string>
// #include "university.h"
// #include "functions.h"
using namespace std;

class Course{
  //public:
  private:
    string name;
    string teacher;
    int current_enrollment;
    string* roster;
    schedule* course_time;
  public:
    //need to include accessors functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructor where appropriate
	Course();//constructor
	Course(string name, string teacher, string start_time, string end_time, string days, string term, string location);
	Course(const Course &); //copy constructor
	void set_name(string);
	void set_instructor(string);
	string get_instructor();
	string get_name();
	void set_current_enrollment(int);
	int get_current_enrollment();
	schedule* get_course_time();
    void change_course_time(schedule* course_time);
    void enroll_student(string new_student);
	void remove_student(int id);
	void resize_dynamic_string (string **arr, int new_size, int old_size);
	void create_roster(int number_of_students);
	void print_roster();
	void fill_courses(Course *);
	void printAllCourses(const Course *, int);
	void reduce_dynamic_string (int new_size, int old_size, string removed);
	string* get_roster();
	string get_days();
	string get_start_time();
	string get_end_time();
	string get_term();
	string get_location();
	void set_days(string);
	void set_start_time(string);
	void set_end_time(string);
	void set_term(string);
	void set_location(string);
	void set_roster(string*);
	void remove_student_course(string);
	void operator= (const Course &C);//ass operator ovld
	void print_course();
	void get_student(student *student_list);
	~Course(); //destructor
};

#endif