bool trigger = 0; //when this is zero the if statement below is false
if (play1 == 'C' || play1 == 'c') { 
			do {
				if (trigger) { //happens when the bool is different than zero
					cout << "Please input valid amount..." << endl;
					cin.clear(); //clears the input
					cin.ignore(100, '\n'); //ignores the input in 100 characters
				}
				cout << "How many Stones do you want to remove from pile C?" << endl; //prompts the amount of stones to remove
				cin >> stones; //player input
				trigger = 1; //sets the trigger different than zero and 
			} while (stones > c || stones > 3 || stones < 1);
			trigger = 0;
			c = c - stones;
		}