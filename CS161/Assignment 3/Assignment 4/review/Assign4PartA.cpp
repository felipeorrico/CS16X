/******************************************************
** Program: Assign4PartA.cpp
** Author: Noah Robertson
** Date: 5/12/2019
** Description: Runs the game of hangman
** Input: The user inputs letters as guesses for the word
** Output: The program outputs the instructions and condition of the game according to player input
******************************************************/

#include <iostream>
#include <string>

using namespace std;
//declaration of function guess_to_upper
char guess_to_upper(char guess_to_upper);


/********************************************************************
** Function: main
** Description: Where the majority of the hangman game is executed.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a, program ends
*********************************************************************/
int main(){

    // the word is 'wardrobe'
    char word [8] = {'*', '*', '*', '*', '*', '*', '*', '*'};
    char missed_guesses [8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char winning_array [8] = {'W', 'A', 'R', 'D', 'R', 'O', 'B', 'E'};

    cout << "\nWelcome to Hangman! Try to guess the word." << endl;
    int attempts;
    char guess;
    //the following for loop repeats the same number of times as the word is long, plus 1
    for(int i = 0; i < sizeof(word) + 1; i++){
        attempts = i + 1;

//        if (word[0] == 'W' && word[1] == 'A' && word[2] == 'R' && word[3] == 'D' && word[4] == 'R' && word[5] == 'O' && word[6] == 'B' && word[7] == 'E'){
//            cout << "YOU WIN!" << endl;
//            return 0;

        //states the condition of the game
        cout << "\nAttempt: " << attempts << "/" << sizeof(word) + 1;
        cout << "\nWord:    " << word << endl;
        cout << "Misses:  " << missed_guesses << endl;
        cout << "What's your guess?: ";
        cin >> guess;
        char guess_yeet = guess_to_upper(guess);
        //the following statements check the user inputs and repsond accordingly

        if(guess_yeet == 'W'){
            word[0] = 'W';
        }
        else if(guess_yeet == 'A'){
            word[1] = 'A';
        }
        else if(guess_yeet == 'R'){
            word[2] = 'R';
            word[4] = 'R';
        }
        else if(guess_yeet == 'D'){
            word[3] = 'D';
        }
        else if(guess_yeet == 'O'){
            word[5] = 'O';
        }
        else if(guess_yeet == 'B'){
            word[6] = 'B';
        }
        else if(guess_yeet == 'E'){
            word[7] = 'E';
        }
        else{
            missed_guesses[i] = guess_yeet;
            cout << "You lost." << endl;
        }
    }
return 0;
}

/********************************************************************
** Function: guess_to_upper
** Description: converts the user input to an uppercase letter
** Parameters: only characters can be inputted
** Pre-Conditions: the for loop is running
** Post-Conditions: the character entered is uppercase
*********************************************************************/
char guess_to_upper(char guess){
    for(int i = 0; i < 1; i++){
        int x = (char(guess));
        if(x > 96 && x < 123){
            guess = x - 32;
        }
    }
return guess;
}
