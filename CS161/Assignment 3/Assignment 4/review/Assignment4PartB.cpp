//***********************************************************
//Program:  Assignment4PartB.cpp
//Author:  Devin Ascherl
//Date:  5/12/2019
//Description:  Takes an input and determines if it is an int, float, or string, and then capitalizes all letters in it.
//Input:  String of any type.
//Output:  If the input is a float, string, or int.  It also capitalizes all letters.
//**********************************************************


#include <iostream> //The standard library that allows input and output
#include <string>// This library allows us to use .length() of the strings.

//This is used for convenience.
using namespace std;

//This function determines if the input is an integer or not.
bool is_int(string Input)
{
     int Check = 0;
     for (int i = 0; i < Input.length(); i++)
     {
	  //This is the part that specifically checks if the input is an integer by comparing it to the numbers 0-9.  If there is anything else, check increases.
	  if (Input[i] >= '0' and Input[i] <= '9')
	  {
	       Check = Check;
	  }
	  else
	  {
	       //The increase in check tells the program to return false.
	       Check = Check + 1;
	  }
     }
     if (Check == 0)
     {
	  return true;
     }
     else
     {
	  return false;
     }
}

//This function determines if a program is a float.  It is the same as the int function, but has one additional command.
bool is_float(string Input)
{
     int Check = 0;
     int Periods = 0;
     int Count = 0;

     for (int i = 0; i < Input.length(); i++)
     {
	  //Here we check the number of periods.  All floats have exactly one decimal, so if there is more than one the program fails.
	  if (Input[i] == '.')
	  {
	       Periods = Periods + 1;
	  }

	  //This next part should look familiar, since it is the same as int, except we also add the period as valid inputs.

	  if (Periods > 1)
	  {
	       return false;
	  }

	  if (Input[i] >= '0' and Input[i] <= '9')
	  {
	       Count = Count + 1;
	  }

	  if (Input[i] >= '0' and Input[i] <='9' or Input[i] == '.')
	  {
	       Check = Check;
	  }
	  else
	  {
	       Check = Check + 1;
	  }
     }
     if (Check == 0 and Count > 1)
     {
	  return true;
     }
     else
     {
	  return false;
     }
}

//Here we check if a single character is an input or not.  Thanks to this, we had to remake our format, but the function works the same as the int function.
bool is_uppercase(char Input)
{
     //Here we see if the input is between A-Z.  If it is, we get a true return.  If not, we get a false.
     if (Input >= 'A' and Input <= 'Z')
     {     
	  return true;
     }
     else
     {
	  return false;
     }
}

//Here we check if numbers exist in the function.  It is similar to the int function, except that the return true is in the for loop.  This means that if the function detects any numbers, it returns a true on the first number input.
bool numbers_present(string Input)
{
     for (int i = 0; i < Input.length(); i++)
     {
	  if (Input[i] >= '0' and Input[i] <= '9')
	  {
	       return true;
	  }
     }
     //If no numbers are found, we return false.
     return false;
}

//This function changes an input from lowercase to uppercase.  It will take all inputs and check to see if they have an a-z in them.  If so, it changes their ASCII value by 32 to output an A-Z.  Unlike all of the other functions, it returns a string instead of true or false.
string to_upper(string Input)
{
     for (int i = 0; i < Input.length(); i++)
     {
	  if (Input[i] >= 'a' and Input[i] <= 'z')
	  {
	       Input[i] = Input[i] - 32;
	  }
     }
     return Input;
}

//This is our main function, which will take the input and call on the prior functions.
int main()
{
     //First we set up an input as a string.
     string Input;

     //Next, we ask the user to put in anything.  Yes, anything.
     cout << "Put in anything." << endl;
     cin >> Input;

     //First, we check if the input is an int or not.  If the function returns true, or 1, it is an int.  Otherwise it is not.
     if (is_int(Input) == 1)
     {
	  cout << "Your input is an int." << endl;
     }

     //If the int function returns a false, we don't have an int.
     else if (is_int(Input) == 0)
     {
	  cout << "Your input is not an int." << endl;
     }

     //Next we check if this input is a float.  This acts the same as the int above.
     if (is_float(Input) == 1)
     {
	  cout << "Your input is a float." << endl;
     }

     else if (is_float(Input) == 0)
     {
	  cout << "Your input is not a float." << endl;
     }

     //Here the format changes.  Since we had to make the function read individual characters instead of entire strings, we had to format it like a loop.  This will run for as long as the length of the input.
     for (int i = 0; i < Input.length(); i++)
     {
	  if (is_uppercase(Input[i]) == 1)
	  {
	       //This can lead to a very long output, but it is what is necessary to fulfil the requirements of the function.
	       cout << Input[i] << " is a capital letter." << endl;
	  }

	  else
	  {
	       cout << Input[i] << " is not a capital letter." << endl;
	  }
     }

     //Now we return to the format that was evident in prior parts of the program.  It checks for true or false, and if true then there are numbers in the input.
     if (numbers_present(Input) == 1)
     {
	  cout << "Numbers are present in your input." << endl;
     }
     else
     {
	  cout << "Numbers are not present in your input." << endl;
     }

     //Our last call to a function calls back to the to_upper function, and makes all of the characters capitalized.
     Input = to_upper(Input);

     //Our last step is to output the new input.  I realize I could have just done cout << Input << endl;, however I wanted another for loop.
     for (int i = 0; i < Input.length(); i++)
     {
	  cout << Input[i];
     }
     cout << endl;
     return 0;
}
