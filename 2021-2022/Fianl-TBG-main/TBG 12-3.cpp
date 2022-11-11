#include <iostream>
#include<algorithm>
#include<string>
#include<random>
using namespace std;

//function declarations (needed for each one you write)
void thingsforall(string s);
void shop();
void monster();
void combat();
void map();

//global variables (in general, not a good idea, but for this small of a game, ok)

int MonHealth;
int MonCls;
int MonAT;

int PlrHealth = 100;
int PlrWep;
bool shield = 0;
bool armour = 0;

//struct 
struct item {
	bool InInventory;
	bool ActiveWeapon;
	bool ActiveArmor;
	string ItemName;
	int Quantity;
	int BaseAttack;
	int ArmourBonus;
};

item inventory[13] = { 
	{1,1,0,"Rusty Sword",1,5,0},
	{01,0,0,"Sword",0,10,0},
	{0,0,0,"Magic Sword",0,15,0},
	{0,0,0,"Axe",0,10,0},
	{0,0,0,"Magic Axe",0,15,0},
	{0,0,0,"Mace",0,10,0},
	{0,0,0,"Magic Mace",0,15,0},
	{0,0,0,"Stick",0,1000,0},
	{1,0,1,"Leather Armor",1,0,10},
	{0,0,0,"ChainMail Armor",0,0,50},
	{0,0,0,"Shield",0,0,0},
	{0,0,0,"Gold",0,0,0},
	{0,0,0,"Health Potions",0,0,0}
};

char maps[8][16] = {
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177},
	{(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177}
};

//
//{(char)200, (char)205, (char)203, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187, ' ', (char)201, (char)205, (char)205, (char)205, (char)187, ' '},
//{ (char)201,(char)205,(char)188,' ',(char)201,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)186,' ' },
//{ (char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)205,(char)205,(char)205,(char)205,(char)188,' ' },
//{ (char)204,(char)205,(char)205,' ',(char)186,' ',(char)201,(char)205,(char)205,(char)205,(char)205,(char)205,(char)203,(char)205,(char)187,' ' },
//{ (char)200,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)203,(char)205,(char)205,' ',(char)186,' ',(char)186,' ' },
//{ (char)201,(char)205,(char)188,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)201,(char)205,(char)185,' ',(char)186,' ' },
//{ (char)200,(char)205,(char)187,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)200,(char)205,(char)205,' ' },
//{ (char)205,(char)205,(char)188,' ',(char)186,' ',(char)200,(char)205,(char)188,' ',(char)200,(char)205,(char)205,(char)205,(char)205,' ' }}

