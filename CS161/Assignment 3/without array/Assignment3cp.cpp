/******************************************************************************
 * Program: Assignment3.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Nim game with 2 players and 1 winner. Game generates random numbers for each pile between 1 and 10.
 * Inputs: A,B,C for the piles and 1,2,3 for amount.
 * Output: The remaining of each pile per round and winner
 * Date: 04/15/2019
 ******************************************************************************/
 
 #include <cmath>
 #include <iostream>
 #include <string>
 #include <cstdlib>
 #include <ctime>
 
 using namespace std;
 
 int main (){
	srand (time(NULL));
	int a;
	a = rand() % 10 + 1;//generating random number.
	int b;
	b = rand() % 10 + 1;//generating random number.
	int c;
	c = rand() % 10 + 1;//generating random number.
	int stones; //defined for amount of stones removed from pile.
	int play; //defines int for winning check
	string aout; // fancy a
	string bout; //fancy b
	string ccout; //fancy c
	string player1; //player 1 name string now defined.
	string player2; //player 2 name string now defined.
	//if statements for fancy display
	if (a) {
		if (a == 10) {
			aout = "*********";	
		}
		else if (a == 9) {
			aout = "*********";	
		}
		else if (a == 8) {
			aout = "********";
		}
		else if (a == 7) {
			aout = "*******";	
		}
		else if (a == 6) {
			aout = "******";	
		}
		else if (a == 5) {
			aout = "*****";	
		}
		else if (a == 4) {
			aout = "****";	
		}
		else if (a == 3) {
			aout = "***";	
		}
		else if (a == 2) {
			aout = "**";	
		}
		else if (a == 1) {
			aout = "*";	
		}
	} 
	else if (a==0) {
		aout = "Zero";
	}
	if (b) {
		if (b == 10) {
			bout = "*********";
		}			
		else if (b == 9) {
			bout = "*********";	
		}
		else if (b == 8) {
			bout = "********";
		}
		else if (b == 7) {
			bout = "*******";	
		}
		else if (b == 6) {
			bout = "******";	
		}
		else if (b == 5) {
			bout = "*****";	
		}
		else if (b == 4) {
			bout = "****";	
		}
		else if (b == 3) {
			bout = "***";	
		}
		else if (b == 2) {
			bout = "**";	
		}
		else if (b == 1) {
			bout = "*";	
		}
	} 
	else if (b==0) {
		bout = "Zero";
	}
	if (c) {
		if (c == 10) {
			ccout = "*********";
		}
		else if (c == 9) {
			ccout = "*********";	
		}
		else if (c == 8) {
			ccout = "********";
		}
		else if (c == 7) {
			ccout = "*******";	
		}
		else if (c == 6) {
			ccout = "******";	
		}
		else if (c == 5) {
			ccout = "*****";	
		}
		else if (c == 4) {
			ccout = "****";	
		}
		else if (c == 3) {
			ccout = "***";	
		}
		else if (c == 2) {
			ccout = "**";	
		}
		else if (c == 1) {
			ccout = "*";	
		}
	} 
	else if (c==0) {
		ccout = "Zero";
	}
	// getting player names.
	cout << "Player 1, please input your desired name: "<< endl;
	getline(cin,player1); //getting input for name player 1.
	cout << "Player 2, please input your desired name: "<< endl;
	getline(cin,player2); //getting input for name player 2.
	cout << "\n A : " << aout << "\n B : " << bout << "\n C : " << ccout << "\n" << "\n"; //prints current game status.
	do { // Do-while loop to repeat whole code while either one of a,b,c are not zero.
		char play1;
		bool trigger = 0; //defined trigger for invalid input error message.
		do { //loop for input
			if (trigger){
				cout << "Please input valid pile: " << endl; //error message
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
		//fancy output
		if (a) {
			if (a == 10) {
				aout = "*********";	
			}
			else if (a == 9) {
				aout = "*********";	
			}
			else if (a == 8) {
				aout = "********";
			}
			else if (a == 7) {
				aout = "*******";	
			}
			else if (a == 6) {
				aout = "******";	
			}
			else if (a == 5) {
				aout = "*****";	
			}
			else if (a == 4) {
				aout = "****";	
			}
			else if (a == 3) {
				aout = "***";	
			}
			else if (a == 2) {
				aout = "**";	
			}
			else if (a == 1) {
				aout = "*";	
			}
		} 
		else if (a==0) {
			aout = "Zero";
		}
		if (b) {
			if (b == 10) {
				bout = "*********";
			}			
			else if (b == 9) {
				bout = "*********";	
			}
			else if (b == 8) {
				bout = "********";
			}
			else if (b == 7) {
				bout = "*******";	
			}
			else if (b == 6) {
				bout = "******";	
			}
			else if (b == 5) {
				bout = "*****";	
			}
			else if (b == 4) {
				bout = "****";	
			}
			else if (b == 3) {
				bout = "***";	
			}
			else if (b == 2) {
				bout = "**";	
			}
			else if (b == 1) {
				bout = "*";	
			}
		} 
		else if (b==0) {
			bout = "Zero";
		}
		if (c) {
			if (c == 10) {
				ccout = "*********";
			}
			else if (c == 9) {
				ccout = "*********";	
			}
			else if (c == 8) {
				ccout = "********";
			}
			else if (c == 7) {
				ccout = "*******";	
			}
			else if (c == 6) {
				ccout = "******";	
			}
			else if (c == 5) {
				ccout = "*****";	
			}
			else if (c == 4) {
				ccout = "****";	
			}
			else if (c == 3) {
				ccout = "***";	
			}
			else if (c == 2) {
				ccout = "**";	
			}
			else if (c == 1) {
				ccout = "*";	
			}
		} 
		else if (c==0) {
			ccout = "Zero";
		}
		cout << "\n A : " << aout << "\n B : " << bout << "\n C : " << ccout << "\n" << "\n"; //printing current game status
		play = 1;
		if (a == 0 && b == 0 && c == 0) { //checks for winning round.
			if (play == 1) {
				cout << "All the piles are empty. " << player1 << " Wins! \n";
				return 0;
			}
			else if (play == 2) {
				cout << "All the piles are empty. " << player2 << " Wins! \n";
				return 0;
			}
		}
		//player 2 turn begins here
		//the code is the same for both player 1 and 2 so the notes for player1 apply to player2.
		char play2;
		do {
			if (trigger){
				cout << "Please input valid pile: " << endl;
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
		//if statements for fancy display
		if (a) {
			if (a == 10) {
				aout = "*********";	
			}
			else if (a == 9) {
				aout = "*********";	
			}
			else if (a == 8) {
				aout = "********";
			}
			else if (a == 7) {
				aout = "*******";	
			}
			else if (a == 6) {
				aout = "******";	
			}
			else if (a == 5) {
				aout = "*****";	
			}
			else if (a == 4) {
				aout = "****";	
			}
			else if (a == 3) {
				aout = "***";	
			}
			else if (a == 2) {
				aout = "**";	
			}
			else if (a == 1) {
				aout = "*";	
			}
		} 
		else if (a==0) {
			aout = "Zero";
		}
		if (b) {
			if (b == 10) {
				bout = "*********";
			}			
			else if (b == 9) {
				bout = "*********";	
			}
			else if (b == 8) {
				bout = "********";
			}
			else if (b == 7) {
				bout = "*******";	
			}
			else if (b == 6) {
				bout = "******";	
			}
			else if (b == 5) {
				bout = "*****";	
			}
			else if (b == 4) {
				bout = "****";	
			}
			else if (b == 3) {
				bout = "***";	
			}
			else if (b == 2) {
				bout = "**";	
			}
			else if (b == 1) {
				bout = "*";	
			}
		} 
		else if (b==0) {
			bout = "Zero";
		}
		if (c) {
			if (c == 10) {
				ccout = "*********";
			}
			else if (c == 9) {
				ccout = "*********";	
			}
			else if (c == 8) {
				ccout = "********";
			}
			else if (c == 7) {
				ccout = "*******";	
			}
			else if (c == 6) {
				ccout = "******";	
			}
			else if (c == 5) {
				ccout = "*****";	
			}
			else if (c == 4) {
				ccout = "****";	
			}
			else if (c == 3) {
				ccout = "***";	
			}
			else if (c == 2) {
				ccout = "**";	
			}
			else if (c == 1) {
				ccout = "*";	
			}
		} 
		else if (c==0) {
			ccout = "Zero";
		}
		cout << "\n A : " << aout << "\n B : " << bout << "\n C : " << ccout << "\n" << "\n";
		play = 2;
	} while (a != 0 || b != 0 || c != 0);
	//checks for winning round
	if (play == 1) {
		cout << "All the piles are empty. " << player1 << " Wins! \n";
	}
	else if (play == 2) {
		cout << "All the piles are empty. " << player2 << " Wins! \n";
	}
	
	return 0; 
 }