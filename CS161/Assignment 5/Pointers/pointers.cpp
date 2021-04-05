#include <iostream>
using namespace std;

float *outOfPocketTotal (float spent, float reimbursed) {
	
	float *returned = new float[1];
	
	returned [0] = spent - reimbursed;
	
	return returned;
	
}

int main() {
	
	float spent;
	float reimbursed;
	bool trigger = 0;
	
	do {
		
		if (trigger){
			cout << endl;
			cout << "ERROR - Please input valid amounts.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		
		cout << "Please input value spent: ";
		cin >> spent;
		cout << endl;
		cout << "Please input the value reimbursed: ";
		cin >> reimbursed;
		cout << endl;	
	
		trigger = 1;
		
	} while ((reimbursed > spent)||(reimbursed < 0)|| (spent < 0));

	float *total = outOfPocketTotal(spent, reimbursed);
	float totals = total[0];
	delete[] total;
	
	cout << "You spent a total of $" << spent << " and was reimbursed a total of $" << reimbursed << ". Your final expenses were $" << totals << endl;
	
	
}