int main() {
	int room = 1;
	string input;
	int turns = 0;
	bool goldtf[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	cout << "You wake up to find yourself in a SPOOPY dungeon. Can you escape? Good luck!" << "\n" << "If you want to know what commands you can do type help" << endl;

	do {
		turns++;
		switch (room) {
			//all rooms 
		case 1:
			cout << "You are in room 1." << endl;
			maps[0][0] = (char)200;
			maps[0][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 2;
			else if (input.compare("~") == 0)
				room = 64;
			else if (input.compare("@") == 0) {
				int z = 0;
				string map = {{(char)200, (char)205, (char)203, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187, ' ', (char)201, (char)205, (char)205, (char)205, (char)187, ' ',(char)201,(char)205,(char)188,' ',(char)201,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)186,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)205,(char)205,(char)205,(char)205,(char)188,' ',(char)204,(char)205,(char)205,' ',(char)186,' ',(char)201,(char)205,(char)205,(char)205,(char)205,(char)205,(char)203,(char)205,(char)187,' ',(char)200,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)203,(char)205,(char)205,' ',(char)186,' ',(char)186,' ',(char)201,(char)205,(char)188,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)201,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)187,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)205,(char)205,(char)188,' ',(char)186,' ',(char)200,(char)205,(char)188,' ',(char)200,(char)205,(char)205,(char)205,(char)205,' '}};
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 16; j++) {
						maps[i][j] = map[z];
						z++;
					}
				}
			
			}
			else
				thingsforall(input);
			break;
		case 2:
			cout << "You are in room 2." << endl;
			maps[0][2] = (char)203;
			maps[0][3] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 10;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 3;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 1;
			else
				thingsforall(input);
			break;
		case 3:
			cout << "You are in room 3." << endl;
			maps[0][4] = (char)205;
			maps[0][5] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 4;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 2;
			else
				thingsforall(input);
			break;
		case 4:
			cout << "You are in room 4." << endl;
			maps[0][6] = (char)205;
			maps[0][7] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 5;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 3;
			else
				thingsforall(input);
			break;
		case 5:
			
			cout << "You are in room 5." << endl;
			maps[0][8] = (char)187;
			maps[0][9] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 13;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 4;
			else if (input.compare("pickup") == 0 && goldtf[0] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[0] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 6:
			cout << "You are in room 6." << endl;
			maps[0][10] = (char)201;
			maps[0][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 14;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 7;
			else
				thingsforall(input);
			break;
		case 7:
			cout << "You are in room 7." << endl;
			maps[0][12] = (char)205;
			maps[0][13] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 8;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 6;
			else
				thingsforall(input);
			break;
		case 8:
			cout << "You are in room 8." << endl;
			maps[0][14] = (char)187;
			maps[0][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 16;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 7;
			else
				thingsforall(input);
			break;
		case 9:
			cout << "You are in room 9." << endl;
			maps[1][0] = (char)201;
			maps[1][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 17;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 10;
			else
				thingsforall(input);
			break;
		case 10:
			cout << "You are in room 10." << endl;
			maps[1][2] = (char)188;
			maps[1][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 2;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 9;
			else if (input.compare("pickup") == 0 && goldtf[1] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[1] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 11:
			cout << "You are in room 11." << endl;
			maps[1][4] = (char)201;
			maps[1][5] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 19;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 12;
			else if (input.compare("pickup") == 0 && goldtf[2] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[2] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 12:
			cout << "You are in room 12." << endl;
			maps[1][6] = (char)187;
			maps[1][7] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 20;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 11;
			else
				thingsforall(input);
			break;
		case 13:
			cout << "You are in room 13." << endl;
			maps[1][8] = (char)186;
			maps[1][9] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 5;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 21;
			else
				thingsforall(input);
			break;
		case 14:
			cout << "You are in room 14." << endl;
			maps[1][10] = (char)200;
			maps[1][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 6;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 15;
			else
				thingsforall(input);
			break;
		case 15:
			cout << "You are in room 15." << endl;
			maps[1][12] = (char)205;
			maps[1][13] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 14;
			else
				thingsforall(input);
			break;
		case 16:
			cout << "You are in room 16." << endl;
			maps[1][14] = (char)186;
			maps[1][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 8;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 24;
			else
				thingsforall(input);
			break;
		case 17:
			cout << "You are in room 17." << endl;
			maps[2][0] = (char)204;
			maps[2][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 9;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 25;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 18;
			else
				thingsforall(input);
			break;
		case 18:
			cout << "You are in room 18." << endl;
			maps[2][2] = (char)205;
			maps[2][3] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 19;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 17;
			else
				thingsforall(input);
			break;
		case 19:
			cout << "You are in room 19." << endl;
			maps[2][4] = (char)185;
			maps[2][5] = (char)' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 11;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 27;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 18;
			else
				thingsforall(input);
			break;
		case 20:
			cout << "You are in room 20." << endl;
			maps[2][6] = (char)186;
			maps[2][7] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 12;
			else
				thingsforall(input);
			break;
		case 21:
			cout << "You are in room 21." << endl;
			maps[2][8] = (char)200;
			maps[2][9] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 13;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 22;
			else
				thingsforall(input);
			break;
		case 22:
			cout << "You are in room 22." << endl;
			maps[2][10] = (char)205;
			maps[2][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 23;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 21;
			else
				thingsforall(input);
			break;
		case 23:
			cout << "You are in room 23." << endl;
			maps[2][12] = (char)205;
			maps[2][13] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 24;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 22;
			else
				thingsforall(input);
			break;
		case 24:
			cout << "You are in room 24." << endl;
			maps[2][14] = (char)188;
			maps[2][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 16;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 23;
			else
				thingsforall(input);
			break;
		case 25:
			cout << "You are in room 25." << endl;
			maps[3][0] = (char)204;
			maps[3][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 17;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 33;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 26;
			else
				thingsforall(input);
			break;
		case 26:
			cout << "You are in room 26." << endl;
			maps[3][2] = (char)205;
			maps[3][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 25;
			else
				thingsforall(input);
			break;
		case 27:
			cout << "You are in room 27." << endl;
			maps[3][4] = (char)186;
			maps[3][5] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 19;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 35;
			else
				thingsforall(input);
			break;
		case 28:
			cout << "You are in room 28." << endl;
			maps[3][6] = (char)201;
			maps[3][7] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 36;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 29;
			else if (input.compare("pickup") == 0 && goldtf[3] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[3] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 29:
			cout << "You are in room 29." << endl;
			maps[3][8] = (char)205;
			maps[3][9] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 30;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 28;
			else
				thingsforall(input);
			break;
		case 30:
			cout << "You are in room 30." << endl;
			maps[3][10] = (char)205;
			maps[3][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 31;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 29;
			else
				thingsforall(input);
			break;
		case 31:
			cout << "You are in room 31." << endl;
			maps[3][12] = (char)203;
			maps[3][13] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 39;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 32;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 30;
			else
				thingsforall(input);
			break;
		case 32:
			cout << "You are in room 32." << endl;
			maps[3][14] = (char)187;
			maps[3][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 40;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 31;
			else if (input.compare("pickup") == 0 && goldtf[4] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[4] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 33:
			cout << "You are in room 33." << endl;
			maps[4][0] = (char)200;
			maps[4][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 25;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 34;
			else if (input.compare("pickup") == 0 && goldtf[5] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[5] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 34:
			cout << "You are in room 34." << endl;
			maps[4][2] = (char)187;
			maps[4][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 42;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 33;
			else
				thingsforall(input);
			break;
		case 35:
			cout << "You are in room 35." << endl;
			maps[4][4] = (char)186;
			maps[4][5] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 27;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 43;
			else if (input.compare("pickup") == 0 && goldtf[6] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[6] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 36:
			cout << "You are in room 36." << endl;
			maps[4][6] = (char)200;
			maps[4][7] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 28;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 37;
			else
				thingsforall(input);
			break;
		case 37:
			cout << "You are in room 37." << endl;
			maps[4][8] = (char)203;
			maps[4][9] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 45;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 38;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 36;
			else
				thingsforall(input);
			break;
		case 38:
			cout << "You are in room 38." << endl;
			maps[4][10] = (char)205;
			maps[4][11] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 37;
			else
				thingsforall(input);
			break;
		case 39:
			cout << "You are in room 39." << endl;
			maps[4][12] = (char)186;
			maps[4][13] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 31;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 47;
			else
				thingsforall(input);
			break;
		case 40:
			cout << "You are in room 40." << endl;
			maps[4][14] = (char)186;
			maps[4][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 32;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 48;
			else
				thingsforall(input);
			break;
		case 41:
			cout << "You are in room 41." << endl;
			maps[5][0] = (char)201;
			maps[5][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 49;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 42;
			else
				thingsforall(input);
			break;
		case 42:
			cout << "You are in room 42." << endl;
			maps[5][2] = (char)188;
			maps[5][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 34;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 41;
			else
				thingsforall(input);
			break;
		case 43:
			cout << "You are in room 43." << endl;
			maps[5][4] = (char)204;
			maps[5][5] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 35;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 51;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 44;
			else
				thingsforall(input);
			break;
		case 44:
			cout << "You are in room 44." << endl;
			maps[5][6] = (char)205;
			maps[5][7] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 45;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 43;
			else
				thingsforall(input);
			break;
		case 45:
			cout << "You are in room 45." << endl;
			maps[5][8] = (char)185;
			maps[5][9] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 37;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 53;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 44;
			else if (input.compare("investigate") == 0) {
				int success = rand() % 3 + 1;
				if (success == 1) {
					cout << "You found a faintly glowing stick. You think that it may be magical." << endl;
					inventory[7].InInventory = 1;
					inventory[7].Quantity++;
				}
				else if (success > 1)
					cout << "You did not find anything." << endl;
			}
			else
				thingsforall(input);
			break;
		case 46:
			cout << "You are in room 46." << endl;
			maps[5][10] = (char)201;
			maps[5][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 54;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 47;
			else
				thingsforall(input);
			break;
		case 47:
			cout << "You are in room 47." << endl;
			maps[5][12] = (char)185;
			maps[5][13] = (char)' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 39;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 55;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 46;
			else
				thingsforall(input);
			break;
		case 48:
			cout << "You are in room 48." << endl;
			maps[5][14] = (char)186;
			maps[5][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 40;
			else
				thingsforall(input);
			break;
		case 49:
			cout << "You are in room 49." << endl;
			maps[6][0] = (char)200;
			maps[6][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 41;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 50;
			else if (input.compare("pickup") == 0 && goldtf[7] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[7] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 50:
			cout << "You are in room 50." << endl;
			maps[6][2] = (char)187;
			maps[6][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 58;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 49;
			else
				thingsforall(input);
			break;
		case 51:
			cout << "You are in room 51." << endl;
			maps[6][4] = (char)186;
			maps[6][5] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 43;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 59;
			else
				thingsforall(input);
			break;
		case 52:
			cout << "You are in room 52." << endl;
			maps[6][6] = (char)186;
			maps[6][7] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 60;
			else if (input.compare("pickup") == 0 && goldtf[8] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[8] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 53:
			cout << "You are in room 53." << endl;
			maps[6][8] = (char)186;
			maps[6][9] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 45;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 61;
			else
				thingsforall(input);
			break;
		case 54:
			cout << "You are in room 54." << endl;
			maps[6][10] = (char)186;
			maps[6][11] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 46;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 62;
			else
				thingsforall(input);
			break;
		case 55:
			cout << "You are in room 55." << endl;
			maps[6][12] = (char)200;
			maps[6][13] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 47;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 56;
			else if (input.compare("pickup") == 0 && goldtf[9] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[9] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 56:
			cout << "You are in room 56." << endl;
			maps[6][14] = (char)205;
			maps[6][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 55;
			else
				thingsforall(input);
			break;
		case 57:
			cout << "You are in room 57." << endl;
			maps[7][0] = (char)205;
			maps[7][1] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 58;
			else
				thingsforall(input);
			break;
		case 58:
			cout << "You are in room 58." << endl;
			maps[7][2] = (char)188;
			maps[7][3] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 50;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 57;
			else
				thingsforall(input);
			break;
		case 59:
			cout << "You are in room 59." << endl;
			maps[7][4] = (char)186;
			maps[7][5] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 51;
			else if (input.compare("pickup") == 0 && goldtf[0] == 0) {
				int c = rand() % 31 + 20;
				inventory[11].Quantity += c;
				goldtf[0] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 60:
			cout << "You are in room 60." << endl;
			maps[7][6] = (char)200;
			maps[7][7] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 52;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 61;
			else
				thingsforall(input);
			break;
		case 61:
			cout << "You are in room 61." << endl;
			maps[7][8] = (char)188;
			maps[7][9] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 53;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 60;
			else
				thingsforall(input);
			break;
		case 62:
			cout << "You are in room 62." << endl;
			maps[7][10] = (char)200;
			maps[7][11] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 54;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 63;
			else if (input.compare("pickup") == 0 && goldtf[11] == 0) {
				int c = rand() % 16 + 5;
				inventory[11].Quantity += c;
				goldtf[11] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 63:
			cout << "You are in room 63." << endl;
			maps[7][12] = (char)205;
			maps[7][13] = (char)205;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 64;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 62;
			else
				thingsforall(input);
			break;
		case 64:
			cout << "You are in room 64." << endl;
			maps[7][14] = (char)205;
			maps[7][15] = ' ';
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 63;
			else
				thingsforall(input);

			cout << "It took you " << turns << " turns to complete the game." << endl;
			break;
		}
	} while (input.compare("quit") != 0);
}

void thingsforall(string s) {
	// this is being applyed to all rooms it is just the things that would be repeated over and over.
	string wall = "Oops you ran into a wall";
	string input;
	cout << endl;
	if (s.compare("go north") == 0 || s.compare("north") == 0 || s.compare("n") == 0) {
		cout << wall << endl;
	}
	else if (s.compare("go south") == 0 || s.compare("south") == 0 || s.compare("s") == 0) {
		cout << wall << endl;
	}
	else if (s.compare("go east") == 0 || s.compare("east") == 0 || s.compare("e") == 0) {
		cout << wall << endl;
	}
	else if (s.compare("go west") == 0 || s.compare("west") == 0 || s.compare("w") == 0) {
		cout << wall << endl;
	}
	else if (s.compare("help") == 0) {
		cout << "The commands you can do are:" << endl;
		cout << "go north, go south, go east, go west, north, south, east, west, n, s, e, w" << endl;
		cout << "help" << endl;
		cout << "inventory" << endl;
		cout << "gold" << endl;
		cout << "look" << endl;
		cout << "pickup" << endl;
		cout << "open" << endl;
		cout << "map" << endl;
		cout << "shop" << endl;
		cout << "investigate" << endl;
		cout << "health" << endl;
		cout << "active weapon" << endl;
		cout << "active armor" << endl;
	}
	else if (s.compare("inventory") == 0) {
		for (int i = 0; i < 13; i++) {
			if (inventory[i].InInventory == 1)
				cout << inventory[i].ItemName << endl;
		}
	}
	else if (s.compare("gold") == 0) {
		cout << "You have " << inventory[11].Quantity << " gold" << endl;
	}
	else if (s.compare("look") == 0) {
		cout << "You don't see anything special." << endl;
	}
	else if (s.compare("pickup") == 0) {
		cout << "There is nothing to pickup." << endl;
	}
	else if (s.compare("open") == 0) {
		cout << "There is nothing to open." << endl;
	}
	else if (s.compare("map") == 0) {
		map();
	}
	else if (s.compare("shop") == 0) {
		shop();
	}
	else if (s.compare("investigate") == 0) {
		cout << "You did not find anything." << endl;
	}
	else if (s.compare("health") == 0) {
		cout << "You are at " << PlrHealth << " HP" << endl;
	}
	else if (s.compare("active weapon") == 0) {
		cout << "Your weapon that is curently active is your ";
		for (int i = 0; i < 13; i++) {
			if (inventory[i].ActiveWeapon == 1)
				cout << inventory[i].ItemName << endl;
		}
		cout << endl << endl << endl << endl;
		cout << "Which weapon do you want to make active?        (You need to type the exact name.)" << endl << endl;
		for (int i = 0; i < 13; i++) {
			if (inventory[i].BaseAttack > 1 && inventory[i].InInventory == 1)
				cout << inventory[i].ItemName << endl;
		}

		for (int i = 0; i < 13; i++) {
			inventory[i].ActiveWeapon = 0;
		}

		getline(cin, input);
		for (int i = 0; i < 13; i++) {
			if (input.compare(inventory[i].ItemName) == 0) {
				cout << inventory[i].ItemName << " is now your active item." << endl;
				inventory[i].ActiveWeapon = 1;
			}
		}
		cout << endl;
	}
	else if (s.compare("active armor") == 0) {
		cout << "Your armor that is curently active is your ";
		for (int i = 0; i < 13; i++) {
			if (inventory[i].ActiveArmor == 1)
				cout << inventory[i].ItemName << endl;
		}
		cout << endl << endl << endl << endl;
		cout << "Which weapon do you want to make active?        (You need to type the exact name.)" << endl << endl;
		for (int i = 0; i < 13; i++) {
			if (inventory[i].ArmourBonus > 1 && inventory[i].InInventory == 1)
				cout << inventory[i].ItemName << endl;
		}

		for (int i = 0; i < 13; i++) {
			inventory[i].ActiveArmor = 0;
		}

		getline(cin, input);
		for (int i = 0; i < 13; i++) {
			if (input.compare(inventory[i].ItemName) == 0) {
				cout << inventory[i].ItemName << " is now your active item." << endl;
				inventory[i].ActiveArmor = 1;
			}
		}
		cout << endl;
	}
	else {
		cout << "sorry, not an option." << endl;
	}
}

void shop() {
	// shop i may add more items in the future
	string input;
	do {
		cout << "Welcom to the shop. \n Choose one item" << endl;
		cout << "A for Axe - 75 gold" << endl;
		cout << "Sw for Sword - 75 gold" << endl;
		cout << "Ma for Mace - 75 gold" << endl;
		cout << "Sh for Shield - 125 gold" << endl;
		cout << "HP for Health Potion  - 100 gold" << endl;
		cin >> input;
		if (input == "A" && inventory[11].Quantity >= 75) {
			inventory[3].InInventory = 1;
			inventory[3].Quantity++;
			inventory[11].Quantity -= 75;
		}
		else if (input == "Sw" && inventory[11].Quantity >=75){
			inventory[1].InInventory = 1;
			inventory[1].Quantity++;
			inventory[11].Quantity -= 75;
		}
		else if (input == "Ma" && inventory[11].Quantity >= 75) {
			inventory[5].InInventory = 1;
			inventory[5].Quantity++;
			inventory[11].Quantity -= 75;
		}
		else if (input == "Sh" && inventory[11].Quantity >= 125) {
			inventory[10].InInventory = 1;
			inventory[10].Quantity++;
			inventory[11].Quantity -= 125;
		}
		else if (input == "HP" && inventory[11].Quantity >= 100) {
			inventory[12].InInventory = 1;
			inventory[12].Quantity++;
			inventory[11].Quantity -= 100;
		}
	} while (input != "quit");
}

void monster() {
	MonCls = rand() % 3 + 1;
	if (MonCls == 1) {
		cout << "You see a Skeleton with a sword." << endl << endl;
		MonHealth = 25;
		MonAT = 3;
	}
	if (MonCls == 2) {
		cout << "You see a Skeleton with a sword and sheild." << endl << endl;
		MonHealth = 25;
		MonAT = 4;
	}
	if (MonCls == 3) {
		cout << "You see an armored Skeleton with a sword." << endl << endl;
		MonHealth = 50;
		MonAT = 3;
	}
}

void combat() {
	int MONAT;

	item PlayerWeapon;
	item PlayerArmor;

	string input;
	int whichattack;
	bool ShieldActive = 0;

	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveWeapon == 1)
			PlayerWeapon = inventory[i];
	}
	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveArmor == 1)
			PlayerArmor = inventory[i];
	}

	monster();
	cout << "You have entered combat!" << endl;
	while (PlrHealth >= 0 && MonHealth >= 0) {
		if (inventory[10].InInventory == 1 && inventory[12].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
			cout << "Block" << endl;
			cout << "Health Potion" << endl;
			whichattack = 3;
		}
		else if (inventory[10].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
			cout << "Block" << endl;
			whichattack = 2;
		}
		else {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
			whichattack = 1;
		}

		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input.compare("Slash")) {
			MonHealth = MonHealth -= PlayerWeapon.BaseAttack;
		}
		else if (input.compare("Jab")) {
			MonHealth = MonHealth -= PlayerWeapon.BaseAttack;
		}
		else if (input.compare("Strike")) {
			MonHealth = MonHealth -= PlayerWeapon.BaseAttack;
		}
		else if (input.compare("Block") && whichattack > 1) {
			ShieldActive = 1;
		}
		else if (input.compare("Health Potion") && whichattack > 1) {
			PlrHealth = rand() % 15 + 5;
		}

		MONAT = rand() % MonAT + 1;
		if (MONAT == 1) {
			cout << "slash";
		}
		else if (MONAT == 2) {
			cout << "jab";
		}
		else if (MONAT == 3) {
			cout << "over head";
		}
		else if (MONAT == 4) {
			cout << "block";
		}
	}
}

void map() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 16; j++) {
			cout << maps[i][j];
		}
		cout << endl;
	}
}
