#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

//function declarations (needed for each one you write)
void thingsforall(string s);
void shop();

//global variables (in general, not a good idea, but for this small of a game, ok)
string inventory[5];
string wall = "Oops you ran into a wall";

int main() {

	int room = 1;
	string input;

	cout << "You wake up to find yourself in a SPOOPY dungeon. Can you escape? Good luck!" << "\n" << "If you want to know what commands you can do type help" << endl;

	do {
		switch (room) {
		case 1:
			cout << "You are in room 1. Your Goal is to get to room 11." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 2;
			else if (input.compare("~") == 0)
				room = 11;
			else
				thingsforall(input);
			break;
		case 2:
			cout << "You are in room 2." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 1;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 3;
			else
				thingsforall(input);
			break;
		case 3:
			cout << "You are in room 3." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 5;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0) {
				if (inventory[0].compare("key") != 0) {
					cout << "The door is locked." << endl;
				}
				else
					room = 4;
			}
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 2;
			else if (input.compare("look") == 0)
				cout << "You see a door to the east." << endl;
			else
				thingsforall(input);
			break;
		case 4:
			cout << "You are in room 4." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 3;
			else if (input.compare("look") == 0)
				cout << "You see a chest in the corner." << endl;
			else if (input.compare("open") == 0) {
				inventory[1] = "gold";
				cout << "You found some gold." << endl;
			}
			else
				thingsforall(input);
			break;
		case 5:
			cout << "You are in room 5." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 6;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 3;
			else if (input.compare("pickup") == 0) {
				inventory[0] = "key";
				cout << "You picked up key off the ground." << endl;
			}
			else if (input.compare("look") == 0)
				cout << "You see a key on the ground." << endl;
			else
				thingsforall(input);
			break;
		case 6:
			cout << "You are in room 6." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 5;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 7;
			else
				thingsforall(input);
			break;
		case 7:
			cout << "You are in room 7." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 8;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 6;
			else
				thingsforall(input);
			break;
		case 8:
			cout << "You are in room 8." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 7;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 9;
			else
				thingsforall(input);
			break;
		case 9:
			cout << "You are in room 9." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 10;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 8;
			else
				thingsforall(input);
			break;
		case 10:
			cout << "You are in room 10." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 9;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 11;
			else
				thingsforall(input);
			break;
		case 11:
			cout << "Congratulations you win!" << endl;
			cout << "When you are ready type quit" << endl;
			getline(cin, input);
			break;
		}
	} while (input.compare("quit") != 0);
}

void thingsforall(string s) {
	if (s.compare("go north") == 0 || s.compare("north") == 0 || s.compare("n") == 0)
		cout << wall << endl;
	else if (s.compare("go south") == 0 || s.compare("south") == 0 || s.compare("s") == 0)
		cout << wall << endl;
	else if (s.compare("go east") == 0 || s.compare("east") == 0 || s.compare("e") == 0)
		cout << wall << endl;
	else if (s.compare("go west") == 0 || s.compare("west") == 0 || s.compare("w") == 0)
		cout << wall << endl;
	else if (s.compare("look") == 0)
		cout << "You don't see anything special." << endl;
	else if (s.compare("inventory") == 0)
		for (int i = 0; i < 5; i++) {
			cout << inventory[i] << endl;
		}
	else if (s.compare("help") == 0) {
		cout << "The commands you can do are:" << endl;
		cout << "go north, go south, go east, go west, north, south, east, west, n, s, e, w" << endl;
		cout << "look" << endl;
		cout << "pickup" << endl;
		cout << "open" << endl;
	}
	else if (s.compare("pickup") == 0)
		cout << "There is nothing to pickup." << endl;
	else if (s.compare("look") == 0)
		cout << "There is nothing to open." << endl;
	else if (s.compare("shop") == 0)
		shop();
	else
		cout << "sorry, not an option." << endl;
}

void shop() {
	string input;
	do {
		cout << "Welcom to the shop. \n Choose one item" << endl;
		cout << "A for axe." << endl;
		cout << "Sw for Sword." << endl;
		cout << "Sh for Sheild." << endl;
		cin >> input;
		if (input == "A")
			inventory[2] = "Axe";
		else if (input == "Sw")
			inventory[2] = "Sword";
		else if (input == "Sh")
			inventory[2] = "Shield";
	} while (input != "quit");
}
