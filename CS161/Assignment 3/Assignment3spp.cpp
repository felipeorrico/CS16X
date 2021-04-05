/******************************************************************************
 * Program: Assignment3.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Nim game with 2 players and 1 winner. Game generates random numbers for each pile between 1 and 10.
 * Inputs: A,B,C for the piles and 1,2,3 for amount.
 * Output: The remaining of each pile per round and winner
 * First Version: 04/15/2019
 * This Version: 04/18/2019
 ******************************************************************************/
 
 #include <cmath> //for math functions
 #include <iostream> //for IO out/in
 #include <string> //for string
 #include <cstdlib> //for rand
 #include <ctime> //for rand
 
 using namespace std;
 
 //fancy print function
 string fancy (int fprint) { //this will check the value of the variable and output a string that corresponds to its value.
	string aout;
	if (fprint) {
		if (fprint == 10) {
			aout = "**********";	
		}
		else if (fprint == 9) {
			aout = "*********";	
		}
		else if (fprint == 8) {
			aout = "********";
		}
		else if (fprint == 7) {
			aout = "*******";	
		}
		else if (fprint == 6) {
			aout = "******";	
		}
		else if (fprint == 5) {
			aout = "*****";	
		}
		else if (fprint == 4) {
			aout = "****";	
		}
		else if (fprint == 3) {
			aout = "***";	
		}
		else if (fprint == 2) {
			aout = "**";	
		}
		else if (fprint == 1) {
			aout = "*";	
		}
	} 
	else if (fprint==0) {
		aout = "Zero";
	}
	return aout;
 }
 
 int checkWin (int checka, int checkb, int checkc, int play3, string player1, string player2) {
	int on = 1; //win true
	int off = 0; //not won yet
	if (checka == 0 && checkb == 0 && checkc == 0) { //checks for empty piles.
		if (play3 %2 == 1) {
			cout << "All the piles are empty. " << player2 << " Wins! \n";
			return on;
		}
		else if (play3 %2 == 0) {
			cout << "All the piles are empty. " << player1 << " Wins! \n";
			return on;
		}
		else{
			return off;
		}
	}
	else {
		return off;
	}
}

 int* gamePlay (int a, int b, int c, int play, string player1) { //game function .. the game runs here.
	int stones;
	char play1;
	bool trigger = 0; //defined trigger for invalid input error message.
	do { //loop for input
		if (trigger){
			cout << "Please input valid pile: " << endl; //error message
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << player1 << ", choose a pile: " << endl;
		cin >> play1; //gets input and assigns to play1
		//while loop to check if pile is empty
		while ((((play1 == 'A' && a == 0) || (play1 == 'a' && a == 0)) || ((play1 == 'B' && b == 0) || (play1 == 'b' && b == 0))) || ((play1 == 'C' && c == 0) || (play1 == 'c' && c == 0))) {
			cout << "Please input valid pile: " << endl;
			cin >> play1;
		}
		trigger = 1;
	} while (play1 != 'A' && play1 != 'a' && play1 != 'B' && play1 != 'b' && play1 != 'C' && play1 != 'c');
	trigger = 0; // resets trigger for reuse
	//if statements for choice between piles
	if (play1 == 'A' || play1 == 'a') {
		do { //loop to check input
			if (trigger) {
				cout << "Please input valid amount..." << endl; //error message
				cin.clear(); //flushes the input
				cin.ignore(10, '\n');
			}
			cout << "How many Stones do you want to remove from pile A?" << endl;
			cin >> stones;
			trigger = 1;
		} while (stones > a || stones > 3 || stones < 1);
		trigger = 0;
		a = a - stones; //math operation that takes the input (stones) from random number generated for a.
	}
	if (play1 == 'B' || play1 == 'b') { //same as if(play1 == 'A') 
		do {
			if (trigger) {
				cout << "Please input valid amount..." << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
			cout << "How many Stones do you want to remove from pile B?" << endl;
			cin >> stones;
			trigger = 1;
		} while (stones > b || stones > 3 || stones < 1);
		trigger = 0;
		b = b - stones;
	}
	if (play1 == 'C' || play1 == 'c') { //same as if(play1 == 'A') 
		do {
			if (trigger) {
				cout << "Please input valid amount..." << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
			cout << "How many Stones do you want to remove from pile C?" << endl;
			cin >> stones;
			trigger = 1;
		} while (stones > c || stones > 3 || stones < 1);
		trigger = 0;
		c = c - stones;
	}
	cout << "\n A : " << fancy(a) << "\n B : " << fancy(b) << "\n C : " << fancy(c) << "\n" << "\n"; //prints current game status.
	++play;
	int* array = new int[100];
	array[0]= a;
	array[1]= b;
	array[2]= c;
	array[3]= play;
	return array;
 }
 
 void welcomeMessage (){ //this function has the function to output the welcome message of the game.
	cout << "Welcome to NIM - The Game!" << endl;
	cout << "This is a two player game. \n" << "It ends when all the piles have ZERO rocks in them.\nThe LOSER is the player that takes the last rock\nfrom the last pile that still contains a rock.\n";
	cout << "You can only take up to 3 rocks at a time from your desired pile. You cannot take 0 rocks from the pile.\n";
	cout << "Have fun!\n";
 }
 
 int main () {
	srand (time(NULL));
	int a;
	a = rand() % 10 + 1;//generating random number.
	int b;
	b = rand() % 10 + 1;//generating random number.
	int c;
	c = rand() % 10 + 1;//generating random number.
	string player1; //player 1 name string now defined.
	string player2; //player 2 name string now defined.
	int play = 0; //defines int play that is used to check who won.
	int stones; //defined for amount of stones removed from pile.
	//game starts
	//getting player names.
	welcomeMessage();
	cout << "Player 1, please input your desired name: "<< endl;
	getline(cin,player1); //getting input for name player 1.
	cout << "Player 2, please input your desired name: "<< endl;
	getline(cin,player2); //getting input for name player 2.
	cout << "\n A : " << fancy(a) << "\n B : " << fancy(b) << "\n C : " << fancy(c) << "\n" << "\n"; //prints current game status.
	do { //game running until all piles are zero
		int* returnout = gamePlay(a, b, c, play, player1);
		a = returnout[0]; //points the value of the variable to correspondent value in array.
		b = returnout[1]; 
		c = returnout[2];
		play = returnout[3];
		delete[] returnout; //deletes array
		int z = checkWin (a, b, c, play, player1, player2); //checks win
		if (z == 1) {//if win is ON it ends program
			return 0;
		}
		int* returnout2 = gamePlay(a, b, c, play, player2);
		a = returnout2[0];
		b = returnout2[1]; 
		c = returnout2[2];
		play = returnout2[3];
		delete[] returnout2;
	} while (a != 0 || b != 0 || c != 0);
	checkWin (a, b, c, play, player1, player2);
	return 0;
 }