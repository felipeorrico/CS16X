#ifndef pokedex_h
#define pokedex_h

#include <string>

using namespace std;

struct hunter {
	string name;
	int id;
	string password;
	string experience;
	float encounters;
};

struct monster {
	string name;
	string type;
	int level;
	int num_attacks;
	float avg_effectiveness;
	struct attack *a;
};

struct attack {
	string name;
	float effectiveness;
	string element;
};

monster * create_monsters(int);
void get_monster_data(monster *, int, ifstream &);
attack * create_attacks(int);
void get_attack_data(attack *, int, ifstream &);
void delete_info(hunter **, int, monster **, int);
int get_number_of (ifstream &);
int run_program(char **);
void reset_file(ifstream &);
void swap(int *, int *);
void pass_ID_to_array(int , monster *, int);
void bubbleSort(int *, int );   
void get_hunter_data (hunter *, int, ifstream &);
int get_login_credentials(int &, string &, hunter *, int , int &);
void get_average_eff(monster *, int);
void sort_by_element(monster *, int , bool, string, int );
void print_to_file_level(monster* , int, bool, string, int *);
void print_to_screen_level(monster*, int , bool , int *);
void print_to_screen_eff(monster*, int , bool , float *);
void print_to_file_eff(monster* , int, bool, string, float *);
void after_login_options(monster *, int, hunter *, int , bool);
int run_program_2(monster *, int , hunter *, int );
void loop_for_int (int &input, string message, int max, int min);
void check_for_repetition (string *, int);
bool fileExists(string);
void check_for_repetition_float (float *, int );
void swap_float(float *, float *);
void pass_float_to_array(float *, monster *, int); 
void bubbleSort_float(float *, int);
void print_by_ellement_screen(monster *, int, bool, string *);
void print_by_ellement_file (monster *, int, bool, string *, string);
void sort_by_level(monster *, int, bool, int , string);
void get_filename (string &);
void sort_by_eff(monster *, int, bool, int, string);
void run_program_3(monster*, ifstream &, int, ifstream &);
bool check_id (string, int &, bool &, int &);
void login_separation (bool &, int &, string &);

#endif








