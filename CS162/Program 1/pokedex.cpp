/******************************************************
** Program: pokedex.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 10/11/2019
** Description: This program is a place to store all the monster knowledge gathered by the monster hunters, sort it and print to a file.
** Input: file names in cmd line ./pokedex hunters.txt monsters.txt
** Output: File or screen with monsters sorted in correct way
******************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "pokedex.h"

using namespace std;


/*********************************************************************
** Function: fileExists
** Description: This function checks if a file with the input name exists and returns a boolean
** Parameters: fileName
** Pre-Conditions: assumes string input
** Post-Conditions: returns bool
*********************************************************************/ 
bool fileExists(string fileName)
{
    ifstream infile(fileName.c_str());
    return infile.good();
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

/*********************************************************************
** Function: check_for_repetition
** Description: Checks if a string contains repeated characters and erases the repeated ones.
** Parameters: string checked
** Pre-Conditions: Expected input of valid string
** Post-Conditions: Expected return of a valid string
*********************************************************************/ 
void check_for_repetition (int *arr, int number_of_monsters){
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = i+1; j < number_of_monsters-1; j++){
			if (arr[i] == arr[j]){
				arr[j] = 0;
			}
		}
	}
}
/*********************************************************************
** Function: check_for_repetition_float
** Description: Checks if a string contains repeated characters and erases the repeated ones.
** Parameters: string checked
** Pre-Conditions: Expected input of valid string
** Post-Conditions: Expected return of a valid string
*********************************************************************/ 
void check_for_repetition_float (float *arr, int number_of_monsters){
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = i+1; j < number_of_monsters-1; j++){
			if (arr[i] == arr[j]){
				arr[j] = 0;
			}
		}
	}
}

/*********************************************************************
** Function: swap
** Description: swaps the values of the two inputs
** Parameters: pointers to the two inputs
** Pre-Conditions: assumes dereferenced input
** Post-Conditions: updates values
*********************************************************************/ 
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

