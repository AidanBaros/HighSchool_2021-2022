#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int room = 1;

int main() {
	string input;
	do {
		switch (room) {
		case 1:
			cout << "You are in room 1" << endl;
			cout << "You can go North, West, or East" << endl << "--";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 2;
			else if(input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 3;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 4;
			break;
		case 2:
			cout << "You are in room 2" << endl;
			cout << "You can go South" << endl << "--";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 1;
			break;
		case 3:
			cout << "You are in room 3" << endl;
			cout << "You can go East" << endl << "--";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 1;
			break;
		case 4:
			cout << "You are in room 4" << endl;
			cout << "You can go West, or South" << endl << "--";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 1;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 5;
			break;
		case 5:
			cout << "You are in room 5" << endl;
			cout << "You can go North" << endl << "--";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 4;
			break;
		}
	} while (input.compare("quit") != 0);
}
