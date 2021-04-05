#include <iostream>
using namespace std;

void outOfPocketTotal (float &spent, float &reimbursed, float &totals) {
	
	totals = spent - reimbursed;
	
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

	
	float totals;
	
	outOfPocketTotal (spent, reimbursed, totals);
	
	cout << "You spent a total of $" << spent << " and was reimbursed a total of $" << reimbursed << ". Your final expenses were $" << totals << endl;
	
	
}