/*********************************************************************
** Function: swap_float
** Description: swaps the values of the two inputs
** Parameters: pointers to the two inputs
** Pre-Conditions: assumes dereferenced input
** Post-Conditions: updates values
*********************************************************************/ 
void swap_float(float *xp, float *yp)  
{  
    float temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

/*********************************************************************
** Function: pass_ID_to_array
** Description: this function sets the level values of the monsters into an array for sorting
** Parameters: array, monster db and number of monsters
** Pre-Conditions: assumes valid array and db are sent
** Post-Conditions: updates the array
*********************************************************************/ 
void pass_ID_to_array(int arr[], monster *db, int monster_number){
	for (int i = 0; i < monster_number; i++){
		arr[i] = db[i].level;
		
		//cout << arr[i] << endl;
	}
}

/*********************************************************************
** Function: pass_float_to_array
** Description: this function sets the level values of the monsters into an array for sorting
** Parameters: array, monster db and number of monsters
** Pre-Conditions: assumes valid array and db are sent
** Post-Conditions: updates the array
*********************************************************************/ 
void pass_float_to_array(float arr[], monster *db, int monster_number){
	for (int i = 0; i < monster_number; i++){
		arr[i] = db[i].avg_effectiveness;
		
		//cout << arr[i] << endl;
	}
}

/*********************************************************************
** Function: bubbleSort
** Description: Function found on stack overflow
** Parameters: array for sorting and number of monsters
** Pre-Conditions: assumes valid array passed
** Post-Conditions: updates array to sorted array
*********************************************************************/ 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 

 
/*********************************************************************
** Function: bubbleSort_float
** Description: Function found on stack overflow
** Parameters: array for sorting and number of monsters
** Pre-Conditions: assumes valid array passed
** Post-Conditions: updates array to sorted array
*********************************************************************/ 
void bubbleSort_float(float arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap_float(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 

/*********************************************************************
** Function: reset_file
** Description: moves the cursor in the file to the beginning
** Parameters: file
** Pre-Conditions: assumes valid file on input
** Post-Conditions: updates file
*********************************************************************/
void reset_file (ifstream &file){
	file.clear();
	file.seekg (0, ios::beg);
}

/*********************************************************************
** Function: create_monsters
** Description: dynamically allocate an array of monsters (of the requested size)
** Parameters: number of monsters
** Pre-Conditions: assumes number of monsters
** Post-Conditions: returns a dynamic array of monster structs
*********************************************************************/
monster * create_monsters(int a){ //This function will dynamically allocate an array of monsters (of the requested size)
		monster *monster_list = new monster [a];
		return monster_list;
}

/*********************************************************************
** Function: get_monster_data
** Description: Fill a monster struct with information that is read in from monsters.txt. Hint: "ifstream &" is a reference to a filestream object.
** Parameters: monster_list, number_of_monsters and file
** Pre-Conditions: assumes valid input
** Post-Conditions: updates monster struct
*********************************************************************/
void get_monster_data(monster *monster_list, int number, ifstream &file){ //This function will fill a monster struct with information that is read in from monsters.txt. Hint: "ifstream &" is a reference to a filestream object. You will need to create one and pass it into this function to read from the monsters.txt file.
	string dummyLine;
	for (int i = 0; i < number; i++){
		file >> monster_list[i].name >> monster_list[i].type >> monster_list[i].level >> monster_list[i].num_attacks;
		for (int j = 0; j <= monster_list[i].num_attacks; j++){
			getline(file, dummyLine);
			dummyLine = "";
		}
	}
}

/*********************************************************************
** Function: create_attacks
** Description: dynamically allocate an array of attacks (of the requested size)
** Parameters: number of attacks of a selected monster
** Pre-Conditions: assumes valid number of attacks
** Post-Conditions: returns dynamic arrays of attacks for that monster
*********************************************************************/ 
attack * create_attacks(int a){ //This function will dynamically allocate an array of attacks (of the requested size)
	attack *attack_list = new attack[a];
	return attack_list;
}

/*********************************************************************
** Function: get_attack_data
** Description: fill an attack struct with information that is read in from monsters.txt.
** Parameters: dynamic struct attack, number of attacks, file 
** Pre-Conditions: assumes valid inputs
** Post-Conditions: updates the dynamic struct of attacks
*********************************************************************/ 
void get_attack_data(attack *a, int num_attacks, ifstream &file){//This function will fill an attack struct with information that is read in from monsters.txt.
	for (int i=0; i < num_attacks; i++){
		file >> a[i].name >> a[i].effectiveness >> a[i].element;
	}
}

/*********************************************************************
** Function: get_hunter_data
** Description: gets hunter data from hunter file
** Parameters: dynamic struct hunter, number of hunters, file
** Pre-Conditions: assumes valid inputs
** Post-Conditions: updates hunter struct
*********************************************************************/
void get_hunter_data (hunter *hunter_list, int number, ifstream &file){
	
	for (int i = 0; i <= number; i++){
		if (file >> hunter_list[i].name >> hunter_list[i].id >> hunter_list[i].password >> hunter_list[i].experience >> hunter_list[i].encounters){
			continue;
		}
	}
	
	reset_file(file);
}

/*********************************************************************
** Function: delete_info
** Description: delete all the memory that was dynamically allocated.
** Parameters: hunter dynamic array of structs, monster dynamic array of structs and their sizes
** Pre-Conditions: assumes valid input
** Post-Conditions: deletes both arrays and sets pointers to null
*********************************************************************/
void delete_info(hunter **a, int d, monster **b, int c){
	delete[] *a;
	delete[] *b;
	a = NULL;
	b = NULL;
}

/*********************************************************************
** Function: get_number_of
** Description: gets the number from the top of the input file
** Parameters: file
** Pre-Conditions: assumes valid input
** Post-Conditions: returns number from file
*********************************************************************/ 
int get_number_of (ifstream &files){
	string trigger;
	int number;
	if (files.good()){
		getline(files, trigger); //getting the first line of the file to see how many hunters are there
		number = int(trigger[0]) - 48; //this is the amount of hunters in the file
		//cout << number << endl;
	}
	return number;
}

/*********************************************************************
** Function: check_id
** Description: checks if the hunter ID contains any invalid characters
** Parameters: string id, id number to update if valid, triggers and counters
** Pre-Conditions: assumes valid input
** Post-Conditions: updates ID or triggers to repeat
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
** Description: implements the first half of the login function
** Parameters: trigger, counter, string input
** Pre-Conditions: assumes valid input
** Post-Conditions: updates everything
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
** Description: main function that controls the login process
** Parameters: id, pw, hunter structs, number of hunters and the location of the user
** Pre-Conditions: assumes valid input
** Post-Conditions: updates id, password and user location of the user logging in
*********************************************************************/ 
int get_login_credentials(int &id, string &pw, hunter *hunter_list, int number_of_hunters, int &user_location){
	bool trigger = false;
	int counter = 0;
	string id_input;
	do{
		start: login_separation (trigger, counter, id_input);
		
		bool restart = check_id(id_input, id, trigger, counter);
		
		if (restart){goto start;}
		
		cout << "Password: ";
		
		cin >> pw;
		
		for (int i = 0; i < number_of_hunters; i++){
			if (id == hunter_list[i].id && pw == hunter_list[i].password){
				user_location = i;
				return 0;
			}
			else trigger = true;
		}
	} while (trigger == true && counter < 2);
	
	if (counter >= 2){
		return 1;
	} else 
		return 0;
}

/*********************************************************************
** Function: get_average_eff
** Description: gets the average attack effectiveness for each monster
** Parameters: monster structs and number of monsters
** Pre-Conditions: assumes valid inputs
** Post-Conditions: updates monster struct
*********************************************************************/ 
void get_average_eff(monster *monster_list, int number_of_monsters){
	int avg_counter;
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = 0; j < monster_list[i].num_attacks; j++){
			avg_counter += monster_list[i].a[j].effectiveness;
		}
		monster_list[i].avg_effectiveness = (avg_counter/monster_list[i].num_attacks);
		//monster_list[i].avg_effectiveness = (avg_counter/monster_list[i].num_attacks);
		avg_counter = 0;
	}
}

/*********************************************************************
** Function: print_by_ellement_screen
** Description: print selection to screen
** Parameters: list of monsters, number of monsters,. apprentice flag, array of element strings 
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to screen
*********************************************************************/ 
void print_by_ellement_screen(monster *monster_list, int number_of_monsters, bool flag, string *arr){
	system("clear");
	cout << "Printing attacks by Element: \n\n";
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < number_of_monsters; j++){
			for (int k = 0; k < monster_list[j].num_attacks; k++){
				if (arr[i] == monster_list[j].a[k].element){
					if (monster_list[j].a[k].effectiveness > 70 && flag == true){
						continue;
					}
					cout << monster_list[j].a[k].element << " "<< monster_list[j].a[k].name << " "<< monster_list[j].a[k].effectiveness << endl;	
				}	else continue;
			}
		}
	}
}

