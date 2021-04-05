/******************************************************************************
 * Program: Assignment4.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Hangman game with '2' players. One chooses the word, the other guesses it.
 * Inputs: any letter for the guess
 * Output: The remaining tries and the game status.
 * First Version: 05/03/2019
 * This Version: 05/04/2019
 ******************************************************************************/
 
 #include <iostream>
 #include <ctime>
 #include <string>
 #include <cstdlib>
 #include <boost/lexical_cast.hpp>
 
 using namespace std;
 
/*********************************************************************
** Function: toUnderscore
** Description: Substitutes the letters for the word string to underscore characters.
** Parameters: string word
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of valid string
*********************************************************************/ 
 string toUnderscore (string word);
/*********************************************************************
** Function: containsNumber
** Description: Checks if a string contains any character that is not allowed.
** Parameters: String guess
** Pre-Conditions: Expected input if a valid string
** Post-Conditions: Expected Returns of true or false
*********************************************************************/ 
 bool containsNumber (string checked);
/*********************************************************************
** Function: checkForRepetition
** Description: Checks if a string contains repeated characters and erases the repeated ones.
** Parameters: string checked
** Pre-Conditions: Expected input of valid string
** Post-Conditions: Expected return of a valid string
*********************************************************************/ 
 string checkForRepetition (string repeated);
/*********************************************************************
** Function: checkLetterFunction
** Description: Checks if the input guess is a letter or a word, then checks if the guess is valid and if so substitutes it in the underscore string. And counts the tries.
** Parameters: string guess, string word, string underscore, string usedLetters, int tries.
** Pre-Conditions: Expected input of valid string and int
** Post-Conditions: Expected output of array of strings
*********************************************************************/ 
 string *checkLetterFunction (string guess, string word, string underscore, string usedLetters, int tries);
/*********************************************************************
** Function: stringConvert
** Description: Converts every character of a string to lower case.
** Parameters: string word
** Pre-Conditions: Expected input of valid string
** Post-Conditions: Expected output of valid string
*********************************************************************/ 
 string stringConvert (string word);
