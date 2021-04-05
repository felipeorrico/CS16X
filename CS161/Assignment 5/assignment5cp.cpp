/******************************************************************************
 * Program: Assignment5cp.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Program that calculates the amount of reimbursement one or more people get for a business trip.
 * Inputs: any numbers for values or double for time
 * Output: The status and the request for input
 * First Version: 05/19/2019
 * This Version: 05/25/2019
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*********************************************************************
** Function: loop_for_double
** Description: Is a loop that checks for valid input and updates the variable
** Parameters: double input, string message, double min and max
** Pre-Conditions: expected double as input 
** Post-Conditions: expected update of double
*********************************************************************/ 
void loop_for_double (double &input, string message, double min, double max) { //loops and asks for input while is not valid
		
	bool trigger = false;
	
	do {
		if (trigger){
			cout << "Your input is not valid. Please input again: " << endl;
			cin.clear(); //clear input in case of char being input instead of int
			cin.ignore(10, '\n');
			trigger = false;
		}
		
		cout << message;
		cin >> input;
		cout << endl;
		if (cin.fail() || (input < min)||(input > max)){
			trigger = true;
		}	
		
	} while (trigger == true);
}

/*********************************************************************
** Function: update_total
** Description: Updates total expense and reimbursement 
** Parameters: floats, total_expense, total_reimbursement, expense_to_add and reimbursement_to_add
** Pre-Conditions: expected input of floats
** Post-Conditions: expected updated values
*********************************************************************/ 
void update_total (float &total_expense, float &total_reimbursement, float expense_to_add, float reimbursement_to_add){
	total_expense += expense_to_add;
	total_reimbursement += reimbursement_to_add;
}

/*********************************************************************
** Function: get_if_meal
** Description: checks if the meals have the correct price or not
** Parameters: doubles meal_expense and meal_expense_copy, int days_of_trip, int j for counting and double meal_reimbursement
** Pre-Conditions: expected valid int and double input
** Post-Conditions: updates the variables accordingly
*********************************************************************/ 
void get_if_meal (double &meal_expense, double &meal_expense_copy, int days_of_trip, int j, double &meal_reimbursement){
	
	//checking if amunt spent on meal is fully reimbursed or not
	if (meal_expense_copy > 09.00 && j ==0){
		meal_expense += meal_expense_copy;
		meal_reimbursement += 09.00;
	}
	else if (meal_expense_copy <= 09.00 && j==0) {
		meal_expense += meal_expense_copy;
		meal_reimbursement += meal_expense_copy;
	}
	else if (meal_expense_copy > 12.00 && j ==1) {
		meal_expense += meal_expense_copy;
		meal_reimbursement += 12.00;
	}
	else if (meal_expense_copy <= 12.0 && j==1){
		meal_expense += meal_expense_copy;
		meal_reimbursement += meal_expense_copy;
	}
	else if (meal_expense_copy > 16.00 && j ==2) {
		meal_expense += meal_expense_copy;
		meal_reimbursement += 16.00;
	}
	else if (meal_expense_copy <= 16.0 && j==2){
		meal_expense += meal_expense_copy;
		meal_reimbursement += meal_expense_copy;
	}
	
}