/*********************************************************************
** Function: print_by_ellement_file
** Description: print selection to file
** Parameters: list of monsters, number of monsters,. apprentice flag, array of element strings , name of file
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to file
*********************************************************************/ 
void print_by_ellement_file (monster *monster_list, int number_of_monsters, bool flag, string *arr, string filename){
	ofstream file(filename.c_str());
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < number_of_monsters; j++){
			for (int k = 0; k < monster_list[j].num_attacks; k++){
				if (arr[i] == monster_list[j].a[k].element){
					if (monster_list[j].a[k].effectiveness > 70 && flag == true){
						continue;
					}
					file << monster_list[j].a[k].element << " "<< monster_list[j].a[k].name << " "<< monster_list[j].a[k].effectiveness << endl;	
				}	else continue;
			}
		}
	}
	file.close();
	cout << "\nFile " << filename << " created!\n";
}

/*********************************************************************
** Function: sort_by_element
** Description: implements sorts by element
** Parameters: monster struct, number of monsters, apprentice flag, filename, print type
** Pre-Conditions: assumes valid inputs
** Post-Conditions: selects printing
*********************************************************************/ 
void sort_by_element(monster *db, int number_of_monsters, bool flag, string filename, int print_type){
	string element_array[5] = {"fire", "air", "water", "earth", "darkness"};
	if (print_type == 1){
		print_by_ellement_file(db, number_of_monsters, flag, element_array, filename);
	}
	else if (print_type == 2){
		print_by_ellement_screen(db, number_of_monsters, flag, element_array);
	}
}

