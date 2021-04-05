/******************************************************************************
 * Program: Assignment4.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Hangman game with '2' players. One chooses the word, the other guesses it.
 * Inputs: any letter for the guess
 * Output: The remaining chances and the game status.
 * First Version: 
 * This Version:
 ******************************************************************************/
 
 #include <iostream>
 #include <ctime>
 #include <string>
 #include <cstdlib>
 #include <boost/lexical_cast.hpp>
 
 using namespace std;
 
 string toUnderscore (string word);
 
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
 
 string* checkLetterFunction (string guess, string word, string underscore, string usedLetters, int tries){ 
 
	 string underscoreCopy = underscore;
	
	 string* returned = new string[4];
	 
	 string winVerification = "WIN";
	 
	 if (guess.length() > 1) { //working
		 if (guess == word){
			 cout << "You guessed the right word!\n";
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
				 
				 underscore[i] = word [i]; //this should make change the underscores to the letter if correct.
				 
			 }
		 }	
	 }
	 
	 if (underscoreCopy == underscore){
		 
		 usedLetters += guess;
		
		 usedLetters = checkForRepetition(usedLetters);
		 
		 --tries;
	 }
	 
	 if (underscore == word) {
		 
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
 
 int main(){
	 
	 string playerName;
	 string bossName;
	 string word;
	 string guess;
	 string usedLetters;
	 string win = "WIN";
	 
	 int tries;
	 
	 word = "rogue";
	 
	 string underscore = toUnderscore(word);
	 
	 system ("clear");
	 
	 tries = word.length() + 1;
	 
	 cout << "***********************************************************************\n";
	 cout << "* Welcome to the HANGMAN Game!                                        *"<<endl;
	 cout << "* Guess the word. The word has " << word.length() << " letters                              *"<< endl;
	 cout << "* You may guess a letter or a whole word, just keep in mind that      *\n* if you input more than one letter, it will be considered as a word. *" << endl;
	 cout << "***********************************************************************\n";
	 
	 while (tries > 0) {
		 
		 string winVerification;
		 
		 cout << "*************************************************\n";
		 cout << "* Hangman: "; printUnderscoreString(underscore); cout << "                           *\n";
		 cout << "* Used Letters: "; printUnderscoreString(usedLetters); cout << endl;
		 cout << "* Please input a word guess or a single letter. *\n";
		 cout << "*************************************************\n";
		 
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
		 
		 string* gamePlay = checkLetterFunction(guess, word, underscore, usedLetters, tries);
		 
		 winVerification = gamePlay[0];
		 underscore = gamePlay[1];
		 usedLetters = gamePlay[2];
		 tries = atoi(gamePlay[3].c_str());
		 delete[] gamePlay;
		 
		 if (winVerification == win){
			 cout << "*********************\n";
			 cout << "* You Won the Game! *" << endl;
			 cout << "*********************\n";
			 return 0;
		 }
		 
	 }
	 
	 cout << "************************************\n";
	 cout << "* You ran out of tries! Game Over! *" << endl;
	 cout << "************************************\n";
	 
	 return 0;

 }