/*********************************************************************
** Function: printUnderscoreString
** Description: The function will print every character of a string with a space between them.
** Parameters: string underscore
** Pre-Conditions: Expected input of Valid string
** Post-Conditions: Expected no return
*********************************************************************/ 
 void printUnderscoreString (string underscore);
 
 
 int main(){
	 
	 string word;
	 string guess;
	 string usedLetters;
	 string win = "WIN";
	 
	 int tries;
	 
	 //word to be guessed
	 word = "rogue";
	 
	 //creates the string underscore by converting it from the string word
	 string underscore = toUnderscore(word);
	 
	 //clears the console for better looks
	 system ("clear");
	 
	 //the amount of tries is equal to the sixe of the word string + 1
	 tries = word.length() + 1;
	 
	 cout << "***********************************************************************\n";
	 cout << "* Welcome to the HANGMAN Game!                                        *"<<endl;
	 cout << "* Guess the word. The word has " << word.length() << " letters                              *"<< endl;
	 cout << "* You may guess a letter or a whole word, just keep in mind that      *\n* if you input more than one letter, it will be considered as a word. *" << endl;
	 cout << "* You have " << tries << " tries Left                                               *\n";
	 cout << "***********************************************************************\n";
	 
	 while (tries > 0) { //creates a loop that repeats itself while the tries are greater than zero
		 
		 //creates a string to check if the player won
		 string winVerification;
		 
		 //this is the current status of the game
		 cout << "*************************************************\n";
		 cout << "* Hangman: "; printUnderscoreString(underscore); cout << "                           *\n";
		 cout << "* Used Letters: "; printUnderscoreString(usedLetters); cout << endl;
		 cout << "* Please input a word guess or a single letter. *\n";
		 cout << "*************************************************\n";
		 
		 /*this do while loop is checking for a valid input by the user, if the guess is or contains 
		 any character that is not allowed, it will return an error message*/
		 bool trigger = 0;
		 bool numberCheck;
		 do {
			 
			 if (trigger){
				 
				 cout << "******************************************\n";
				 cout << "* ERROR - Please Input a Letter or Word. *\n";
				 cout << "******************************************\n";
				 numberCheck = 0;
			 }
			 
			 cin >> guess;
			 
			 guess = stringConvert(guess);
			 
			 numberCheck = containsNumber(guess);
			 
			 trigger = 1;
			 
		 } while (numberCheck == 1);
		 
		 //this pointer will get the returned array from the checkLetterFunction and store the its values
		 string* gamePlay = checkLetterFunction(guess, word, underscore, usedLetters, tries);
		 
		 winVerification = gamePlay[0];
		 underscore = gamePlay[1];
		 usedLetters = gamePlay[2];
		 tries = atoi(gamePlay[3].c_str());
		 delete[] gamePlay;
		 
		 //this will check again to see if the player has won the game after the results were returned by the array.
		 if (winVerification == win){
			 cout << "*********************\n";
			 cout << "* You Won the Game! *" << endl;
			 cout << "*********************\n";
			 return 0;
		 }
		 
	 }
	 
	 //when the loop is over, the program will display this and end the program
	 cout << "************************************\n";
	 cout << "* You ran out of tries! Game Over! *" << endl;
	 cout << "************************************\n";
	 
	 return 0;

 }
 
 bool containsNumber (string checked){ 
	
	 if (string::npos != checked.find_first_of("0123456789!@#$%^&*,.;:?+-=_")) {
		
		 return 1;
		
	 }
	 
	 return 0;
	 
 }
 
 string checkForRepetition (string repeated) {
	 
	 for (int i = 0 ; i < repeated.length(); i++){
		 int j = i+1;
		 for (; j < repeated.length();){
			 if (repeated[i] == repeated[j]){
				 repeated.erase(j, 1);
			 }
			 else{
				 ++j;
			 }
		 }
	 }
	 
	 return repeated;
	 
 }
 
 string *checkLetterFunction (string guess, string word, string underscore, string usedLetters, int tries){ 
 
	 string underscoreCopy = underscore;
	
	 string* returned = new string[4];
	 
	 string winVerification = "WIN";
	 
	 if (guess.length() > 1) { //working
		 if (guess == word){
			 cout << "*******************************\n";
			 cout << "* You guessed the right word! *\n";
			 cout << "*******************************\n";
			 returned[0] = winVerification; //if returned is win than game is over.
			 return returned;
		 }
		 else {
			 --tries;
			 string tried = boost::lexical_cast<string>(tries);
			 
			 returned[0] = word;
			 returned[1] = underscore;
			 returned[2] = usedLetters;
			 returned[3] = tried;
			 
			 cout << "*************************\n";
			 cout << "* You have " << tries << " tries Left *" << endl;
			 cout << "*************************\n";
			 return returned;
		 }
	 }
	 
	 else if (guess.length() == 1) {
		 for(int i = 0; i < word.length(); i++){
			 if (guess.find(word[i]) != string::npos) {
				 
				 underscore[i] = word [i]; //this will make change the underscores to the letter if correct.
				 
			 }
		 }	
	 }
	 
	 //in case the tries are only taken out if the player makes a mistake remove this from comment
	 
	 // if (underscoreCopy == underscore){
		 
		 // usedLetters += guess;
		
		 // usedLetters = checkForRepetition(usedLetters);
		 
	 --tries;
	 // }
	 
	 if (underscore == word) { //checks if after a guess the word is equal to the underscore string to check win
		 
		 cout << "***********************************************************\n";
		 cout << "* You guessed all the letters of the word " << word << " Good Job! *\n";
		 cout << "***********************************************************\n";
		 returned[0] = winVerification;
		 return returned;
	 }
	 
	 string tried = boost::lexical_cast<string>(tries);
	 
	 returned[0] = word;
	 returned[1] = underscore;
	 returned[2] = usedLetters;
	 returned[3] = tried;
	 
	 cout << "*************************\n";
	 cout << "* You have " << tries << " tries Left *" << endl;
	 cout << "*************************\n";
	 
	 return returned;
	 
 }
 
 string stringConvert (string word){ //converting string from upper to lower case
	 
	 for (int i=0; i < word.length(); i++){
		 word[i] = tolower(word[i]);
	 }
	 
	 return word;
 }
 
 string toUnderscore (string word){ //converting word to underscores
	 
	 for (int i=0; i < word.length(); i++){
		 word[i] = '_';
	 }
	 return word;
 }
 
 void printUnderscoreString (string underscore) { //printing underscores separately when display
	 
	 for (int i = 0; i < underscore.length(); i++){
		cout << underscore[i] << " ";
	 }

 
 }