/*********************************************************************
** Function: print_to_file_level
** Description: print selection to file
** Parameters: list of monsters, number of monsters,. apprentice flag, array of levels and name of the file
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to file
*********************************************************************/ 
void print_to_file_level(monster* monster_list, int number_of_monsters, bool flag, string filename, int *arr){
	ofstream file(filename.c_str());
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = 0; j < number_of_monsters; j++){
			if (arr[i] == monster_list[j].level){
				if ((monster_list[j].level > 20 || monster_list[j].avg_effectiveness > 50) && flag == true){
					continue;
				}
				file << monster_list[j].level << " " << monster_list[j].name << " " << monster_list[j].type << "\n";
			} else continue;
		}
	}
	file.close();
	cout << "File " << filename << " created!\n";
}

/*********************************************************************
** Function: print_to_screen_level
** Description: print selection to screen
** Parameters: list of monsters, number of monsters,. apprentice flag, array of levels
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to screen
*********************************************************************/ 
void print_to_screen_level(monster* monster_list, int number_of_monsters, bool flag, int *arr){
	system("clear");
	cout << "Printing monsters by Level: \n\n";
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = 0; j < number_of_monsters; j++){
			if (arr[i] == monster_list[j].level){
				if ((monster_list[j].level > 20 || monster_list[j].avg_effectiveness > 50) && flag == true){
					continue;
				}
				cout << monster_list[j].level << " " << monster_list[j].name << " " << monster_list[j].type << "\n";
			} else continue;
		}
	}
}

/*********************************************************************
** Function: print_to_screen_eff
** Description: print selection to file
** Parameters: list of monsters, number of monsters,. apprentice flag, array of averages
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to screen
*********************************************************************/ 
void print_to_screen_eff(monster* monster_list, int number_of_monsters, bool flag, float *arr){
	system("clear");
	cout << "Printing monsters by Average Effectiveness: \n\n";
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = 0; j < number_of_monsters; j++){
			if (arr[i] == monster_list[j].avg_effectiveness){
				if ((monster_list[j].level > 20 || monster_list[j].avg_effectiveness > 50) && flag == true){
					continue;
				}
				cout << monster_list[j].avg_effectiveness<< " "<<monster_list[j].name << " " << monster_list[j].type << " " << monster_list[j].level << " " << monster_list[j].num_attacks << "\n";
			} else continue;
		}
	}
}

/*********************************************************************
** Function: print_to_file_eff
** Description: print selection to file
** Parameters: list of monsters, number of monsters, apprentice flag, array of levels and name of the file
** Pre-Conditions: assumes valid inputs
** Post-Conditions: prints to file
*********************************************************************/ 
void print_to_file_eff(monster* monster_list, int number_of_monsters, bool flag, string filename, float *arr){
	ofstream file(filename.c_str());
	for (int i = 0; i < number_of_monsters; i++){
		for (int j = 0; j < number_of_monsters; j++){
			if (arr[i] == monster_list[j].avg_effectiveness){
				if ((monster_list[j].level > 20 || monster_list[j].avg_effectiveness > 50) && flag == true){
					continue;
				}
				file << monster_list[j].avg_effectiveness<< " "<<monster_list[j].name << " " << monster_list[j].type << " " << monster_list[j].level << " " << monster_list[j].num_attacks << "\n";
			} else continue;
		}
	}
	file.close();
	cout << "File " << filename << " created!\n";
}

/*********************************************************************
** Function: sort_by_level
** Description: sorts monsters by level
** Parameters: monster structs, number_of_monsters, apprentice flag,  type of print and filename
** Pre-Conditions: assumes valid input
** Post-Conditions: selects printing
*********************************************************************/
void sort_by_level(monster *monster_list, int number_of_monsters, bool flag, int type_of_print, string filename){
	int arr[number_of_monsters];
	pass_ID_to_array(arr, monster_list, number_of_monsters);
	bubbleSort(arr, number_of_monsters);
	check_for_repetition(arr, number_of_monsters);
	if (type_of_print == 1){
		print_to_file_level(monster_list, number_of_monsters, flag, filename, arr);
	}
	else if (type_of_print == 2){
		print_to_screen_level(monster_list, number_of_monsters, flag, arr);
	}
}

