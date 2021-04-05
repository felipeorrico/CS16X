#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*

ADD: 
Car Stuff, - OK
Taxi stuff, - OK
food stuff, 
conference and seminar stuff, - ok
Airfare stuff; - ok
hotel stuff; - ok

● The number of days spent on the trip - ok
● The departure time on the first day of the trip, and arrival time on the last day of the trip - ok
● The amount of airfare - ok
● Conference or seminar registration fees - ok
● Rent a car or use taxis during the trip-ok
● Rental car type -ok
● Miles driven, if rent a car. - ok
● Parking fees for each day, if rent a car - ok
● Taxi fees for each day, if use taxis - ok
● Hotel expenses for each day, if number of days spent on the trip is greater than 1 - ok


*/

//must have function

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

void update_total (float &total_expense, float &total_reimbursement, float expense_to_add, float reimbursement_to_add){
	total_expense += expense_to_add;
	total_reimbursement += reimbursement_to_add;
}

void get_if_meal (double &meal_expense, double &meal_expense_copy, int days_of_trip, int j, double &meal_reimbursement){
	
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

void get_first_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, int i, bool &breaker, double &meal_expense_copy){
	
	if (i == 1 && departure_time <= 07.00){
		for (int j = 0; j < 3; j++){
			cout << "Meal " << j+1 << endl;
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

void get_last_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, int i, bool &breaker, double &meal_expense_copy){
	
	if (i == days_of_trip && arrival_time >= 19.00){
		for (int j = 0; j < 3; j++){
			cout << "Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == days_of_trip && (arrival_time >= 13.00 && arrival_time < 19.00)){
		for (int j = 0; j < 2; j++){
			cout << "Meal 3 is not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	else if (i == days_of_trip && (arrival_time >= 08.00 && arrival_time < 13.00)){
		for (int j = 0; j < 1; j++){
			cout << "Meal 2 and 3 are not applicable for this day.\n Meal " << j+1 << endl;
			loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
			get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
			breaker = true;
		}
	}
	meal_expense_copy = 0;
}

void get_other_day_meal (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement, double &meal_expense_copy){
	for (int j = 1; j <= 3; j++){
		cout << "Meal " << j << endl;
		loop_for_double(meal_expense_copy, "Please input the amount spent on the meal in dollars $: ", 00.00, 9999.99); //put maximum and minimum allowed
		get_if_meal(meal_expense, meal_expense_copy, days_of_trip, j, meal_reimbursement);
		meal_expense_copy = 0;
	}
}
//must have function
void meal_fee (int days_of_trip, double departure_time, double arrival_time, double* meal_expense, double* meal_reimbursement){
	
	bool breaker = false;
	double meal_expense_copy;
	for (int i = 1; i <= days_of_trip; i++){
		breaker = false;
		cout << "You Will now input the value spent for each meal of day " << i << ". \nPlease use the following format: XX.XX . \nMeal 1 - Breakfast, Meal 2 - Lunch, Meal 3 - Dinner\n";
		if (departure_time > 18.00 && i == 1){
			cout << "None of the meals from the first day of the trip are allowed as expense.\n";
			continue;
		}
		get_first_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, i, breaker, meal_expense_copy);
		if (breaker == true)
			continue;
		
		if (arrival_time < 08.00 && i == days_of_trip){
			cout << "None of the meals from the last day of the trip are allowed as expense.\n";
			continue;
		}
		get_last_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, i, breaker, meal_expense_copy);
		if (breaker == true)
			continue;
		if (i != 1 && i != days_of_trip){
			get_other_day_meal(days_of_trip, departure_time, arrival_time, *meal_expense, *meal_reimbursement, meal_expense_copy);
		}
		breaker = false;
		
	}	
	
}

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
}


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

void trip_time (double &departure_time, double &arrival_time){ //updates the departure and arrival times - working
	
	string message_departure = "Please input the time of departure on the format XX.XX : ";
	string message_arrival = "Please input the time of arrival on the format XX.XX : ";
	loop_for_double(departure_time, message_departure, 00.00, 23.59);
	loop_for_double(arrival_time, message_arrival, 00.00, 23.59);
	
}

void get_fare (float &airfare, float &registration_fees, float &total_reimbursement){ //gets registration fees and air fares - working
	
	string message_airfare = "Please enter the total amount of airfare, in $: ";
	string message_registration = "Please enter total conference or seminar registration fees, in $: ";
	loop_for_float(airfare, message_airfare);
	loop_for_float(registration_fees, message_registration);
	total_reimbursement += registration_fees + airfare;
	
}

void loop_for_int (int &input, string message, int max, int min){
	
	bool trigger = 0;
	int car_choice;
	do {
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

void get_taxi_fare (float &car_fees, int days_of_trip, float &car_reimbursement) { //taxi stuff - working
	
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

void get_final_car_fee (float &car_fees, int car_type, float miles_driven, int days_of_trip, float &car_reimbursement) { //car stuff - working
	
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

void get_parking (float &car_reimbursement, int days_of_trip,float &car_fees) { //gets the parking stuff - Working
	
	float value;
	for (int i=1; i <= days_of_trip; i++){
		
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

void get_car (float &car_fees, int days_of_trip, float &car_reimbursement, float &total_reimbursement){ //gets all the values for the car - Working
	
	int car_choice, car_type;
	float miles_driven;
	loop_for_int(car_choice, "Did you 1: rent a car or 2: use taxi for your trip? Enter 1 or 2: ", 2, 1);
	if (car_choice == 1) {
		loop_for_int(car_type, "Please choose Between the following types of vehicle:\n 1. Sedan\n 2. SUV\n 3. Van\n 4. Convertible\n Enter the type of car you rented: ", 4, 1);
		loop_for_float(miles_driven, "Please input the total miles driven: ");
		get_final_car_fee(car_fees, car_type, miles_driven, days_of_trip, car_reimbursement);
		get_parking(car_reimbursement, days_of_trip, car_fees);
	}
	else if (car_choice == 2){
		get_taxi_fare(car_fees, days_of_trip, car_reimbursement);
	}
	total_reimbursement += car_reimbursement;
}

void get_hotel (int days_of_trip, float &hotel_fees, float &hotel_reimbursement, float &total_reimbursement){//test
	
	float hotel_fees_copy;
	cout << "You will now enter the amount of money spent on Hotel fees per day of the trip: \n";
	for (int i = 0; i < days_of_trip; i++){
		if (days_of_trip == 1){
			hotel_fees = 0;
			hotel_reimbursement =0;
			cout << "This trip is too short for you to stay in a hotel\n";
			break;
		}
		cout << "Day " << i + 1 << endl;
		loop_for_float(hotel_fees_copy, "Please Input the Hotel Fees for this day: ");
		if (hotel_fees_copy <= 90){
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

void report_status (int days_of_trip, double departure_time, double arrival_time, double meal_expense, double meal_reimbursement, float total_expense, float total_reimbursement, float expense_to_add, float reimbursement_to_add, float airfare,float registration_fees, float car_fees, float car_reimbursement, float hotel_fees, float hotel_reimbursement){
	
	cout << "The days you input are now updated to: "<< days_of_trip <<  "\n\n";
	cout << "Arrival time is now: " << arrival_time << " Departure time is now " << departure_time << "\n\n";
	cout << "Your total airfare is: "<< airfare <<  "\n\n";
	cout << "Your total registration_fees is: "<< airfare <<  "\n\n";
	cout << "Your total car fees are: "<< car_fees <<  "\n\n";
	cout << "Your total car reimbursement is: " << car_reimbursement <<  "\n\n";
	cout << "Total hotel expense: "<< hotel_fees <<  "\n\n";
	cout << "total hotel reimbursement: "<< hotel_reimbursement<<  "\n\n";
	cout << "Total meal fees: " << meal_expense << "\n\n";
	cout << "Total meal Reimbursement: " << meal_reimbursement <<  "\n\n";
	cout << "Total expense so far: " << total_expense <<  "\n\n";
	cout << "Total reimbursement so far: " << total_reimbursement <<  "\n\n";
}

int main() {
	int days_of_trip, car_detail;
	double departure_time, arrival_time, meal_expense, meal_reimbursement;
	float total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare, registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement, meal_expense_float, meal_reimbursement_float;
	
	//add total meal_reimbursement to total reimbursement - ok?
	//add car_fees, hotel_fees, registration_fees, airfare to total expense. - ok
	system ("clear");
	
	get_days(days_of_trip);
	
	trip_time(departure_time, arrival_time);
	
	get_fare(airfare, registration_fees, total_reimbursement);
	
	get_car(car_fees, days_of_trip, car_reimbursement, total_reimbursement);
	
	get_hotel(days_of_trip, hotel_fees, hotel_reimbursement, total_reimbursement);
	
	meal_fee(days_of_trip, departure_time, arrival_time, &meal_expense, &meal_reimbursement);
	
	meal_expense_float = float(meal_expense);
	meal_reimbursement_float = float(meal_reimbursement);
	
	update_total(total_expense, total_reimbursement, meal_expense_float, meal_reimbursement_float);
	
	total_expense = total_expense + car_fees + hotel_fees + registration_fees + airfare;
	
	report_status(days_of_trip, departure_time, arrival_time, meal_expense, meal_reimbursement, total_expense, total_reimbursement, expense_to_add, reimbursement_to_add, airfare,registration_fees, car_fees, car_reimbursement, hotel_fees, hotel_reimbursement);
	
	
	return 0;
}