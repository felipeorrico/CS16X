#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "pokedex.h"

using namespace std;

int main(int cmda, char* cmdb[]) {
	
	if(cmda > 3){
		cout << "\n\033[22;31mError - Too many arguments!\033[01;37m\n\n" << "\nPlease use: ./pokedex <hunter file> <monster file>\n\n"; 
		return 0;
	}
	int end = run_program(cmdb);
	switch (end) { 
        case 1: cout << "\033[22;31mError - An Error Occurred when trying to open Hunter file!\033[01;37m - The program will now Exit!" << endl; 
				break; 
        case 2: cout << "\033[22;31mError - An Error Occurred when trying to open Monster file!\033[01;37m - The program will now Exit!" << endl;
                break; 
        case 3: cout << "\033[22;31mError - An Error Occurred when trying to open BOTH files!\033[01;37m - The program will now Exit!" << endl;
				break;
		case 4: cout << "\033[22;31mLogin Attempt Error\033[01;37m - Please Restart the Program and Try Again!\n";
				break;
        default: printf("\n\n\033[22;31m- End of Program -\033[01;37m\n\n"); 
                break;   
    } 
	return 0;
}