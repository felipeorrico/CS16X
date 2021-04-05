/******************************************************
** Program: functions.h
** Date: 10/26/2019
** Description: header file for functions 
******************************************************/

#ifndef functions_h
#define functions_h
#include <string>

using namespace std;

struct teacher {
	int id;
	string password;
	string first_name;
	string last_name;
};

struct studentCourses{
	string name;
	string term;
};

struct student {
	string id;
	string name;
	int number_of_enrolled_courses;
	studentCourses *enrolled;
};

struct course_hold{
	string name;
	string start_time;
	string term;
};


struct schedule{
  string days;
  string start_time;
  string end_time;
  string term;
  string location;
};

int count_lines(ifstream &);
int get_info_from_file(int &, teacher *, int);
void run();
void reset_file (ifstream &);
void waste_line(ifstream &);
int get_login_credentials(int &, string &,  teacher *, int , int &);
void login_separation (bool &, int &, string &);
bool check_id (string, int &, bool &, int &);
void loop_for_int (int &, string, int, int);
void check_for_repetition (string *, int);
int get_number_of_students();

#endif