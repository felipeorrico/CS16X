//how pointers work - remember how to use them
#include <iostream>
using namespace std;

void setPointerValueToFive(int *x)
{
    *x = 5;
}

void setValueToFiveWithReference(int &x)
{
    x = 5;
}


int main () {
	
	int x = 3;
	cout << "X is equal to " << x << " so far...\n";
	setPointerValueToFive(&x);
	cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
	// Outputs: The value of x is 5, setPointerValueToFive() modified x
	
	int x2 = 3;
	cout << "X2 is equal to " << x2 << " so far...\n";
	setValueToFiveWithReference( x2 );
	cout << "The value of x is " << x2 << ", setPointerValueToFive() modified x.\n";
	// Outputs: The value of x is 5, setPointerValueToFive() modified x
	
}