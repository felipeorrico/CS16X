/******************************************************
** Program: Assign4PartB.cpp
** Author: Noah Robertson
** Date: 5/12/2019
** Description: Contains functions that could be useful for future application
** Input: The user inputs various things to check for conditions or be converted.
** Output: The program outputs the converted value or check confirmation.
******************************************************/

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

bool numbers_present(string input_for_numbers_present);
bool is_int(string input_for_is_int);
bool is_float(string input_for_is_float);
bool is_uppercase(char input_for_is_uppercase);
bool letters_present(string input_for_letters_present);
string to_upper(string input_for_to_upper);

/********************************************************************
** Function: main
** Description: Where the other functions are executed.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a, program ends
*********************************************************************/
int main(){

    //Beginning of the test for numbers_present function
    string input_for_numbers_present;  //creates string variable named 'input'
    cout << "Enter a string to test whether or not it contains numbers: ";
    getline(cin,input_for_numbers_present);
    bool x = numbers_present(input_for_numbers_present);  //sets a boolean variable 'x' equal to the return value of the function numbers_present
    if(!x){
        cout << "No, this string does not contain numbers." << endl;
    }
    else if(x){
        cout << "Yes, this string contains numbers." << endl;
    }

    //Beginning of test for if input is integer
    string input_for_is_int;  //creates string variable named 'input_for_is_int'
    cout << "\nEnter something to check if it is an integer: ";
    getline(cin,input_for_is_int);
    x = is_int(input_for_is_int);
    if(!x){
        cout << "No, this is not an integer." << endl;
    }
    else if(x){
        cout << "Yes, this is an integer." << endl;
    }

    //Beginning of test for if input is float
    string input_for_is_float;
    cout << "\nEnter something to check if it is a float: ";
    getline(cin,input_for_is_float);
    x = is_float(input_for_is_float);
    if(!x){
        cout << "No, this is not a float." << endl;
    }
    else if(x){
        cout << "Yes, this is a float." << endl;
    }

    //Beginning of test for uppercase letter
    char input_for_is_uppercase;
    cout << "\nEnter a character to check if it is uppercase: ";
    cin >> input_for_is_uppercase;
    x = is_uppercase(input_for_is_uppercase);
    if(!x){
        cout << "No, this character is not uppercase." << endl;
    }
    else if(x){
        cout << "Yes, this character is uppercase." << endl;
    }

    //Beginning of test for characters in istringstring
    string input_for_letters_present;
    cout << "\nEnter a string to check if there are letters contained within it: ";
    getline(cin,input_for_letters_present);
    x = letters_present(input_for_letters_present);
    if(!x){
        cout << "No, there are not letters in this string." << endl;
    }
    else if(x){
        cout << "Yes, there are letters in this string." << endl;
    }

    //Beginning of conversion from non-capital letters in string to capital letters
    string input_for_to_upper;
    cout << "\nEnter a string, and all of its lowercase letters will be converted to uppercase: ";
    getline(cin,input_for_to_upper);
    cout << to_upper(input_for_to_upper) << endl;

return 0;
}// end of main function


/********************************************************************
** Function: numbers_present
** Description: checks to see if numbers are present in an entered string
** Parameters: a string must be entered
** Pre-Conditions: n/a
** Post-Conditions: corresponding response to the presence of numbers is printed in main function.
*********************************************************************/
bool numbers_present(string input_for_numbers_present){
    for(int i = 0; i <= input_for_numbers_present.length(); i++){  //the for loop checks every character in the string
        if(input_for_numbers_present[i] > '0' && input_for_numbers_present[i] < '9'){  //if the checked character is a number between 1 and 9, the function returns true
            return true;
        }
    }
    return false;  // if the for loop ran and didn't find any numbers, the function returns false

}  //end of function 'numbers_present'

/********************************************************************
** Function: is_int
** Description: Checks if the entered string is an integer
** Parameters: a string must be entered
** Pre-Conditions: n/a
** Post-Conditions: corresonding response based on if the string is an integer printed in main function.
*********************************************************************/
bool is_int(string input_for_is_int){
    for(int i = 0; i <= input_for_is_int.length(); i++){
        if(input_for_is_int[i] == '.' || isalpha(input_for_is_int[i])){  //if for loop finds a period in the entered number, then it declares that the number is not an integer
        return false;
        }
    }
    return true;
}  //end of function 'is_int'

/********************************************************************
** Function: is_float
** Description: Checks if the entered string is a float, not entirely accurate
** Parameters: a string must be entered
** Pre-Conditions: n/a
** Post-Conditions: corresponding response based on if the string is a float printed in main function.
*********************************************************************/
bool is_float(string input_for_is_float){
    for(int i = 0; i <= input_for_is_float.length(); i++){
        if(input_for_is_float[i] == '.'){
            return true;
        }
    }
    return false;
}

/********************************************************************
** Function: is_uppercase
** Description: checks if the entered character is uppercase.
** Parameters: a character must be entered
** Pre-Conditions: n/a
** Post-Conditions: corresponding response based on if the character is uppercase printed in main function.
*********************************************************************/
bool is_uppercase(char input_for_is_uppercase){
    int a = int(input_for_is_uppercase);
    if(a > 64 && a < 91){
        return true;
    }
    else{
        return false;
    }
}

/********************************************************************
** Function: letters_present
** Description: Checks if letters are present in the entered string
** Parameters: a string must be entered.
** Pre-Conditions: n/a
** Post-Conditions: corresponding response based on if there are letters in the string printed in main function.
*********************************************************************/
bool letters_present(string input_for_letters_present){
    for(int i = 0; i <= input_for_letters_present.length(); i++){
        int b = (input_for_letters_present[i]);
        if(b > 64 && b < 91){
            return true;
        }
        else if(b > 96 && b < 123){
            return true;
        }
    }
    return false;
}

/********************************************************************
** Function: to_upper
** Description: converts the characters in the entered string to uppercase
** Parameters: a string must be entered
** Pre-Conditions: n/a
** Post-Conditions: the string is printed in main with all uppercase characters.
*********************************************************************/
string to_upper(string input_for_to_upper){
    for(int i = 0; i <= input_for_to_upper.length(); i++){
        int c = (input_for_to_upper[i]);
        if(c > 96 && c < 123){
            input_for_to_upper[i] = c - 32;
        }
    }
return input_for_to_upper;
}
