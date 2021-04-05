//**********************************************************
//Program:  Assignment4.cpp
//Author:  Devin Ascherl
//Date: 5/12/2019
//Description:  This game plays the Hangman game!
//Input:  Strings, namely either a single word or single letter.
//Output:  An array that shows the remaining letters, the correct letters so far and the incorrect letters so far.
//**********************************************************

//We have four libraries included.
#include <iostream> //First, we have the input and output libraries.
#include <string> //Second, we need string for the length() and at() commands.
#include <cstdlib> //We need this for random, which is used later.
#include <ctime> //We need this for true randomness.

using namespace std;

//This function convers the user's input from lowercase to uppercase, which makes the inputs easier.
string to_upper(string Input)
{
     for (int i = 0; i < Input.length(); i++)
     {
	  if (Input[i] >= 'a' and Input[i] <= 'z')
	  {
	       Input[i] = Input[i] - 32; //We remove 32 to convert it to the proper ASCII value.
	  }
     }
     return Input;
}

//This function checks if the input is valid or not.  If the input is not A-Z, it returns a false.
bool input_checker(string Input)
{
     int Check = 0;
     for (int i = 0; i < Input.length(); i++)
     {

	  //I used a check that increases with the number of errors to provide a false result.
          if (Input.at(i) >= 'A' and Input.at(i) <= 'Z')
     	  {
	       Check = Check;
     	  }
     	  else
      	  {
	       Check = Check + 1;
          }
     }
     if (Check > 0)
     {
          return false;
     }
     else
     {
          return true;
     }
     
}

//This function selects a random word from a given library of words.  It has 20 options to choose from, and will return the word.
string word_generator()
{
     srand (time(NULL));
     int Randomizer = rand()%20;

     //These words were chosen at random from the dictionary.  To make it more confusing to guess what word it is, I repeatedly used five letter words, however any word would be fine.
     string WordBank[] = {"SWING", "CROWD", "FRUIT", "PAINT", "BRASS", "SHORT", "BURST", "SCALD", "HEAVE", "GRADE", "REPLY", "BRAVE", "PUSHY", "SPARK", "FAINT", "MACHO", "CAUSE", "APPLE", "TRAMP", "LATCH"};

     return WordBank[Randomizer];

}

//This function checks if the input that the player in is equal to any of the letters in the word generated above.  If it is the same anywhere, it returns a true.  If not, it returns a false.
bool Bad_Input_Check (string Input, string Word)
{
     string Check;
     for (int i = 0; i < Word.length(); i++)
     {
	  Check = Word.at(i);

	  if (Input == Check)
	  {
	       return true;
	  }
     }
     return false;

}

//This is our main function, which calls on all of the other functions.
int main()
{
     int WinCheck = 0; //This int is used to see if the player has won or not.
     int Turns = 0; //This int is used to count how many turns have passed.
     string Input;//This is the player's input.
     string Word = word_generator();//This calls on the word_generator function to generate a random word.
     string IsItSame;//This string is used later to see if the letter input is the same as the given word.
     string BadInputs[Word.length() + 1];//This string is used to represent incorrect inputs by the player.  Its length is equal to the length of the game, or the number of letters in the word plus one.
     int LetterChecker[Word.length()];//This int is used to convert the letters of the generated word into '_'s.
     bool BadInputChecker; //This true false result indicates if the player entered correct information or not.

     //First, we start with the introductory information for the game, along with basic rules.
     cout << "Welcome to Hangman!  To play this game, enter a letter!  If the letter is correct, it will appear among a list of undefined letters.  If it is wrong, it will be marked wrong!" << endl;
     cout << "If you enter more than one character, it counts as a word guess, and so you will only win if it is completely correct." << endl; //While the assignment does say to make it so that if a player enters a word, it is suppose to extract the words, I felt that this was unfair.  A player could type in all of the letters of the alphabet and win this way.  So, I did away with it.
     cout << "You have as many turns as the number of letters plus one!  Good luck." << endl;
     do// Everything after the tutorial and initial value setup gets repeated.
     {
        do //This while loop checks the validity of the response, and forces the player to input a new response if it is invalid.
        {
	     cout << "Input a letter or word." << endl;
             cin >> Input;
             Input = to_upper(Input);
	     if (input_checker(Input) == true)
             {
	          cout << "This is a valid input!  If it is correct, it will appear in the word below.  Otherwise, it will appear in the bad inputs!" << endl;
             }
             else if (input_checker(Input) == false)
             {
	          cout << "Invalid entry, please only enter a letter or word." << endl;
             }
        }
        while (input_checker(Input) == false);
	
	//This loop checks if the input matches the word or not.  If it does, it saves the value as 1.  If not, it saves a value of 0.
        for (int i = 0; i < Word.length(); i++)
	{

	     IsItSame = Word[i];
             if (Input == IsItSame)
             {
   	          LetterChecker[i] = 1;
   	          WinCheck = WinCheck + 1; //The loop also increases the win variable for each letter entered correctly.  This even works for words like apple, with two of the same letter.
             }   
	}
	
        //This checks if the input was in the word.	
        BadInputChecker = Bad_Input_Check(Input, Word);

	//And this for puts that value into an array if it was not in the word.
	if (BadInputChecker == false)
	{
	     BadInputs[Turns] = Input;
	}	     


         //Here we check if the input was the same as the word.  If it was, the player wins and it breaks out of the loop.
         if (Input == Word)
         {
              WinCheck = Word.length();
              break;
         }


	//Here we output our _s for non-one values of LetterChecker, and the accurate letter of the word for values of one of LetterChecker.
	for (int i = 0; i < Word.length(); i++)
	{
	     if (LetterChecker[i] != 1)
	     {
	          cout << "_";
             }
	     else if (LetterChecker[i] == 1)
	     {
	          cout << Word[i];
	     }
        }
	cout << endl;
	
	//Here we increase the number of turns by one.
	Turns = Turns + 1;

	//Here we output how many turns are left.
     	cout << "You have " << (Word.length() + 1 - Turns) << " turn(s) remaining." << endl;
	//And here we output the bad responses so far.
	cout << "Your bad responses so far are: \n";

	//This will output all invalid words or letters input so far in the BadInputs array.
	for (int i = 0; i < Word.length(); i++)
        {
	     cout << BadInputs[i] << " ";
	}
	cout << endl;


     }

     //This ends our loop, and it checks if the number of turns has exceeded the length of the word by one and checks if the player has already won or not.
     while (Turns < (Word.length() + 1) and WinCheck != Word.length()); 

     //Here, we check the winning conditions and output the corresponding results.
     if (WinCheck == Word.length())
     {
	  cout << "You win!  Congratulations!" << endl;
	  cout << "The word was: " << Word << endl;
     }
     else
     {
	  cout << "You lost!  Too bad!" << endl;
	  cout << "The word was: " << Word << endl;
     }
     return 0;
}
