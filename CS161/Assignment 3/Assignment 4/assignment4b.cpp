/******************************************************************************
 * Program: assignment4b.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Functions for assignment 4 part B
 * Inputs: Test cases
 * Output: Test response
 * First Version: 05/06/2019
 * This Version: 05/10/2019
 ******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: isInt
** Description: checks if input string is int and returns bool.
** Parameters: string input
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of bool
*********************************************************************/ 
 bool isInt (string input){ //working
		

	 for (int i = 33; ((i>=33)&& (i <=47)); i++){ //checking for symbols 
		 for (int j =0; j < input.length(); j++){
			 if ((j==0)&&(int(input[j])== 45)){
				 continue;
			 }
			 int z = int(input[j]);
			 if (z == i){
				 return 0;
				 
			 }
		 }
	 }
	 
	 
	 for (int k = 58; ((k>=58)&& (k <=126)); k++){ //checking if it contains letters or extra symbols
		 for (int v =0; v < input.length(); v++){
			 if ((v==0)&&(int(input[v])== 45)){
				 continue;
			 }
			 int l = int(input[v]);
			 if (l == k){
				 return 0;
				 
			 }
		 }
	 }
	 
	 for (int i = 48; ((i>=48)&& (i <=57)); i++){//checking if it contains a number
		 for (int j =0; j < input.length(); j++){
			 int z = int(input[j]);
			 if (z == i){
				 return 1;
				 
			 }
		 }
	 }
	 
	 return 0;
	 
 }
 
 /*********************************************************************
** Function: isFloat
** Description: checks if input string is float and returns bool.
** Parameters: string input
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of bool
*********************************************************************/ 
 bool isFloat (string input){ //working
	 
	 for (int i = 0 ; i < input.length(); i++){//checks for repeated dots
		 int j = i+1;
		 for (; j < input.length();){
			 if ((input[i] == input[j])&& (int(input[i])==46)){
				 return 0;
			 }
			 else{
				 ++j;
			 }
		 }
	 }
	 for (int i = 33; ((i>=33)&& (i <=45)); i++){//check if it contains any symbols
		 for (int j =0; j < input.length(); j++){
			 int z = int(input[j]);
			 if (z == i){
				 return 0;
				 
			 }
		 }
	 }
	 
	 
	 for (int k = 58; ((k>=58)&& (k <=126)); k++){ //check if it contains extra symbols and letters.
		 for (int v =0; v < input.length(); v++){
			 int l = int(input[v]);
			 if (l == k){
				 return 0;
				 
			 }
		 }
	 }
	 
	 for (int p = 48; ((p>=48)&&(p <=57)); p++){//check if it contains a number with a dot next to it.
		 for (int g =0; g < input.length(); g++){
			 int u = g+1;
			 for (; u < input.length(); u++){
				 if ((int(input[g]) == p)&&(input[u] == '.')){
					 return 1;
				 }
			 }
		 }
	 }
	 
	 return 0;
	 
	 
 } 
 
 /*********************************************************************
** Function: isUppercase
** Description: checks if input char is uppercase and returns bool.
** Parameters: char input
** Pre-Conditions: Expected input of a valid char
** Post-Conditions: Expected return of bool
*********************************************************************/ 
 bool isUppercase (char input){ //working
	 
	 for (int i = 65; ((i>=65)&& (i <=90)); i++){//check if a character is uppercase
		 int z = int(input);
		 if (z == i){
				 
			 return 1;
				 
		 }
	 }
	 
	 return 0;
	 
 }
 
 /*********************************************************************
** Function: LettersPresent
** Description: checks if input string contains any letters and returns bool
** Parameters: string input
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of bool
*********************************************************************/ 
 bool lettersPresent (string input){//working
	 
	 for (int i = 65; ((i>=65)&& (i <=90)); i++){ //checks for upper case letters
		 for (int j =0; j < input.length(); j++){
			 int z = int(input[j]);
			 if (z == i){
				 return 1;
				 
			 }
		 }
	 }
	 for (int i = 97; ((i>=97)&& (i <=122)); i++){ //checks for lower case letters
		 for (int j =0; j < input.length(); j++){
			 int z = int(input[j]);
			 if (z == i){
				 return 1;
				 
			 }
		 }
	 }
	 return 0;
	 
 }
 
 /*********************************************************************
** Function: Numberspresent
** Description: checks if input string contains any numbers and returns bool
** Parameters: string input
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of bool
*********************************************************************/ 
 bool numbersPresent (string input){//working
	 
	 for (int i = '0'; ((i>='0')&& (i <='9')); i++){ //checks for numbers
		 for (int j =0; j < input.length(); j++){
			 int z = int(input[j]);
			 if (z == i){
				 return 1;
				 
			 }
		 }
	 }
	 
	 return 0;
	 
 }
 
/*********************************************************************
** Function: toUpper
** Description: changes every char from input string to uppercase
** Parameters: string input
** Pre-Conditions: Expected input of a valid string
** Post-Conditions: Expected return of string
*********************************************************************/ 
 string toUpper (string input) {//working
	 
	 for (int i = 0; i < input.length(); i++){
		 if ((input[i] < 'z')&&(input[i] > 'a')){
			 input[i] = char(int(input[i])-32);
		 }
	 }
	 return input;
 }
	
 int main() {
	 
	 //calling functions that return bool
	 int present = isInt("-1");
	 int past = isFloat(" 2.0.");
	 int upper = isUppercase('a');
	 int letters = lettersPresent("123");
	 int numbersPresent2 = numbersPresent("google1");
	 
	 //check toUppter function
	 string lower = "test";
	 cout << lower << endl;
	 string uppercase = toUpper(lower);
	 cout << uppercase << endl;
	 
	 //check NumbersPresent function
	 if (numbersPresent2 == 0) { 
		 cout << "Numbers not present"<< endl; 
	 }
	 else if (numbersPresent2 == 1){
		 cout << "Numbers present"<< endl; 
	 }
	 
	 //checking lettersPresent function
	 if (letters == 0) { 
		 cout << "Letters not present"<< endl; 
	 }
	 else if (letters == 1){
		 cout << "Letters present"<< endl; 
	 }
	 
	 //checking isInt function
	 if (present == 0) { 
		 cout << "Not int"<< endl; 
	 }
	 else if (present == 1){
		 cout << "Is int"<< endl; 
	 }
	 
	 //checking isFloat function
	 if (past == 0) {
		 cout << "Not float\n";
	 }
	 else if (past == 1){
		 cout << "Is Float\n";
	 }
	 
	 //checking isUppercase function
	 if (upper == 0){
		 cout <<  "Not upper case\n";
	 }
	 else if (upper ==1){
		 cout << "Upper case detected\n";
	 }
 }