/*********************************************************************
** Function: get_firs_day_meal
** Description: gets the meal for the first day according to specifications
** Parameters: days of trip, departure and arrival times, meal expense, meal reimbursement, i for the loop, breaker to break the loop, meal expense copy
** Pre-Conditions: expected valid inputs			
** Post-Conditions: updating the inputs accordingly
*********************************************************************/ 
void get_first_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, int i, bool &breaker, double &meal_expense_copy){
	
	if (i == 1 && departure_time <= 07.00){ //checks of meal is allowed (this and next 2 if statements);
		for (int j = 0; j < 3; j++){
			cout << "Meal " << j+1<< ": ";
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == 1 && (departure_time > 07.00 && departure_time <= 12.00)){
		for (int j = 1; j < 3; j++){
			cout << "Meal 1 is not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == 1 && (departure_time > 12.00 && departure_time <= 18.00)){
		for (int j = 2; j < 3; j++){
			cout << "Meals 1 and 2 are not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	meal_expense_copy = 0;
}

/*********************************************************************
** Function: get_last_day_meal
** Description: gets the meals for the ls day of the trip if applicable
** Parameters: days of trip, departure and arrival times, meal expense, meal reimbursement, i for the loop, breaker to break the loop, meal expense copy
** Pre-Conditions: expected valid inputs			
** Post-Conditions: updating the inputs accordingly
*********************************************************************/ 
void get_last_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, int i, bool &breaker, double &meal_expense_copy){
	
	if (i == days_of_trip && arrival_time >= 19.00){//checks if meal starts on morning
		for (int j = 0; j < 3; j++){
			cout << "Meal " << j+1<< ": ";
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == days_of_trip && (arrival_time >= 13.00 && arrival_time < 19.00)){//check if meal starts on lunch
		for (int j = 0; j < 2; j++){
			cout << "Meal 3 is not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == days_of_trip && (arrival_time >= 08.00 && arrival_time < 13.00)){//check if meal starts on dinner
		for (int j = 0; j < 1; j++){
			cout << "Meal 2 and 3 are not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	meal_expense_copy = 0;
}

/*********************************************************************
** Function: get_other_day_meal
** Description: gets the meal for other than first and last days
** Parameters: days of trip, departure time, arrival time, meal expense, meal reimbursement
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_other_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, double &meal_expense_copy){
	
	for (int j = 1; j <= 3; j++){//loops for every other day meals
	
		cout << "Meal " << j << ": ";
		loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99);
		get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
		
		meal_expense_copy = 0; //reset for next loop

	}
}

/*********************************************************************
** Function: meal_fee
** Description: gets the total meal fee for the trip
** Parameters: days of trip, departure time, arrival time, meal_expense, meal reimbursement
** Pre-Conditions: expected valid inputs	
** Post-Conditions: updated inputs
*********************************************************************/ 
void meal_fee (int days_of_trip, double departure_time, double arrival_time, double* meal_expense, double* meal_reimbursement){
	
	bool breaker = false;
	double meal_expense_copy;
	for (int i = 1; i <= days_of_trip; i++){
		breaker = false;
		cout << "\n\nYou Will now input the value spent for each meal of day " << i << ". \nPlease use the following format: XX.XX . \nMeal 1 - Breakfast, Meal 2 - Lunch, Meal 3 - Dinner\n";
		if (departure_time > 18.00 && i == 1){ //checks if the first day meals are allowed
			cout << "\nNone of the meals from the first day of the trip are allowed as expense.\n";
			continue;
		}
		get_first_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, i, breaker, meal_expense_copy);
		if (breaker == true)
			continue;
		
		if (arrival_time < 08.00 && i == days_of_trip){ //checks if last day of trip is applicable
			cout << "\nNone of the meals from the last day of the trip are allowed as expense.\n";
			continue;
		}
		get_last_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, i, breaker, meal_expense_copy);
		if (breaker == true)
			continue;
		if (i != 1 && i != days_of_trip){//every other day applicable
			get_other_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, meal_expense_copy);
		}
		breaker = false;
		
	}	
	
}

/*********************************************************************
** Function: get_days
** Description: gets the days of trip
** Parameters: days of trip	
** Pre-Conditions: expected valid in inputs
** Post-Conditions: updated input
*********************************************************************/ 
void get_days (int &days_of_trip){ //get days of the trip
	
	bool trigger = false;
	do {
		if (trigger){
			cout << "Your input is not valid. Please input again: " << endl;
			cin.clear(); //clear input in case of char being input instead of int
			cin.ignore(10, '\n');
			trigger = false;
		}
		
		cout << "Please input the number of days of your trip: ";
		cin >> days_of_trip;
		cout << endl;
		if (cin.fail() || days_of_trip < 1){
			trigger = true;
		}	
		
	} while (trigger == true);
	//system ("clear");
}

/*********************************************************************
** Function: loop_for_float
** Description: Is a loop that checks for valid input and updates the variable
** Parameters: float input, string message
** Pre-Conditions: expected float as input 
** Post-Conditions: expected update of float
*********************************************************************/ 
void loop_for_float (float &input, string message) { //loop for all purposes
	
	bool trigger = false;
	
	do {
		if (trigger){
			cout << "Your input is not valid. Please input again: " << endl;
			cin.clear(); //clear input in case of char being input instead of int
			cin.ignore(10, '\n');
			trigger = false;
		}
		
		cout << message;
		cin >> input;
		cout << endl;
		if (cin.fail() || input < 00.00){
			trigger = true;
		}	
		
	} while (trigger == true);
	
}

/*********************************************************************
** Function: trip_time
** Description: gets the time or arrival and departure
** Parameters: departure time and arrival time
** Pre-Conditions: expected valid double input
** Post-Conditions: updated input
*********************************************************************/ 
void trip_time (double &departure_time, double &arrival_time){ //updates the departure and arrival times - working
	
	string message_departure = "Please input the time of departure on the format XX.XX : ";
	string message_arrival = "Please input the time of arrival on the format XX.XX : ";
	loop_for_double(departure_time, message_departure, 00.00, 23.59);
	loop_for_double(arrival_time, message_arrival, 00.00, 23.59);
	
}

/*********************************************************************
** Function: get_fare
** Description: gets the airfare and registration fee part of the expense
** Parameters: airfare, registration fees and total reimbursement
** Pre-Conditions: expected valid input
** Post-Conditions: updated output
*********************************************************************/ 
void get_fare (float &airfare, float &registration_fees, float &total_reimbursement){ //gets registration fees and air fares - working
	
	string message_airfare = "Please enter the total amount of airfare, in $: ";
	string message_registration = "Please enter total conference or seminar registration fees, in $: ";
	loop_for_float(airfare, message_airfare);
	loop_for_float(registration_fees, message_registration);
	total_reimbursement += registration_fees + airfare;
	
}

/*********************************************************************
** Function: loop_for_int
** Description: Is a loop that checks for valid input and updates the variable
** Parameters: int input, string message, int min and max
** Pre-Conditions: expected int as input 
** Post-Conditions: expected update of int
*********************************************************************/ 
void loop_for_int (int &input, string message, int max, int min){
	
	bool trigger = 0;
	int car_choice; 
	do { //loop that checks for valid input
		if (trigger) {
			cout << "Please input a valid number: " << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << message;
		cin >> input;
		trigger = 1;	
	} while ( input < min || input > max);
	
}

/*********************************************************************
** Function: get_taxi_fare
** Description: gets the amount of expense if the person uses taxi
** Parameters: car fees, days , car reimbursement
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_taxi_fare (float &car_fees, int days_of_trip, float &car_reimbursement) { //taxi fee per day
	
	float value;
	for (int i=1; i <= days_of_trip; i++){
		
		cout << "Day " << i << endl;
		loop_for_float(value, "Please input how much you spent on the taxi: ");
		car_fees += value;
		if (value > 10){
			car_reimbursement += 10;
		}
		else if (value <= 10 ){
			car_reimbursement += value;
		}
		value = 0;
		
	}
	
}

/*********************************************************************
** Function: get_final_car_fee
** Description: gets the final fee per mile driven of used car
** Parameters: car fees, type, miles driven , days of trip and reimbursement
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_final_car_fee (float &car_fees, int car_type, float miles_driven, int days_of_trip, float &car_reimbursement) { 
	
	if (car_type == 1) {
		car_fees += (20 * days_of_trip) + (0.24 * miles_driven);
	}
	else if (car_type == 2){
		car_fees += (25 * days_of_trip) + (0.27 * miles_driven);
	}
	else if (car_type == 3){
		car_fees += (30 * days_of_trip) + (0.32 * miles_driven);
	}
	else if (car_type == 4){
		car_fees += (50 * days_of_trip) + (0.45 * miles_driven);
	}
	car_reimbursement += car_fees;
}

/*********************************************************************
** Function: get_parking
** Description: gets the parking for each day with the car
** Parameters: car reimbursement days_of_trip and car_fees
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_parking (float &car_reimbursement, int days_of_trip,float &car_fees) { //gets the parking stuff - Working
	
	float value;
	for (int i=1; i <= days_of_trip; i++){ //loops for each day getting parking
		
		cout << "Day " << i << endl;
		loop_for_float(value, "Please input how much you spent on parking: ");
		car_fees += value;
		if (value > 6){
			car_reimbursement += 6;
		}
		else if (value <= 6){
			car_reimbursement += value;
		}
		value = 0;
		
		
	}
	
}

/*********************************************************************
** Function: get_car
** Description: governs adjacent car functions and updates values for car
** Parameters:car fees, days of trip, car reimbursement, total_reimbursement
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_car (float &car_fees, int days_of_trip, float &car_reimbursement, float &total_reimbursement){ //gets all the values for the car - Working
	
	int car_choice, car_type;
	float miles_driven;
	loop_for_int(car_choice, "Did you 1: rent a car or 2: use taxi for your trip? Enter 1 or 2: ", 2, 1);
	if (car_choice == 1) {//for car
		loop_for_int(car_type, "Please choose Between the following types of vehicle:\n 1. Sedan\n 2. SUV\n 3. Van\n 4. Convertible\n Enter the type of car you rented: ", 4, 1);
		loop_for_float(miles_driven, "Please input the total miles driven: ");
		get_final_car_fee(car_fees, car_type, miles_driven, days_of_trip, car_reimbursement);
		get_parking(car_reimbursement, days_of_trip, car_fees);
	}
	else if (car_choice == 2){//for taxi
		get_taxi_fare(car_fees, days_of_trip, car_reimbursement);
	}
	total_reimbursement += car_reimbursement;
	//system ("clear");
}

/*********************************************************************
** Function: get_hotel
** Description: gets hotel fees for each day of trip if trip is greater than 1 day
** Parameters: days of trip, hotel_fees, hotel reimbursement, total_reimbursement
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void get_hotel (int days_of_trip, float &hotel_fees, float &hotel_reimbursement, float &total_reimbursement){
	
	float hotel_fees_copy;
	cout << "You will now enter the amount of money spent on Hotel fees per day of the trip: \n";
	for (int i = 0; i < days_of_trip; i++){ //loop to get hotel fees 
		if (days_of_trip == 1){//1 day trip break
			hotel_fees = 0;
			hotel_reimbursement =0;
			cout << "This trip is too short for you to stay in a hotel\n"<< endl;
			break;
		}
		cout << "Day " << i + 1 << endl;
		loop_for_float(hotel_fees_copy, "Please Input the Hotel Fees for this day: ");
		if (hotel_fees_copy <= 90){//checking for value of hotel fee
			hotel_fees += hotel_fees_copy;
			hotel_reimbursement += hotel_fees_copy;
		}
		else if (hotel_fees_copy > 90){
			hotel_fees += hotel_fees_copy;
			hotel_reimbursement += 90;
		}
		
	}
	total_reimbursement += hotel_reimbursement;
	
	
}

/*********************************************************************
** Function: report_status
** Description: reports status of the inputs
** Parameters: all of them
** Pre-Conditions: expected valid inputs
** Post-Conditions: cout everything
*********************************************************************/ 
void report_status (int days_of_trip, double departure_time, double arrival_time, double meal_expense, double meal_reimbursement, float total_expense, float total_reimbursement, float expense_to_add, float reimbursement_to_add, float airfare,float registration_fees, float car_fees, float car_reimbursement, float hotel_fees, float hotel_reimbursement){
	
	cout << "Days of Trip: "<< days_of_trip <<  "\n\n";
	cout << "Arrival time: " << arrival_time << " Departure time: " << departure_time << "\n\n";
	cout << "Your total airfare is: "<< airfare <<  "\n\n";
	cout << "Your total registration_fees is: "<< registration_fees <<  "\n\n";
	cout << "Your total car fees are: "<< car_fees <<  "\n\n";
	cout << "Your total car reimbursement is: " << car_reimbursement <<  "\n\n";
	cout << "Total hotel expense: "<< hotel_fees <<  "\n\n";
	cout << "Total hotel reimbursement: "<< hotel_reimbursement<<  "\n\n";
	cout << "Total meal fees: " << meal_expense << "\n\n";
	cout << "Total meal Reimbursement: " << meal_reimbursement <<  "\n\n";
	cout << "Total expense so far: " << total_expense <<  "\n\n";
	cout << "Total reimbursement so far: " << total_reimbursement <<  "\n\n";
}

/*********************************************************************
** Function: get_names
** Description: gets the names of the people that are going to have their inputs calculated
** Parameters: int size
** Pre-Conditions: expected valid int inputs
** Post-Conditions: returns array of names
*********************************************************************/ 
string* get_names (int size){
	
	string *returned = new string[size];
	for (int i = 0; i < size; i++){
		cout << "Please input the name of person #" << i+1 << endl;
		cin >> returned[i];
	}
	return returned;
}

/*********************************************************************
** Function: clear_values
** Description: clears the values for the next person 
** Parameters: all of them
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/ 
void clear_values (int &days_of_trip, double &departure_time, double &arrival_time, double &meal_expense, double &meal_reimbursement, float &total_expense, float &total_reimbursement, float &expense_to_add, float &reimbursement_to_add, float &airfare,float &registration_fees, float &car_fees, float &car_reimbursement, float &hotel_fees, float &hotel_reimbursement){
	
	days_of_trip = 0;
	departure_time = 0;
	meal_expense = 0;
	meal_reimbursement = 0;
	total_expense = 0;
	total_reimbursement = 0;
	expense_to_add = 0;
	reimbursement_to_add = 0;
	airfare = 0;
	registration_fees=0;
	car_fees = 0;
	car_reimbursement = 0;
	hotel_fees = 0;
	hotel_reimbursement = 0;
}

/*********************************************************************
** Function: calling_extra
** Description: calls necessary functions 
** Parameters: all of them
** Pre-Conditions: expected valid inputs
** Post-Conditions: updated inputs
*********************************************************************/
void calling_extra(double &departure_time, double &arrival_time, float &airfare, float &registration_fees, float &total_reimbursement, float &car_fees, int days_of_trip, float &car_reimbursement, float &hotel_fees, float &hotel_reimbursement, double &meal_expense, double &meal_reimbursement){
		trip_time(departure_time, arrival_time);
		
		get_fare(airfare, registration_fees, total_reimbursement);
		
		get_car(car_fees, days_of_trip, car_reimbursement, total_reimbursement);
		
		get_hotel(days_of_trip, hotel_fees, hotel_reimbursement, total_reimbursement);
		
		meal_fee(days_of_trip, departure_time, arrival_time, &meal_expense, &meal_reimbursement);
}

/*********************************************************************
** Function: request_data
** Description: returns array of values for the users.
** Parameters: all of them
** Pre-Conditions: expected valid input
** Post-Conditions: returns array of values
*********************************************************************/ 
float* request_data (int &days_of_trip, double &departure_time, double &arrival_time, double &meal_expense, double &meal_reimbursement, float &total_expense, float &total_reimbursement, float &expense_to_add, float &reimbursement_to_add, float &airfare,float &registration_fees, float &car_fees, float &car_reimbursement, float &hotel_fees, float &hotel_reimbursement, string name[], int size){
	float* returned = new float[size*3];
	float meal_expense_float, meal_reimbursement_float;
	int j = 0;
	for (int i = 0; i < size; i++){
		
		cout << "Now getting expenses from " << name[i] << endl;
		get_days(days_of_trip);
		
		calling_extra(departure_time, arrival_time, airfare, registration_fees, total_reimbursement, car_fees, days_of_trip, car_reimbursement, hotel_fees, hotel_reimbursement, meal_expense, meal_reimbursement);
		
		meal_expense_float = float(meal_expense);
		meal_reimbursement_float = float(meal_reimbursement);
		
		update_total(total_expense, total_reimbursement, meal_expense_float, meal_reimbursement_float);
		
		total_expense = total_expense + car_fees + hotel_fees + registration_fees + airfare;
		cout << "Reporting status from " << name[i]<< endl;
		report_status(days_of_trip, departure_time, arrival_time, meal_expense, meal_reimbursement, total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare,registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement);
		returned[i+j]= total_expense;
		j++;
		returned[i+j]= total_reimbursement;
		j++;
		returned[i+j]= total_expense - total_reimbursement;
		clear_values(days_of_trip, departure_time, arrival_time, meal_expense, meal_reimbursement, total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare,registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement);
	}
	return returned;
}

/*********************************************************************
** Function: print_results
** Description: prints the results for each user
** Parameters: array, size and names
** Pre-Conditions: expected valid inputs
** Post-Conditions: printed inputs
*********************************************************************/ 
void print_results (float array[][3], int size, string names[]){
	
	for (int i=0; i<size; i++){ //loop for outputting results
		cout << "***************************************\n";
		cout << names[i] << endl;
		cout << "Your total expense was: "<< array[i][0] << endl;
		cout << "Your total reimbursement was: "<< array[i][1] << endl;
		cout << "Your final out-of-pocket balance is: " << array[i][2] << endl;
		cout << "***************************************\n";
	}
	
}

int main() {
	int days_of_trip, car_detail, size,j = 0, choice;
	double departure_time, arrival_time, meal_expense = 0, meal_reimbursement = 0;
	float total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare, registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement, meal_expense_float, meal_reimbursement_float;
	
	do {
		//getting size of arrays limited for 100 people for no reason
		loop_for_int(size, "Please input the amount of people this program will take expenses from: ",100, 1);
		float array_of_values [size][3];
		choice = 0;
		
		string* name = get_names(size); //creating array and reassigning names to static
		string names[size];
		for (int i = 0; i < size; i++){
			names[i] = name[i];
		}
		delete[] name;
		
		//getting the results of the program and assigning it to 2D array for output.
		float* Play = request_data (days_of_trip, departure_time, arrival_time, meal_expense, meal_reimbursement, total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare,registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement, names, size);
		for (int i = 0; i < size; i++){
			array_of_values[i][0] = Play[i+j];
			j++;
			array_of_values[i][1] = Play[i+j];
			j++;
			array_of_values[i][2] = Play[i+j];
		}
		//printing results for each player
		print_results(array_of_values, size, names);
		delete[] Play;
		//asking if want to use again
		loop_for_int(choice, "Would you like to do any further calculations?\nInput 1 for Yes, and 2 for No:", 2, 1);
		
	} while (choice == 1);
	return 0;
}