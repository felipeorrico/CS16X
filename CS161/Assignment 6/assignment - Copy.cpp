#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void loop_for_int (int &input, string message, int max, int min){//loops for int, useful when dealing with choices
	
	bool trigger = 0;

	do { //loop that checks for valid input
		if (trigger) {
			cout << "****************************************\n* ERROR - Please Input a Valid Coords. *\n****************************************\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;
		trigger = 1;	
	} while ( input < min || input > max);
	
}

int get_letter_number (string input){//gets input string and transforms the letter to a number
	 if (int(input[0]) < 97){
		 return int(input[0]) - 65;
	 }
	 else if(int(input[0]) >= 97){
		 return int(input[0]) - 97;
	 }
}
int get_number(string input){
	return int(input[2]) - 48; 
}
bool check_valid_input (string input){ //if input is valid returns false
	if (((input[0] >= 'a' && input[0] <= 'j')||(input[0] >= 'A' && input[0] <= 'J'))&& (input[1] == '-') && (input[2] >= '0' || input[2] <= '9')&& (input.length() == 3)){
		return false;
	}
	else
		return true;
}
void get_player_choice (string &input){//gets input from user for overall coordinates
	bool trigger = false;
	do {
		if (trigger){
			cout << "****************************************\n* ERROR - Please Input a Valid Coords. *\n****************************************\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << "Please input The Coordinates using X-#, Example: A-4 or B-9\n";
		cin >> input;
		trigger = check_valid_input(input);
	} while(trigger == true);
}
void ShowGrid(int matrix[][10]){//displays grid
	int lettercoords = 65;
	cout << "\n   0 1 2 3 4 5 6 7 8 9 \n_______________________" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << char(lettercoords) << "| ";
		lettercoords++;
		for (int j = 0; j < 10; j++){
			if (matrix [i][j] == 8){//display of hits working.
				
				cout << "\033[22;31mX\033[01;37m ";
				continue;
			}
			else if (matrix[i][j] == 7){
				cout << "M ";
				continue;
			}
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void initialize_matrix_10x10 (int matrix[][10]){//initializes a [10][10] matrix.
	for (int i = 0; i < 10; i++)//initializing matrix
	{
		for (int j = 0; j < 10; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
void initialize (int matrix_tries_player1[][10], int matrix_tries_player2[][10], int matrix_ships_player1[][10], int matrix_ships_player2[][10]){//initializs the grids
	initialize_matrix_10x10(matrix_tries_player1);
	initialize_matrix_10x10(matrix_tries_player2);
	initialize_matrix_10x10(matrix_ships_player1);
	initialize_matrix_10x10(matrix_ships_player2);
}
int get_ship_length(int ship_type){//gets the lenght of the ship by it's number and returns it
	if (ship_type == 1)
		return 5;
	else if (ship_type == 2)
		return 4;
	else if (ship_type == 3 || ship_type == 4)
		return 3;
	else if (ship_type == 5)
		return 2;
}
bool check_available_coord_verical (int matrix[][10], int y_coord_1, int x_coord_1, int y_coord_2, int x_coord_2){//checks if any of the numbers in between the endpoints is a ship
	for (int i = y_coord_1; i <= y_coord_2; i++){
		if (matrix [i][x_coord_1] >= 1 && matrix [i][x_coord_1] <= 5)
			return true;
		else
			continue;
	}
	return false;
}

bool check_available_coord_horizontal (int matrix[][10], int y_coord_1, int x_coord_1, int y_coord_2, int x_coord_2){//checks if any of the numbers in between the endpoints is a ship
	for (int i = y_coord_1; i <= y_coord_2; i++){
		if (matrix [y_coord_1][i] >= 1 && matrix [y_coord_1][i] <= 5)
			return true;
		else
			continue;
	}
	return false;
}

void update_endpoints_vertical (string &input, string &input_2,int &y_coord_1, int &x_coord_1, int &y_coord_2, int &x_coord_2 ){
	
	cout << "Please input the top endpoint: "<< endl;
	get_player_choice(input);
	y_coord_1 = get_letter_number(input);
	x_coord_1 = get_number(input);
	cout << "Y = " << y_coord_1<< " X = " << x_coord_1 << endl;	//test
	cout << "Please input the bottom endpoint: "<< endl;
	get_player_choice(input_2);
	y_coord_2 = get_letter_number(input_2);
	x_coord_2 = get_number(input_2);
	cout << "Y = " << y_coord_2<< " X = " << x_coord_2 << endl; //test
	
}

//gets the endpoints and sets them in the matrix - possibly add a way to get the endpoints to be stored in an array
void vertical_choice (string input, string input_2, int ship_type, int ship_length, int matrix[][10], int y_coord_1, int x_coord_1, int y_coord_2, int x_coord_2){ 
	bool trigger = false, error_trigger = false;
	cin.ignore(10, '\n');
	ShowGrid(matrix);//test
	cout << "Length = " << ship_length << endl; //test
	do {
		if (trigger){
			cout << "****************************************\n* ERROR - Please Input a Valid Coords. *\n****************************************\n";
			trigger = false;
			error_trigger = false;
		}
		update_endpoints_vertical(input, input_2, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
		error_trigger = check_available_coord_verical(matrix, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
		trigger = true;
	} while (x_coord_1 != x_coord_2 || (y_coord_2 - y_coord_1) != (ship_length-1) || error_trigger==true);
	for (int i = 0; i < ship_length; i++){
		matrix[i+y_coord_1][x_coord_1] = ship_type;
	}
	ShowGrid(matrix);//test	
}

void update_endpoints_horizontal (string &input, string &input_2,int &y_coord_1, int &x_coord_1, int &y_coord_2, int &x_coord_2 ){
	
	cout << "Please input the left endpoint: "<< endl;
	get_player_choice(input);
	y_coord_1 = get_letter_number(input);
	x_coord_1 = get_number(input);
	cout << "Y = " << y_coord_1<< " X = " << x_coord_1 << endl;	//test
	cout << "Please input the right endpoint: "<< endl;
	get_player_choice(input_2);
	y_coord_2 = get_letter_number(input_2);
	x_coord_2 = get_number(input_2);
	cout << "Y = " << y_coord_2<< " X = " << x_coord_2 << endl; //test
	
}
//gets the endpoints and sets them in the matrix - possibly add a way to get the endpoints to be stored in an array
void horizontal_choice (string input, string input_2, int ship_type, int ship_length, int matrix[][10], int y_coord_1, int x_coord_1, int y_coord_2, int x_coord_2){ 
	bool trigger = false, error_trigger = false;
	cin.ignore(10, '\n');
	ShowGrid(matrix);//test
	cout << "Length = " << ship_length << endl; //test
	do {
		if (trigger){
			cout << "****************************************\n* ERROR - Please Input a Valid Coords. *\n****************************************\n";
			trigger = false;
			error_trigger = false;
		}
		update_endpoints_horizontal(input, input_2, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
		error_trigger = check_available_coord_horizontal(matrix, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
		trigger = true;
	} while (y_coord_1 != y_coord_2 || (x_coord_2 - x_coord_1) != (ship_length-1) || error_trigger==true);
	for (int i = 0; i < ship_length; i++){
		matrix[y_coord_1][i+x_coord_1] = ship_type;
	}
	ShowGrid(matrix);//test	
}

void get_ship_endpoints (int ship_type, int matrix[][10]){//function to get endpoints of the chosen ship
	int v_or_h, ship_length = get_ship_length(ship_type), y_coord_1, x_coord_1, y_coord_2, x_coord_2;
	string input, input_2;
	cout << "Now placing Ship type " << ship_type << endl;
	loop_for_int(v_or_h, "Is the ship going to be placed on the vertical or horizontal?\n1-Vertical\n2-Horizontal\n", 2, 1);
	if (v_or_h == 1){
		vertical_choice (input,input_2, ship_type, ship_length, matrix, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
	}
	else if (v_or_h == 2){
		horizontal_choice (input,input_2, ship_type, ship_length, matrix, y_coord_1, x_coord_1, y_coord_2, x_coord_2);
	}
}
void get_ships_positions(int matrix[][10]) {//function to control ship placement
	int choice_loop = 5, ship_type = 0;
	string used_ships;
	bool trigger = false;
	do{
		if(trigger){
			cout << "***************************************\n* ERROR - Please Choose a valid Ship! *\n***************************************\n";
			cin.clear();
			cin.ignore(10, '\n');
			trigger = false;
		}
		
		loop_for_int(ship_type, "You Will Now choose where your ships will be placed.\nPlease Choose one of the Following:\n1-Aircraft Carrier\n2-Battleship\n3-Destroyer\n4-Submarine\n5-Patrol Boat\n", 5, 1);
		
		if (string::npos != used_ships.find_first_of(char(ship_type))){ //check if it works... this should check if you already chose that ship!
			trigger = true;
			continue;
		}
		get_ship_endpoints(ship_type, matrix); //get_ship_endpoints here - put function call - check works
		
		used_ships += char(ship_type);
		
		choice_loop --;
	} while (choice_loop > 0);	
}

void attack_to_8_7 (int y_attack2, int x_attack2, int matrix_tries[][10], int matrix_ships[][10]){

	if (matrix_ships[y_attack2][x_attack2] >= 1 && matrix_ships[y_attack2][x_attack2] <=5){//probably works
		cout << "Hit! Nice Job Capitan!\n";
		matrix_ships[y_attack2][x_attack2] = 8;
		matrix_tries[y_attack2][x_attack2] = 8;
	}
	else if (matrix_ships[y_attack2][x_attack2] == 0){//probably works
		cout << "Miss! Better Luck Next Time!\n";
		matrix_ships[y_attack2][x_attack2] = 7;
		matrix_tries[y_attack2][x_attack2] = 7;
	}
}

void print_destroyed_status(bool array[]){
	
	cout << "\n\nShips Destroyed so far:\n";
	if (array[0] == true)
		cout << "- Aircraft Carrier\n";
	if (array[1] == true)
		cout << "- Battleship\n";
	if (array[2] == true)
		cout << "- Destroyer\n";
	if (array[3] == true)
		cout << "- Submarine\n";
	if (array[4] == true)
		cout << "- Patrol Boat\n";
	if (array[0] == false && array[1] == false && array[2] == false && array[3] == false && array[4] == false)
		cout << "- None\n";
	cout << endl;
	
}

void attack (string input, int matrix_tries[][10], int matrix_ships[][10], bool carrier, bool battleship, bool destroyer, bool submarine, bool patrol){//this function will get the attack coordinate, check if is a hit or miss and update all the arrays to match.
	bool array_of_bools[5] = {carrier, battleship, destroyer, submarine, patrol};
	print_destroyed_status(array_of_bools);
	cout << "Attack time! Follow the steps to attack the Enemy!\n";
	bool trigger = 0;
	int y_attack2 = 0, x_attack2 = 0;
	do{
		if (trigger){
			cout << "This Attack coord is not valid!\n";
			cin.clear();
			cin.ignore(10, '\n');
		}
		get_player_choice(input);
		y_attack2 = get_letter_number(input); x_attack2 = get_number(input);
		trigger = 1;
	} while (matrix_ships[y_attack2][x_attack2] == 8 || matrix_ships[y_attack2][x_attack2] == 7);
	
	attack_to_8_7(y_attack2, x_attack2, matrix_tries, matrix_ships);
	cout << "Please Press ENTER to CONTINUE:";
	cin.clear();
	cin.ignore(10, '\n');
	cin.get();
}

void get_sunk_string(string &sunk, int counter_carrier , int counter_battleship, int counter_destroyer, int counter_submarine, int counter_patrol){//adds sunk ship to the string
	if (counter_carrier == 0)
		sunk += char(1);
	if (counter_battleship == 0)
		sunk += char(2);
	if (counter_destroyer == 0)
		sunk += char(3);
	if (counter_submarine == 0)
		sunk += char(4);
	if (counter_patrol == 0)
		sunk += char(5);
}

string check_sunk(int matrix[][10]){//check each number (ship types) and sees if any of them is missing - use counter and for loops. Put this function between user plays - returns string.
	
	int counter_carrier = 0, counter_battleship = 0, counter_destroyer = 0, counter_submarine = 0, counter_patrol = 0;
	string ships_sunk;
	for (int i = 0; i < 10; i++){
		
		for (int j = 0; j<10; j++){	//adding to the counter as the ships are found.	
			if (matrix[i][j] == 1)
				counter_carrier++;
			else if(matrix[i][j] == 2)
				counter_battleship++;
			else if(matrix[i][j] == 3)
				counter_destroyer++;
			else if(matrix[i][j] == 4)
				counter_submarine++;
			else if(matrix[i][j] == 5)
				counter_patrol++;
		}
		
	}
	get_sunk_string(ships_sunk, counter_carrier , counter_battleship, counter_destroyer, counter_submarine, counter_patrol);
	return ships_sunk;
}

void print_sunk_ships (string sunk_ships, bool &carrier, bool &battleship, bool &destroyer, bool &submarine, bool &patrol){//checks if can print and it can, it will.
	
	for (int i = 0; i < sunk_ships.length(); i++){
		
		if (int(sunk_ships[i]) == 1 && carrier == 0){
			cout << "Carrier Sunk!\n\n";
			carrier = 1;	
		}
		if (int(sunk_ships[i]) == 2 && battleship == 0){
			cout << "Battleship Sunk!\n\n";
			battleship = 1;	
		}
		if (int(sunk_ships[i]) == 3 && destroyer == 0){
			cout << "Destroyer Sunk!\n\n";
			destroyer = 1;
		}
		if (int(sunk_ships[i]) == 4 && submarine == 0){
			cout << "Submarine Sunk!\n\n";
			submarine = 1;
		}
		if (int(sunk_ships[i]) == 5 && patrol == 0){
			cout << "Patrol Boat Sunk!\n\n";
			patrol = 1;
		}
	}
}


string* get_names (int size){
	
	string *returned = new string[size];
	for (int i = 0; i < size; i++){
		cout << "Please input the name of player #" << i+1 << endl;
		cin >> returned[i];
	}
	return returned;
}

bool check_win(bool carrier1, bool battleship1, bool destroyer1, bool submarine1, bool patrol1, bool carrier2, bool battleship2, bool destroyer2, bool submarine2, bool patrol2, string player_name[]){
	if (carrier1 == 1 && battleship1 == 1 && destroyer1 == 1 && submarine1 == 1 && patrol1 == 1){ //add play checker - This player 1 wins
		cout << "Player " << player_name[1] << " wins!\nAll Ships from "<< player_name[0] << " were destroyed! Good Game!\n";
		return 1;
	}
	else if(carrier2 == 1 && battleship2 == 1 && destroyer2 == 1 && submarine2 == 1 && patrol2 == 1){
		cout << "Player " << player_name[0] << " wins!\nAll Ships from "<< player_name[1] << " were destroyed! Good Game!\n";
		return 1;
	}
	else
		return 0;
}



void game_2 (bool &check_wins, string input, bool &carrier_1, bool &battleship_1, bool &destroyer_1, bool &submarine_1, bool &patrol_1, bool &carrier_2, bool &battleship_2, bool &destroyer_2, bool &submarine_2, bool &patrol_2, string names[], int matrix_tries_player1[][10], int matrix_tries_player2[][10], int matrix_ships_player1[][10], int matrix_ships_player2[][10]){
	do {
		system("clear");
		cout << names[0] << " It is your turn to attack!\n\nYour Ships\n";
		ShowGrid(matrix_ships_player1);
		cout << "\nYour Tries\n";
		ShowGrid(matrix_tries_player1);
		attack(input, matrix_tries_player1, matrix_ships_player2, carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1);
		print_sunk_ships(check_sunk(matrix_ships_player2), carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2);
		check_wins = check_win(carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1, carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2, names);
		if (check_wins == 1)
			break;
		system("clear");
		cout << names[1] << " It is your turn to attack!\n\nYour Ships\n";
		ShowGrid(matrix_ships_player2);
		cout << "\nYour Tries\n";
		ShowGrid(matrix_tries_player2);
		attack(input, matrix_tries_player2, matrix_ships_player1, carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2);
		print_sunk_ships(check_sunk(matrix_ships_player1), carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1);
		check_wins = check_win(carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1, carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2, names);
		
	}while (check_wins == 0);
	
}

void print_last_standing(bool array[][5], string names[]){
	
	system("clear");
	for (int i = 0; i < 2; i++){
		cout << "Ships still standing for " << names[i] << ":\n";
		if (array[i][0] == false)
			cout << "- Aircraft Carrier\n";
		if (array[i][1] == false)
			cout << "- Battleship\n";
		if (array[i][2] == false)
			cout << "- Destroyer\n";
		if (array[i][3] == false)
			cout << "- Submarine\n";
		if (array[i][4] == false)
			cout << "- Patrol Boat\n";
		if (array[i][0] == true && array[i][1] == true && array[i][2] == true && array[i][3] == true && array[i][4] == true)
			cout << "- All Ships Destroyed\n";
		cout << endl;
	}
	
}
void game(){
	system("clear");
	bool carrier_1 = 0, battleship_1 = 0, destroyer_1 = 0, submarine_1 = 0, patrol_1 = 0, carrier_2 = 0, battleship_2 = 0, destroyer_2 = 0, submarine_2 = 0, patrol_2 = 0, check_wins = 0;
	string input;
	int matrix_tries_player1[10][10], matrix_tries_player2[10][10], matrix_ships_player1[10][10], matrix_ships_player2[10][10];
	
	initialize(matrix_tries_player1, matrix_tries_player2, matrix_ships_player1, matrix_ships_player2);
	// initialize(matrix_tries_player1, matrix_tries_player2, matrix_tries_player2, matrix_tries_player1); //tester
	
	string* name = get_names(2); //creating array and reassigning names to static
		string names[2];
		for (int i = 0; i < 2; i++){
			names[i] = name[i];
		}
		delete[] name;
	
	//start setting up ships here
	system("clear");
	cout <<names[0] << "\n";
	get_ships_positions(matrix_ships_player1); //getting updated array for player 1 with ships placed.
	system("clear");
	cout << names[1] << "\n";
	get_ships_positions(matrix_ships_player2); //getting updated array for player 2 with ships placed.
	system("clear");
	
	//testing stuff
	// for (int i = 0; i < 10; i++){
		// for (int j = 0; j < 10; j++){
			// if (i == 0 && j < 5)
				// matrix_ships_player2[j][i] = 1;
			// else if (i == 1 && j < 4)
				// matrix_ships_player2[j][i] = 2;
			// else if (i == 2 && j < 3)
				// matrix_ships_player2[j][i] = 3;
			// else if (i == 3 && j < 3)
				// matrix_ships_player2[j][i] = 4;
			// else if (i == 4 && j < 2)
				// matrix_ships_player2[j][i] = 5;
			// else {
				// matrix_ships_player2[j][i] = 0;
			// }
		// }
	// }
	// for (int i = 0; i < 10; i++){
		// for (int j = 0; j < 10; j++){
			// if (i == 0 && j < 5)
				// matrix_ships_player1[j][i] = 1;
			// else if (i == 1 && j < 4)
				// matrix_ships_player1[j][i] = 2;
			// else if (i == 2 && j < 3)
				// matrix_ships_player1[j][i] = 3;
			// else if (i == 3 && j < 3)
				// matrix_ships_player1[j][i] = 4;
			// else if (i == 4 && j < 2)
				// matrix_ships_player1[j][i] = 5;
			// else {
				// matrix_ships_player1[j][i] = 0;
			// }
		// }
	// }
	
	game_2(check_wins, input, carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1, carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2, names, matrix_tries_player1, matrix_tries_player2, matrix_ships_player1, matrix_ships_player2);
	bool array_of_bools[2][5] = {{carrier_1, battleship_1, destroyer_1, submarine_1, patrol_1},{carrier_2, battleship_2, destroyer_2, submarine_2, patrol_2}};
	print_last_standing(array_of_bools, names);
}

int main(){
	
	game();
	
	return 0;
}