/*********************************************************************
** Function: get_filename
** Description: gets the filename of the print file
** Parameters: filename
** Pre-Conditions: assumes valid input
** Post-Conditions: updates string filename
*********************************************************************/
void get_filename (string &filename){
	bool filename_check = false;
	do {
		if (filename_check){
			cout << "\nThis file already exists! Please choose another Filename.\n";
			filename_check = false;
		}
		cout << "\n\nPlease Choose a Filename (Do not include spaces or .txt): ";
		cin >> filename;
		filename += ".txt";
		filename_check = fileExists(filename);
	} while (filename_check == true);
}

/*********************************************************************
** Function: sort_by_eff
** Description: sorts each monster by average efficiency
** Parameters: monster structs, number of monsters, apprentice flag, type of print and filename
** Pre-Conditions: assumes valid input	
** Post-Conditions: sorts and selects printing
*********************************************************************/
void sort_by_eff(monster *monster_list, int number_of_monsters, bool flag, int type_of_print, string filename){
	float arr[number_of_monsters];
	pass_float_to_array(arr, monster_list, number_of_monsters);
	bubbleSort_float(arr, number_of_monsters);
	check_for_repetition_float(arr, number_of_monsters);
	if (type_of_print == 1){
		print_to_file_eff(monster_list, number_of_monsters, flag, filename, arr);
		//print_to_screen_eff(monster_list, number_of_monsters, flag, arr);
	}
	else if (type_of_print == 2){
		print_to_screen_eff(monster_list, number_of_monsters, flag, arr);
	}
}

/*********************************************************************
** Function: after_login_options
** Description: gives the options to the user after login is authenticated 
** Parameters: monster_list, number_of_monsters, hunter struct, hunter location and apprentice flag
** Pre-Conditions: assumes valid input_iterator
** Post-Conditions: gives options to user
*********************************************************************/
void after_login_options(monster *monster_list, int number_of_monsters, hunter *hunter_list, int user_location, bool flag){
	system("clear");
	string filename;
	
	cout << "Welcome " << hunter_list[user_location].name << "!\n\n - ID: " << hunter_list[user_location].id << "\n - Level: " << hunter_list[user_location].experience << "\n - Encounters: " << hunter_list[user_location].encounters << endl;
	
	int choice = 0, type_of_print = 0;
	
	loop_for_int(choice, "\nPlease choose the way you want to sort:\n (1) Sort monsters by level\n (2) Sort attacks by element\n (3) Sort by average attack effectiveness\n (4) QUIT\n\nChoice: ", 4, 1);
	if (choice == 4){goto end;}
	
	loop_for_int(type_of_print, "\n\nPlease Choose The Medium of output:\n (1) File\n (2) Screen\n\nChoice: ", 2, 1);
	
	if (type_of_print == 1){
		get_filename(filename);
	}
	switch (choice){
		case 1: sort_by_level(monster_list, number_of_monsters, flag, type_of_print, filename);
				break;
		case 2: sort_by_element(monster_list, number_of_monsters, flag, filename, type_of_print);
				break;
		case 3: sort_by_eff(monster_list, number_of_monsters, flag, type_of_print, filename);
				break;
	}
	end:;
}

