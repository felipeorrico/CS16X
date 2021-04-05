/******************************************************
** Program: university.h
** Date: 10/26/2019
** Description: Header file for University class
** Input: -
** Output: -
******************************************************/

#ifndef university_h


#define university_h
#include <string>
#include "functions.h"
using namespace std;

class University{
  private:
    string name;
    string address;
    string current_term;
    teacher* teachers;
    int num_courses;
    Course* courses;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
	University();
	University(const University&);
	string get_name();
    Course *search_courses_by_term(string term);
	Course *search_courses_by_term_2(string term, Course*, int);
    Course *search_courses_by_times(string* times, int num_times);
    void add_to_catalog(Course course_to_add);
    void remove_from_catalog(int index_of_course);
	University& operator= (const University &U);
	teacher* get_teachers();
	int get_teacher_number();
	student *get_student(student *student_list);
	void after_login_teacher(teacher *, int);
	void printCourses() const;
	string get_term();
	void printSorted_1 (Course *list, int num);
	int get_num_courses_term(string term);
	void printSorted_2 (Course *sorted, string *times,int num, string term_chosen, int);
	string *time_sort_term(Course *sorted, string *times, int num_times, int num_sorted);
	void printSorted_3 (Course *sorted);
	int get_num_courses_time(Course *yo);
	void printSorted_4 (Course *sorted, int num, string term);
	void edit_courses();
	void erase_file(string);
	void add_a_course();
	void get_new_course_info (string &, string &, string &, string &, string &, string &, string &);
	void edit_a_course();
	bool edit_remove_add();
	int get_course_index(string course_name, string course_term, string course_teacher);
	void DeleteEmptyLines(const string &FilePath);
	void changeCourseInfo(int index, int);
	void theifs (int index, int choice);
	void removeStudent(int);
	void enrollStudent(int index);
	void enrollmentUPDT();
	void after_login_student(string, string);
	void reg_student(string name, string id);
	void student_separation_choice2(string , string);
	void student_separation_choice1(string , string);
	void teacher_separation_choice1();
	void teacher_separation_choice2();
	~University();
};




#endif