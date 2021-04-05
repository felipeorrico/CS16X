/******************************************************************************
 * Program: Assignment2.cpp
 * Author: Felipe Orrico Scognamiglio
 * Description: Text game based on user integer input and chance. 
 * Inputs: 1 and 2 for choices
 * Output/: The result of your choices
 * Date: 04/08/2019
 ******************************************************************************/
 
 #include <cmath>
 #include <iostream>
 #include <string>
 #include <cstdlib>
 #include <ctime>
 
 using namespace std;
 
 int main () { //main function to execute everything
	int random;
	srand (time(NULL));
	random = rand() % 10 + 1;//generating random number.
	string player_name;
	cout << "Welcome to the Boss Fight Level! Please input your desired name: "<< endl;
	getline(cin,player_name); //getting input for name.
	cout << "Hello " << player_name << " ,you are the Elder Spell caster of the vast lands of Arcadia." << endl;
	cout << "There are two structures ahead of you. One is a BIG DARK CASTLE, the other is the entrance to a COAL MINE." << endl;
	cout << "Do you want to enter the BIG DARK CASTLE or the COAL MINE?" << endl;
	int boss_level;
	bool trigger = 0; //trigger for the first if statement
	do {
		if (trigger) {
			cout << "Please input a valid number: " << endl;
			//clear input in case of char being input instead of int
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << "Enter 1 to enter the BIG DARK CASTLE or 2 to enter the COAL MINE:" << endl;
		cin >> boss_level;
		trigger = 1;	
	} while (boss_level < 1 || boss_level > 2);
	if (boss_level == 1) { //if you chose to go to the castle this will be executed.
		cout << "You choose to enter the BIG DARK CASTLE. \n" << "You go inside and you see a red light in the distance. You start walking towards it and enter what looks like a church inside. The doors of the church close behind you, and you can hear what could only sound like the cry of a baby. As you get closer to the Altar the high pitch cry gets more intense, when you reach the altar a blinding red light begins to shine and moves towards you. The crying stops and a very deep voice begins to talk to you. 'Hello ";
		cout << player_name << ", I've been expecting you!" << endl;
		cout << "The Creature then grabs you by your neck and says 'Now we can finish this once and for all' then throws you away and you hit a wall." << endl;
		cout << "Do you want to cast a fireball at the creature or a lightning spell and see what happens?" << endl;
		int fight1; //int for fight 1
		bool trigger2 = 0;//trigger for first fight
		do { //fight 1
			if (trigger2){
				cout << "Please input valid number: " << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
		cout << "Enter 1 to cast the FIREBALL or 2 to cast a LIGHTINING SPELL" << endl;
		cin >> fight1;
		trigger2 = 1;
		} while (fight1 > 2 || fight1 < 1);
		if (fight1 == 1) { //if you choose fireball this will be executed.
			cout << "You cast a FIREBALL at the creature and the creature absorbs it! It says 'Do you think something that small can hurt me? you haven't seen anything!' After the Smoke clears you can see what the creature looks like. The creature is a Massive Gummi bear.  'It's now my turn, you fool!'" << endl;
			cout << "The Massive Gummi Bear breaks the altar and throws it in your direction with incredible speed. You can ether dodge it or send it back with a return spell." << endl;
			bool trigger3 = 0;
			int fight2;
			do { //fight 2
				if (trigger3){
					cout << "Please enter a valid number: " << endl;
					cin.clear();
					cin.ignore(10, '\n');
				}
				cout << "Enter 1 for DODGE or 2 for RETURN SPELL" << endl;
				cin >> fight2;
				trigger3 = 1;
			} while (fight2 > 2 || fight2 < 1);
			if (fight2 == 1) { //if you chose dodge this will be executed
				cout << "You manage to dodge the altar but barely. The Gummi bear then yells 'I wont be defeated by a mere spell caster! I'm much stronger than this!'. " << endl;
				cout << "The Massive Gummi Bear is angry and starts shooting Gummi Minions at you. \n You get hit and they start biting you. Their bites are poisonous and so you cant take more than a few." << endl;
				cout << "You can either choose to summon your own minions to destroy the Gummi minions or Launch a controllable ice spear at them so you can kill all of them with one hit." << endl;
				bool trigger4 =0;
				int fight3;
				do { //fight 3
					if (trigger4) {
						cout << "Please input a valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for MINIONS or 2 for ICE SPEAR" << endl;
					cin >> fight3;
					trigger4 = 1;
				} while (fight3 > 2 || fight3 < 1);
				if (fight3 == 1) { //if you chose minions this will be executed.
					cout << "You summon your minions and they manage to destroy their Gummi counterparts. However you took too long to do so and your blood is now filled with a deadly poison." << endl;
					cout << "You then remember that there is a spell that is very powerful but if used in the wrong way can get you killed. Since you already dyeing, you accept the powerful spell as an option. You can either Cast the Powerful Spell or go supernova." << endl;
					bool trigger5 = 0;
					int fight4;
					do { // fight 4
						if (trigger5) {
							cout << "Please input valid number: " << endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 to CAST THE SPELL or 2 for SUPERNOVA"<< endl;
						cin >> fight4;
						trigger5 = 1;
					} while (fight4 > 2 || fight4 < 1);
					if (fight4 == 1) { //if you choose to cast the spell this will be executed.
						if (random > 5) { //spell worked from random number
							cout << "Your spell worked! The Massive Gummi Bear then falls to its knees and melts. By his side there is the antidote to the poison." << endl;
							cout << "You Win "<< player_name << "! Here are your Spoils..." << endl;
							return 0;
						}
						else { //spell did not work
							cout << "Your Spell Failed! you died." << endl;
							cout << "This is the end of your journey in Arcadia "<< player_name << "." << endl;
							cout << "Thank you for playing!" << endl;
							return 0;
						}
					}
					else if (fight4 == 2) { //if you chose to go supernova this will be executed.
						cout << "You went Supernova and killed the boss, but also died due to the massive heat generated by the explosion." << endl;
						cout << "You sacrificed yourself so no one else would die for the Massive Gummi Bear!" << endl;
						cout << "Later as a token of gratitude the people of Arcadia gave you a Totem of immortality!" << endl;
						cout << "You now live an immortal life!" << endl;
						cout << "You Win!" << endl;
						return 0;	
					}
				}
				else if (fight3 == 2) { //if you chose to launch ice spear this will be executed.
					cout<< "You Launch the Ice spear and destroy all of the minions on time! The Massive Gummi Bear shoots the spear back at you and "<<endl;
					cout << "you realize you can't control it anymore. You can either try to control the spear or Dodge it and counter attack the Bear with "<<endl;
					cout << "your most powerful spell, the Rectifier."<<endl;
					bool trigger6 = 0;
					int fight5;
					do { //fight 5
						if (trigger6){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for CONTROL or 2 for DODGE" << endl;
						cin >> fight5;
						trigger6 = 1;
					} while (fight5 > 2 || fight5 < 1);
					if (fight5 == 1) { //if you chose to control this will be executed.
						cout << "You failed to control the spear and got Impaled by it" << endl;
						cout <<"This is the end of your journey in Arcadia "<< player_name<< endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
					else if (fight5 == 2) { //if you chose to dodge this will be executed.
						cout << "You dodge the spear and cast your spell. The Massive Gummi Bear then falls to its knees and melts" <<endl;
						cout << "You Win "<< player_name<< "Here are your spoils..." << endl;
						return 0;
					}
				}
			}
			else if (fight2 == 2 ){ //if you choose to cast return spell this will be executed.
				cout << "You cast the Return Spell and the Altar is sent back at the Massive Gummi Bear with incredible speed! The Bear then "<<endl;
				cout << "crushes it with a punch and releases a horde of Gummi Minions at you. You take some damage and they start biting you!"<<endl;
				cout << "You can either choose to summon your own minions to destroy the Gummi minions or Launch a controllable ice spear"<< endl;
				cout << "at them so you can kill all of them with one hit." << endl;
				bool trigger7 = 0;
				int fight6;
				do { //fight 6
					if (trigger7){
						cout << "Please input valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for MINIONS or 2 for ICE SPEAR"<< endl;
					cin >> fight6;
					trigger7 =1;
				} while (fight6 > 2 || fight6 < 1);
				if (fight6 == 1) { //if you chose minions this will be executed.
					cout << "You summon your minions and they manage to destroy their Gummi counterparts. The Massive bear then Launches a fireball at you." << endl;
					cout << "You can either Cast a Poisonous Fire Extinguish Spell or Dodge it." << endl;
					bool trigger8 =0;
					int fight7;
					do { //fight 7 starts here
						if (trigger8){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for SPELL or 2 for DODGE." << endl;
						cin >> fight7;
						trigger8 = 1;
					} while (fight7 > 2 || fight7 < 1);
					if (fight7 == 1){ //if you chose spell this will be executed.
						cout << "Your spell failed and the fireball killed you!" <<endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl; 
						cout << "Thank you for playing!"<< endl;
						return 0;
					}
					else if (fight7 == 2){ //if you chose dodge this will be executed.
						cout << "You dodged the fireball but did not realize that the ball curved. The fireball killed you!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
				}
				else if (fight6 == 2) { //if you chose ice spear this will be executed
					cout << "You Launch the Ice spear and destroy all of the minions on time! The Massive Gummi Bear shoots the spear back at you and "<<endl;
					cout << "you realize you can't control it anymore. You can either try to control the spear or Dodge it and counter attack the Bear with" <<endl;
					cout << "your most powerful spell, the Rectifier."<<endl;
					bool trigger9 = 0;
					int fight8;
					do { //fight 8 begins
						if (trigger9) { 
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for CONTROL or 2 for DODGE."<<endl;
						cin >> fight8;
						trigger9 = 1;
					} while (fight8 > 2 || fight8 < 1);
					if (fight8 == 1){ //if you chose control this will be executed
						cout << "You failed to control the spear and got Impaled by it."<< endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
					else if (fight8 == 2) { //if you chose dodge this will be executed
						cout << "You dodge the Spear and cast your spell. The Massive Gummi Bear then falls to its knees and melts." << endl;
						cout << "You win! Here are your spoils..."<<endl;
						return 0;
					}
				}
			}
			
		}
		else if (fight1 == 2) { //begin second line. if you chose lighting spell this will be executed.
			cout << "You Cast a Lightning Spell that makes the creature yell in rage 'I wont be defeated by a mere spell caster!" <<endl;
			cout << "I'm much stronger than this!'. You can smell this burnt sugar smell from the beast's skin and realize" <<endl;
			cout << "that you are dealing with something very dangerous, a Massive Gummi Bear."<< endl;
			cout << "The Massive Gummi Bear is angry and starts shooting Gummi Minions at you." << endl;
			cout << "You get hit and they start biting you. Their bites are poisonous and so you cant take more than a few." << endl;
			cout << "You can either choose to summon your own minions to destroy the Gummi minions or Launch a controllable ice spear"<< endl;
			cout << "at them so you can kill all of them with one hit." <<endl;
			bool trigger3 = 0;
			int fight2;
			do { //fight 2
				if (trigger3){
					cout << "Please enter a valid number: " << endl;
					cin.clear();
					cin.ignore(10, '\n');
				}
				cout << "Enter 1 for MINIONS or 2 for ICE SPEAR" << endl;
				cin >> fight2;
				trigger3 = 1;
			} while (fight2 > 2 || fight2 < 1);
			if (fight2 == 1) { //if you chose minions this will be executed.
				cout << "You summon your minions and they manage to destroy their Gummi counterparts. However you took too long to do so ";
				cout << "and your blood is now filled with a deadly poison." << endl;
				cout << "You then remember that there is a spell that is very powerful but if used in the wrong way can get you killed. Since " << endl;
				cout << "you already dyeing, you accept the powerful spell as an option. You can either Cast the Powerful Spell or go supernova." << endl;
				bool trigger4 =0;
				int fight3;
				do { //fight 3
					if (trigger4) {
						cout << "Please input a valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for CAST THE SPELL or 2 for SUPERNOVA" << endl;
					cin >> fight3;
					trigger4 = 1;
				} while (fight3 > 2 || fight3 < 1);
				if (fight3 == 1) { //if you chose the spell this will be executed
					cout << "Your Spell failed! But somehow you did not die! The Bear now desperate charges at you with its fist. You can either cast"<< endl;
					cout << "a lightning sword spell or a fire sword spell to kill it." << endl;
					bool trigger5 = 0;
					int fight4;
					do { // fight 4
						if (trigger5) {
							cout << "Please input valid number: " << endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 to LIGHTNING or 2 for FIRE"<< endl;
						cin >> fight4;
						trigger5 = 1;
					} while (fight4 > 2 || fight4 < 1);
					if (fight4 == 1) { //if you chose lightning random will be executed from below
						if (random > 5) { //spell worked
							cout << "Your spell worked! The Massive Gummi Bear died. By his side there is the antidote to the poison." << endl;
							cout << "You Win "<< player_name << "! Here are your Spoils..." << endl;
							return 0;
						}
						else { //spell did not work
							cout << "Your Spell Failed! you died." << endl;
							cout << "This is the end of your journey in Arcadia "<< player_name << "." << endl;
							cout << "Thank you for playing!" << endl;
							return 0;
						}
					}
					else if (fight4 == 2) { //if you chose fire this will be executed.
						cout << "You damaged the Bear but it was not enough! The Bear then separated your head from your body!" << endl;
						cout << "You Died!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for Playing!" << endl;
						return 0;	
					}
				}
				else if (fight3 == 2) { //if you chose supernova this will be executed.
					cout<< "You could not go supernova! There was some kind of limiting factor! "<<endl;
					cout << "The Bear now desperate charges at you with its fist. You can either cast "<<endl;
					cout << "a lightning sword spell or a fire sword spell to kill it."<<endl;
					bool trigger6 = 0;
					int fight5;
					do { //fight 5
						if (trigger6){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for LIGHTNING or 2 for FIRE" << endl;
						cin >> fight5;
						trigger6 = 1;
					} while (fight5 > 2 || fight5 < 1);
					if (fight5 == 1) { //if you chose lightning.
						cout << "You damaged the Bear but it was not enough! The Bear then separated your head from your body!" << endl;
						cout <<"You Died "<< player_name<< endl;
						cout << "This is the end of your journey in Arcadia " << player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
					else if (fight5 == 2) { //if you chose fire.
						cout << "You Destroyed the monster "<< player_name << "!" <<endl;
						cout << "You Win! Here are your spoils..." << endl;
						return 0;
					}
				}
			}
			else if (fight2 == 2 ){ //if you chose ice spear this will be executed.
				cout << "You Launch the Ice Spear, but the Bear is too strong! The Spear was not effective!" << endl;
				cout << "The bear gets angry and shoots a chunk of Gummi substance at you!" << endl;
				cout << "You can either Dodge the Gummi substance or cast the ultra eating spell." << endl;
				bool trigger7 = 0;
				int fight6;
				do { //fight 6
					if (trigger7){
						cout << "Please input valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for DODGE or 2 for SPELL"<< endl;
					cin >> fight6;
					trigger7 =1;
				} while (fight6 > 2 || fight6 < 1);
				if (fight6 == 1) { //if you chose dodge this will be executed.
					cout << "You dodge the chunk of Gummi. The Bear then launches a fireball at you." << endl;
					cout << "You can either Cast a Poisonous Fire Extinguish Spell or Dodge it." << endl;
					bool trigger8 =0;
					int fight7;
					do { //fight 7 starts here
						if (trigger8){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for SPELL or 2 for DODGE." << endl;
						cin >> fight7;
						trigger8 = 1;
					} while (fight7 > 2 || fight7 < 1);
					if (fight7 == 1){ //if you chose spell this will be executed
						cout << "Your spell failed and the fireball killed you!" <<endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl; 
						cout << "Thank you for playing!"<< endl;
						return 0;
					}
					else if (fight7 == 2){ //if you chose fireball this will be executed.
						cout << "You dodged the fireball but did not realize that the ball curved. The fireball killed you!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
				}
				else if (fight6 == 2) { //if you chose ultra eating this will be executed.
					cout << "You cast the ultra eating spell. You ate the whole chunk! "<<endl;
					cout << "you realize you can't walk anymore, the Gummi paralyzed your legs. you can either accept your faith or cast " <<endl;
					cout << "your most powerful spell, the Rectifier and rectify your legs."<<endl;
					bool trigger9 = 0;
					int fight8;
					do { //fight 8 begins
						if (trigger9) {
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for FAITH or 2 for RECTIFIER."<<endl;
						cin >> fight8;
						trigger9 = 1;
					} while (fight8 > 2 || fight8 < 1);
					if (fight8 == 1){ //if you chose faith this will be executed
						cout << "Your legs did not work anymore"<< endl;
						cout << "The Gummi bear separated your head from your body. You died." << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
					else if (fight8 == 2) { //if you chose RECTIFIER this will be executed.
						cout << "Your Rectifier spell did not work. The Gummi Bear then separated your head from your body. You Died." << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
				}
			}
		
			
		}
	}
	else if (boss_level == 2){ // if you chose to go to the mine this will be executed.
		cout << "You Chose to enter the Coal Mine! As you enter the mine you can hear a bone-chilling sound." << endl;
		cout << "As you go deeper into the mine, the sound grows louder."<<endl;
		cout << "'I've been expecting you' the boss says just before it reveals itself."<<endl;
		cout << "The Monster is a Giant Undead Easter Bunny."<<endl;
		cout << "The Bunny dashes towards you and kicks you."<< endl;
		cout << "You hit a wall. Now It's time to counterattack you can either cast a lightning strike or a water cannon spell." << endl;
		int fight1; //int for fight 1
		bool trigger2 = 0;//trigger for first fight
		do { //fight 1
			if (trigger2){
				cout << "Please input valid number: " << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
		cout << "Enter 1 to cast the LIGHTNING STRIKE or 2 to cast a WATERCANNON SPELL" << endl;
		cin >> fight1;
		trigger2 = 1;
		} while (fight1 > 2 || fight1 < 1);
		if (fight1 == 1) { //if you choose fireball this will be executed.
			cout << "You cast a Lightning strike at the creature and the creature absorbs it! It says 'Do you think something that small can hurt me? you haven't seen anything!' 'It's now my turn, you fool!'" << endl;
			cout << "The bunny then sends back the lightning spell at you. You can either dodge the attack or cast a shield spell." << endl;
			bool trigger3 = 0;
			int fight2;
			do { //fight 2
				if (trigger3){
					cout << "Please enter a valid number: " << endl;
					cin.clear();
					cin.ignore(10, '\n');
				}
				cout << "Enter 1 for DODGE or 2 for SHIELD SPELL" << endl;
				cin >> fight2;
				trigger3 = 1;
			} while (fight2 > 2 || fight2 < 1);
			if (fight2 == 1) { //if you chose dodge this will be executed
				cout << "You manage to dodge the strike but barely. The bunny 'I wont be defeated by a mere spell caster! I'm much stronger than this!'. " << endl;
				cout << "The Bunny Bear is angry and starts shooting Minion Miners at you. \n You get hit and they start grabbing you." << endl;
				cout << "You can either choose to summon your own minions to destroy the Gummi minions or Launch a controllable ice spear at them so you can kill all of them with one hit." << endl;
				bool trigger4 =0;
				int fight3;
				do { //fight 3
					if (trigger4) {
						cout << "Please input a valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for MINIONS or 2 for ICE SPEAR" << endl;
					cin >> fight3;
					trigger4 = 1;
				} while (fight3 > 2 || fight3 < 1);
				if (fight3 == 1) { //if you chose minions this will be executed.
					cout << "You summon your minions and they manage to destroy their miner counterparts." << endl;
					cout << "You then remember that there is a spell that is very powerful but if used in the wrong way can get you killed. Since you already hurt, you accept the powerful spell as an option. You can either Cast the Powerful Spell or go supernova." << endl;
					bool trigger5 = 0;
					int fight4;
					do { // fight 4
						if (trigger5) {
							cout << "Please input valid number: " << endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 to CAST THE SPELL or 2 for SUPERNOVA"<< endl;
						cin >> fight4;
						trigger5 = 1;
					} while (fight4 > 2 || fight4 < 1);
					if (fight4 == 1) { //if you choose to cast the spell this will be executed.
						if (random > 5) { //spell worked from random number
							cout << "Your spell worked! The Bunny then falls to its knees and crumbles into ashes." << endl;
							cout << "You Win "<< player_name << "! Here are your Spoils..." << endl;
							return 0;
						}
						else { //spell did not work
							cout << "Your Spell Failed! you died." << endl;
							cout << "This is the end of your journey in Arcadia "<< player_name << "." << endl;
							cout << "Thank you for playing!" << endl;
							return 0;
						}
					}
					else if (fight4 == 2) { //if you chose to go supernova this will be executed.
						cout << "You went Supernova and killed the boss, but also died due to the massive heat generated by the explosion." << endl;
						cout << "You sacrificed yourself so no one else would die for the Giant Undead Easter Bunny!" << endl;
						cout << "Later as a token of gratitude the people of Arcadia gave you a Totem of immortality!" << endl;
						cout << "You now live an immortal life!" << endl;
						cout << "You Win!" << endl;
						return 0;	
					}
				}
				else if (fight3 == 2) { //if you chose to launch ice spear this will be executed.
					cout<< "You Launch the Ice spear and destroy all of the minions on time! The Giant Undead Easter Bunny shoots the spear back at you and "<<endl;
					cout << "you realize you can't control it anymore. You can either try to control the spear or Dodge it and counter attack the Bunny with "<<endl;
					cout << "your most powerful spell, the Rectifier."<<endl;
					bool trigger6 = 0;
					int fight5;
					do { //fight 5
						if (trigger6){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for CONTROL or 2 for DODGE" << endl;
						cin >> fight5;
						trigger6 = 1;
					} while (fight5 > 2 || fight5 < 1);
					if (fight5 == 1) { //if you chose to control this will be executed.
						cout << "You failed to control the spear and got Impaled by it" << endl;
						cout <<"This is the end of your journey in Arcadia "<< player_name<< endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
					else if (fight5 == 2) { //if you chose to dodge this will be executed.
						cout << "You dodge the spear and cast your spell. TheGiant Undead Easter Bunny then falls to its knees and crumbles into ashes" <<endl;
						cout << "You Win "<< player_name<< "Here are your spoils..." << endl;
						return 0;
					}
				}
			}
			else if (fight2 == 2 ){ //if you choose to cast shield spell this will be executed.
				cout << "You cast the Shield Spell and the lightning strike ricochets directed to the Giant Undead Easter Bunny. The bunny then"<<endl;
				cout << "Absorbs it with its hand and releases a horde of Minion Miners at you. You take some damage and they start grabbing you!"<<endl;
				cout << "You can either choose to summon your own minions to destroy the Miner minions or Launch a controllable ice spear"<< endl;
				cout << "at them so you can kill all of them with one hit." << endl;
				bool trigger7 = 0;
				int fight6;
				do { //fight 6
					if (trigger7){
						cout << "Please input valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for MINIONS or 2 for ICE SPEAR"<< endl;
					cin >> fight6;
					trigger7 =1;
				} while (fight6 > 2 || fight6 < 1);
				if (fight6 == 1) { //if you chose minions this will be executed.
					cout << "You summon your minions and they manage to destroy their miner counterparts. The Giant Undead Easter Bunny then Launches a fireball at you." << endl;
					cout << "You can either Cast a Poisonous Fire Extinguish Spell or Dodge it." << endl;
					bool trigger8 =0;
					int fight7;
					do { //fight 7 starts here
						if (trigger8){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for SPELL or 2 for DODGE." << endl;
						cin >> fight7;
						trigger8 = 1;
					} while (fight7 > 2 || fight7 < 1);
					if (fight7 == 1){ //if you chose spell this will be executed.
						cout << "Your spell failed and the fireball killed you!" <<endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl; 
						cout << "Thank you for playing!"<< endl;
						return 0;
					}
					else if (fight7 == 2){ //if you chose dodge this will be executed.
						cout << "You dodged the fireball but did not realize that the ball curved. The fireball killed you!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
				}
				else if (fight6 == 2) { //if you chose ice spear this will be executed
					cout << "You Launch the Ice spear and destroy all of the minions on time! The Giant Undead Easter Bunny shoots the spear back at you and "<<endl;
					cout << "you realize you can't control it anymore. You can either try to control the spear or Dodge it and counter attack the Bear with" <<endl;
					cout << "your most powerful spell, the Rectifier."<<endl;
					bool trigger9 = 0;
					int fight8;
					do { //fight 8 begins
						if (trigger9) { 
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for CONTROL or 2 for DODGE."<<endl;
						cin >> fight8;
						trigger9 = 1;
					} while (fight8 > 2 || fight8 < 1);
					if (fight8 == 1){ //if you chose control this will be executed
						cout << "You failed to control the spear and got Impaled by it."<< endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
					else if (fight8 == 2) { //if you chose dodge this will be executed
						cout << "You dodge the Spear and cast your spell. The Giant Undead Easter Bunny then falls to its knees and crumbles into a pile of ash." << endl;
						cout << "You win! Here are your spoils..."<<endl;
						return 0;
					}
				}
			}
			
		}
		else if (fight1 == 2) { //begin second line. if you chose lighting spell this will be executed.
			cout << "You Cast a Lightning Spell that makes the creature yell in rage 'I wont be defeated by a mere spell caster!" <<endl;
			cout << "I'm much stronger than this!'." <<endl;
			cout << "The Giant Undead Easter Bunny is angry and starts shooting Minion Miners at you." << endl;
			cout << "You get hit and they start grabbing you." << endl;
			cout << "You can either choose to summon your own minions to destroy the minion miners or Launch a controllable ice spear"<< endl;
			cout << "at them so you can kill all of them with one hit." <<endl;
			bool trigger3 = 0;
			int fight2;
			do { //fight 2
				if (trigger3){
					cout << "Please enter a valid number: " << endl;
					cin.clear();
					cin.ignore(10, '\n');
				}
				cout << "Enter 1 for MINIONS or 2 for ICE SPEAR" << endl;
				cin >> fight2;
				trigger3 = 1;
			} while (fight2 > 2 || fight2 < 1);
			if (fight2 == 1) { //if you chose minions this will be executed.
				cout << "You summon your minions and they manage to destroy their miner counterparts." << endl;
				cout << "You then remember that there is a spell that is very powerful but if used in the wrong way can get you killed. Since " << endl;
				cout << "you already hurt, you accept the powerful spell as an option. You can either Cast the Powerful Spell or go supernova." << endl;
				bool trigger4 =0;
				int fight3;
				do { //fight 3
					if (trigger4) {
						cout << "Please input a valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for CAST THE SPELL or 2 for SUPERNOVA" << endl;
					cin >> fight3;
					trigger4 = 1;
				} while (fight3 > 2 || fight3 < 1);
				if (fight3 == 1) { //if you chose the spell this will be executed
					cout << "Your Spell failed! But somehow you did not die! The Giant Undead Easter Bunny now desperate charges at you with its fist. You can either cast"<< endl;
					cout << "a lightning sword spell or a fire sword spell to kill it." << endl;
					bool trigger5 = 0;
					int fight4;
					do { // fight 4
						if (trigger5) {
							cout << "Please input valid number: " << endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 to LIGHTNING or 2 for FIRE"<< endl;
						cin >> fight4;
						trigger5 = 1;
					} while (fight4 > 2 || fight4 < 1);
					if (fight4 == 1) { //if you chose lightning random will be executed from below
						if (random > 5) { //spell worked
							cout << "Your spell worked! The Giant Undead Easter Bunny died." << endl;
							cout << "You Win "<< player_name << "! Here are your Spoils..." << endl;
							return 0;
						}
						else { //spell did not work
							cout << "Your Spell Failed! you died." << endl;
							cout << "This is the end of your journey in Arcadia "<< player_name << "." << endl;
							cout << "Thank you for playing!" << endl;
							return 0;
						}
					}
					else if (fight4 == 2) { //if you chose fire this will be executed.
						cout << "You damaged the bunny but it was not enough! The Giant Undead Easter Bunny then kicked your head from your body!" << endl;
						cout << "You Died!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for Playing!" << endl;
						return 0;	
					}
				}
				else if (fight3 == 2) { //if you chose supernova this will be executed.
					cout<< "You could not go supernova! There was some kind of limiting factor! "<<endl;
					cout << "The Giant Undead Easter Bunny now desperate charges at you with its fist. You can either cast "<<endl;
					cout << "a lightning sword spell or a fire sword spell to kill it."<<endl;
					bool trigger6 = 0;
					int fight5;
					do { //fight 5
						if (trigger6){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for LIGHTNING or 2 for FIRE" << endl;
						cin >> fight5;
						trigger6 = 1;
					} while (fight5 > 2 || fight5 < 1);
					if (fight5 == 1) { //if you chose lightning.
						cout << "You damaged the Bunny but it was not enough! The Bunny then kicked off your head from your body!" << endl;
						cout <<"You Died "<< player_name<< endl;
						cout << "This is the end of your journey in Arcadia " << player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
					else if (fight5 == 2) { //if you chose fire.
						cout << "You Destroyed the monster "<< player_name << "!" <<endl;
						cout << "You Win! Here are your spoils..." << endl;
						return 0;
					}
				}
			}
			else if (fight2 == 2 ){ //if you chose ice spear this will be executed.
				cout << "You Launch the Ice Spear, but the Giant Undead Easter Bunny is too strong! The Spear was not effective!" << endl;
				cout << "The bear gets angry and shoots a chunk of bunny poop at you!" << endl;
				cout << "You can either Dodge the poop or cast the ultra cleaning spell." << endl;
				bool trigger7 = 0;
				int fight6;
				do { //fight 6
					if (trigger7){
						cout << "Please input valid number: "<< endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
					cout << "Enter 1 for DODGE or 2 for SPELL"<< endl;
					cin >> fight6;
					trigger7 =1;
				} while (fight6 > 2 || fight6 < 1);
				if (fight6 == 1) { //if you chose dodge this will be executed.
					cout << "You dodge the chunk of poop. The Giant Undead Easter Bunny then launches a fireball at you." << endl;
					cout << "You can either Cast a Poisonous Fire Extinguish Spell or Dodge it." << endl;
					bool trigger8 =0;
					int fight7;
					do { //fight 7 starts here
						if (trigger8){
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for SPELL or 2 for DODGE." << endl;
						cin >> fight7;
						trigger8 = 1;
					} while (fight7 > 2 || fight7 < 1);
					if (fight7 == 1){ //if you chose spell this will be executed
						cout << "Your spell failed and the fireball killed you!" <<endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl; 
						cout << "Thank you for playing!"<< endl;
						return 0;
					}
					else if (fight7 == 2){ //if you chose fireball this will be executed.
						cout << "You dodged the fireball but did not realize that the ball curved. The fireball killed you!" << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!" << endl;
						return 0;
					}
				}
				else if (fight6 == 2) { //if you chose ultra cleaning this will be executed.
					cout << "You cast the ultra cleaning spell. You cleaned the whole chunk! "<<endl;
					cout << "you realize you can't walk anymore, the a bacteria in the poop paralyzed your legs. you can either accept your faith or cast " <<endl;
					cout << "your most powerful spell, the Rectifier and rectify your legs."<<endl;
					bool trigger9 = 0;
					int fight8;
					do { //fight 8 begins
						if (trigger9) {
							cout << "Please input valid number: "<< endl;
							cin.clear();
							cin.ignore(10, '\n');
						}
						cout << "Enter 1 for FAITH or 2 for RECTIFIER."<<endl;
						cin >> fight8;
						trigger9 = 1;
					} while (fight8 > 2 || fight8 < 1);
					if (fight8 == 1){ //if you chose faith this will be executed
						cout << "Your legs did not work anymore"<< endl;
						cout << "The Giant Undead Easter Bunny kicked off your head from your body. You died." << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
					else if (fight8 == 2) { //if you chose RECTIFIER this will be executed.
						cout << "Your Rectifier spell did not work. The Giant Undead Easter Bunny then kicked off your head from your body. You Died." << endl;
						cout << "This is the end of your journey in Arcadia "<< player_name << endl;
						cout << "Thank you for playing!	"<< endl;
						return 0;
					}
				}
			}
		
			
		}
	}
	return 0;
}