/*********************************************************************
** Function: run_program_2
** Description: helps run_program tun the program
** Parameters: monster struct, number of monsters, hunter struct and number of hunters
** Pre-Conditions: assumes valid input
** Post-Conditions: continues run_program function
*********************************************************************/
int run_program_2(monster *monster_list, int number_of_monsters, hunter *hunter_list, int number_of_hunters){
	
	get_average_eff(monster_list, number_of_monsters);
	
	//monster debug
	// for (int i = 0; i < number_of_monsters; i++){
		// cout << monster_list[i].name << ", "<< monster_list[i].type << ", "<< monster_list[i].level << ", "<< monster_list[i].num_attacks << ", " << monster_list[i].avg_effectiveness << endl;
		// for (int j = 0; j < monster_list[i].num_attacks; j++){
			// cout << "- " <<monster_list[i].a[j].name << ", "<< monster_list[i].a[j].effectiveness << ", "<< monster_list[i].a[j].element << endl;
		// }
	// }
	
	//login stuff starts here!
	int id_input, user_location, login = 0, end_choice;
	string pw_input;
	login = get_login_credentials(id_input, pw_input, hunter_list, number_of_hunters, user_location);
	if (login == 1){
		for (int i = 0; i < number_of_monsters; i++){
			delete[] monster_list[i].a;
			monster_list[i].a = NULL;
		}
		delete_info(&hunter_list, number_of_hunters, &monster_list, number_of_monsters);
		return 4;
	}
	bool flag = false; //flags if the user is apprentice
	if (hunter_list[user_location].experience == "Apprentice") 
		flag = true;
	//After Login Options
	do {
		after_login_options(monster_list, number_of_monsters, hunter_list, user_location, flag);
		loop_for_int(end_choice, "\n\nWould you like to perform any other operation?\n (1) Yes\n (2) No\n\n Choice: ", 2, 1);
	} while (end_choice == 1);
	//after_login_options(monster_list, number_of_monsters, hunter_list, user_location, flag);
	
	for (int i = 0; i < number_of_monsters; i++){
		delete[] monster_list[i].a;
		monster_list[i].a = NULL;
	}
	delete_info(&hunter_list, number_of_hunters, &monster_list, number_of_monsters);
	
	return 0;
}

/*********************************************************************
** Function: run_program_3
** Description: helps run_program tun the program
** Parameters: monster struct, number of monsters, hunter struct and number of hunters, and hunter and monster files.
** Pre-Conditions: assumes valid input
** Post-Conditions: continues run_program function
*********************************************************************/
void run_program_3(monster* monster_list, ifstream &monster_file, int number_of_monsters, ifstream &hunter_file){
	reset_file(monster_file);
	string dummyLine;
	
	for (int i = 0; i < 2; i++){
		getline(monster_file, dummyLine);
		dummyLine = "";
	}
		
	for (int i = 0; i < number_of_monsters; i++){
		
		monster_list[i].a = create_attacks(monster_list[i].num_attacks);
		
		get_attack_data(monster_list[i].a, monster_list[i].num_attacks, monster_file);
		
		for (int i = 0; i <=1; i++){
			
			getline(monster_file, dummyLine);
			
			dummyLine = "";
		}
		
	}
	hunter_file.close();
	monster_file.close();
}

/*********************************************************************
** Function: run_program
** Description: entire implementation of program runs form here "main" function
** Parameters: input from command line
** Pre-Conditions: assumes valid inputs
** Post-Conditions: runs the program
*********************************************************************/ 
int run_program(char* cmdb[]){ //break this function into smaller ones
	
	ifstream hunter_file(cmdb[1]);
	ifstream monster_file(cmdb[2]);
	if (monster_file.good() && hunter_file.good()){
		
		int number_of_hunters = get_number_of(hunter_file), number_of_monsters = get_number_of(monster_file);
		
		system("clear");
		cout << "Welcome! Please Login to Access the Data!\n"<<"Hunters Loaded: " << number_of_hunters << ", Monsters Loaded: " << number_of_monsters << "\n\n\n";
		
		hunter *hunter_list = new hunter[number_of_hunters];
		
		get_hunter_data(hunter_list, number_of_hunters, hunter_file);
		
		monster *monster_list = create_monsters(number_of_monsters);
		
		get_monster_data(monster_list, number_of_monsters, monster_file);
		
		run_program_3(monster_list, monster_file, number_of_monsters, hunter_file);
		int run2 = run_program_2(monster_list, number_of_monsters, hunter_list, number_of_hunters);
		if (run2 == 4){
			return 4;
		}
	} 
	else if (monster_file.good() && !hunter_file.good()) {
		return 1;
	}
	else if (!monster_file.good() && hunter_file.good()){
		return 2;
	}
	else if (!monster_file.good() && !hunter_file.good()){
		return 3;
	}
	return 0;
}

