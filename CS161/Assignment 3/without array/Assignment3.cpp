/******************************************************************************
 * Program: Assignment3.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Nim game with 2 players and 1 winner. Game generates random numbers for each pile between 1 and 10.
 * Inputs: A,B,C for the piles and 1,2,3 for amount.
 * Output: The remaining of each pile per round and winner
 * Date: 04/15/2019
 ******************************************************************************/
 
 #include <cmath> //for math functions
 #include <iostream> //for IO out/in
 #include <string> //for string
 #include <cstdlib> //for rand
 #include <ctime> //for rand
 
 using namespace std;
 
 //fancy print function
 string fancy (int fprint) {
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
	int on = 1;
	int off = 0;
	if (checka == 0 && checkb == 0 && checkc == 0) { //checks for winning round.
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
	int play = 0;
	int stones; //defined for amount of stones removed from pile.
	//getting player names.
	//game starts
	cout << "Welcome to NIM - The Game!" << endl;
	cout << "This is a two player game. \n" << "It ends when all the piles have ZERO rocks in them.\nThe LOSER is the player that takes the last rock\nfrom the last pile that still contains a rock.\n";
	cout << "You can only take up to 3 rocks at a time from your desired pile. You cannot take 0 rocks from the pile.\n";
	cout << "Have fun!\n";
	cout << "Player 1, please input your desired name: "<< endl;
	getline(cin,player1); //getting input for name player 1.
	cout << "Player 2, please input your desired name: "<< endl;
	getline(cin,player2); //getting input for name player 2.
	cout << "\n A : " << fancy(a) << "\n B : " << fancy(b) << "\n C : " << fancy(c) << "\n" << "\n"; //prints current game status.
	do { // Do-while loop to repeat whole code while either one of a,b,c are not zero.
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
		int z = checkWin (a, b, c, play, player1, player2);
		z;
		if (z == 1) {
			return 0;
		}
		//player 2 turn begins here
		//the code is the same for both player 1 and 2 so the notes for player1 apply to player2.
		char play2;
		do {
			if (trigger){
				cout << "Please input valid pile: " << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
			cout << player2 << ", choose a pile: " << endl;
			cin >> play2;
			while ((((play2 == 'A' && a == 0) || (play2 == 'a' && a == 0)) || ((play2 == 'B' && b == 0) || (play2 == 'b' && b == 0))) || ((play2 == 'C' && c == 0) || (play2 == 'c' && c == 0))) {
				cout << "Please input valid pile: " << endl;
				cin >> play2;
			}
			trigger = 1;
		} while (play2 != 'A' && play2 != 'a' && play2 != 'B' && play2 != 'b' && play2 != 'C' && play2 != 'c');
		trigger = 0;
		if (play2 == 'A' || play2 == 'a') {
			do {
				if (trigger) {
					cout << "Please input valid amount..." << endl;
					cin.clear();
					cin.ignore(10, '\n');
				}
				cout << "How many Stones do you want to remove from pile A?" << endl;
				cin >> stones;
				trigger = 1;
			} while (stones > a || stones > 3 || stones < 1);
			trigger = 0;
			a = a - stones;
		}
		if (play2 == 'B' || play2 == 'b') {
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
		if (play2 == 'C' || play2 == 'c') {
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
	} while (a != 0 || b != 0 || c != 0);
	//checks for winning round
	checkWin (a, b, c, play, player1, player2);
	
	return 0; 
 }