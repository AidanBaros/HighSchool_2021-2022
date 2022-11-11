#include<iostream>
#include<algorithm>
#include<string>
#include<random>
#include<Windows.h>
#include<cmath>
#include<ctime>
using namespace std;

//function declarations
void thingsforall(string s);
void shop();
void monster();
void combat();
void map();
void movement(string s, bool up, bool down, bool left, bool right);
void boss();

//global variables 
int MonHealth;
int MonCls;
int MonAT;

int PlrHealth = 100;
int PlrWep;

int room = 1;

//this is just changed in the code for testing purpesses 
bool dev = 1;

bool wasd = 0;

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

//Inventory struct
item inventory[15] = {
	{1,1,0,"Rusty Sword",1,5,0},
	{0,0,0,"Sword",0,10,0},
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
	{0,0,0,"Health Potions",0,0,0},
	{0,0,0,"Circle Key",0,0,0},
	{0,0,0,"Triangle Key",0,0,0}
};

//Map array
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

//These are just here as guides about the map.
/*
int room2d[8][8] = {
	{1,2,3,4,5,6,7,8},
	{9,10,11,12,13,14,15,16,},
	{17,18,19,20,21,22,23,24},
	{25,26,27,28,29,30,31,32},
	{33,34,35,36,37,38,39,40},
	{41,42,43,44,45,46,47,48},
	{49,50,51,52,53,54,55,56},
	{57,58,59,60,61,62,63,64} };
*/
/*
{
(char)200, (char)205, (char)203, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187, ' ', (char)201, (char)205, (char)205, (char)205, (char)187, ' '},
{ (char)201,(char)205,(char)188,' ',(char)201,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)186,' ' },
{ (char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)205,(char)205,(char)205,(char)205,(char)188,' ' },
{ (char)204,(char)205,(char)205,' ',(char)186,' ',(char)201,(char)205,(char)205,(char)205,(char)205,(char)205,(char)203,(char)205,(char)187,' ' },
{ (char)200,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)203,(char)205,(char)205,' ',(char)186,' ',(char)186,' ' },
{ (char)201,(char)205,(char)188,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)201,(char)205,(char)185,' ',(char)186,' ' },
{ (char)200,(char)205,(char)187,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)200,(char)205,(char)205,' ' },
{ (char)205,(char)205,(char)188,' ',(char)186,' ',(char)200,(char)205,(char)188,' ',(char)200,(char)205,(char)205,(char)205,(char)205,' ' }
}
*/



//Main loop
int main() {
	//Local variables
	srand(time(NULL));
	string input;
	int turns = 0;
	bool goldtf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool combattf[] = { 0,0,0,0,0,0 };
	bool keytf[] = { 0, 0 };
	int DidIWin = 0;
	int check;

	cout << "Do you want to use W A S D or North South East West controls? \n0 for North South East West \n1 for W A S D" << endl;
	cin >> wasd;

	cout << "You wake up to find yourself in a SPOOPY dungeon. Can you escape? Good luck!" << "\n" << "If you want to know what commands you can do type help" << endl;

	//Main loop
	do {
		turns++;
		system("cls");
		switch (room) {
		//all rooms 
		case 1:
			//cout << "You are in room 1." << endl;
			cout << "To your east, you see a long hallway stretching out before you, and to your north, you see the way you came in which you know you can’t exit until you complete your mission to defeat the skeleton king." << endl;
			maps[0][0] = (char)200;
			maps[0][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 0, 1);
			check = 0;
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 16; ++j) {
					if (maps[i][j] != (char)177){
						check++;
					}
				}
			}
			if ((check == 128) && (input == "egg")) {
				room = 65;
			}
			thingsforall(input);
			break;
		case 2:
			//cout << "You are in room 2." << endl;
			cout << "You see a three-way junction with a long hallway going east, a path west that goes to the entrance of the maze, and a path going south." << endl;
			maps[0][2] = (char)203;
			maps[0][3] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 1);
			thingsforall(input);
			break;
		case 3:
			//cout << "You are in room 3." << endl;
			cout << "You sense that you are near the middle of this hallway as the darkness to the west and easy seem the same.  " << endl;
			maps[0][4] = (char)205;
			maps[0][5] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 4:
			//cout << "You are in room 4." << endl;
			cout << "You see faint light from your torch bouncing off a wall to the east and darkness to the west." << endl;
			maps[0][6] = (char)205;
			maps[0][7] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 5:
			//cout << "You are in room 5." << endl;
			cout << "You approach the wall that the light from your torch was bouncing off of and you see paths leading south and west." << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[0][8] = (char)187;
			maps[0][9] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			if (input.compare("pickup") == 0) {
				if (goldtf[0] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[0] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 6:
			//cout << "You are in room 6." << endl;
			cout << "You can go south and east" << endl;
			maps[0][10] = (char)201;
			maps[0][11] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			thingsforall(input);
			break;
		case 7:
			//cout << "You are in room 7." << endl;
			cout << "You can go west and east" << endl;
			maps[0][12] = (char)205;
			maps[0][13] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 8:
			//cout << "You are in room 8." << endl;
			cout << "You can go south and west" << endl;
			maps[0][14] = (char)187;
			maps[0][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			thingsforall(input);
			break;
		case 9:
			//cout << "You are in room 9." << endl;
			cout << "You can go east and south" << endl;
			maps[1][0] = (char)201;
			maps[1][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			thingsforall(input);
			break;
		case 10:
			//cout << "You are in room 10." << endl;
			cout << "You can go north and west" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[1][2] = (char)188;
			maps[1][3] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 1, 0);
			if (input.compare("pickup") == 0) {
				if (goldtf[1] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[1] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 11:
			//cout << "You are in room 11." << endl;
			cout << "You can go south and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[1][4] = (char)201;
			maps[1][5] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[2] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[2] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 12:
			//cout << "You are in room 12." << endl;
			cout << "You can go south and west" << endl;
			maps[1][6] = (char)187;
			maps[1][7] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			thingsforall(input);
			break;
		case 13:
			//cout << "You are in room 13." << endl;
			cout << "To the north and south, your torchlight reflects off walls in the distance." << endl;
			maps[1][8] = (char)186;
			maps[1][9] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 14:
			//cout << "You are in room 14." << endl;
			cout << "You can go north and east" << endl;
			maps[1][10] = (char)200;
			maps[1][11] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			thingsforall(input);
			break;
		case 15:
			//cout << "You are in room 15." << endl;
			cout << "You can go west" << endl;
			cout << "You also see a chest in the corner." << endl;
			maps[1][12] = (char)205;
			maps[1][13] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 0);
			if (input.compare("open") == 0) {
				if (inventory[13].InInventory == 1) {
					int x = rand() % 3 + 1;
					if (x == 1) {
						cout << "You found what looks like a magic sword." << endl;
						inventory[2].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					if (x == 2) {
						cout << "You found what looks like a magic axe." << endl;
						inventory[4].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					if (x == 3) {
						cout << "You found what looks like a magic mace." << endl;
						inventory[6].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					inventory[12].InInventory = 0;
				}
				else {
					cout << "You have not found the circle key." << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 16:
			//cout << "You are in room 16." << endl;
			cout << "You can go north and south" << endl;
			maps[1][14] = (char)186;
			maps[1][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 17:
			//cout << "You are in room 17." << endl;
			cout << "You can go north, south, and east" << endl;
			maps[2][0] = (char)204;
			maps[2][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 1);
			thingsforall(input);
			break;
		case 18:
			//cout << "You are in room 18." << endl;
			cout << "You can go east and west" << endl;
			maps[2][2] = (char)205;
			maps[2][3] = (char)205;
			map();
			cout << endl << endl;
			if (combattf[0] == 0) {
				combat();
				combattf[0] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 19:
			//cout << "You are in room 19." << endl;
			cout << "You can go north, south, and west" << endl;
			maps[2][4] = (char)185;
			maps[2][5] = (char)' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 1, 0);
			if (input.compare("investigate") == 0) {
				int success = rand() % 3 + 1;
				if (success == 1) {
					cout << "You found a set of chainmail armor hidden in the dirt." << endl;
					inventory[9].InInventory = 1;
					inventory[9].Quantity++;
					getchar();
					system("Pause>nul");
				}
				else if (success > 1) {
					cout << "You did not find anything." << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 20:
			//cout << "You are in room 20." << endl;
			cout << "You can go north" << endl;
			cout << "You see a circular looking key" << endl;
			maps[2][6] = (char)186;
			maps[2][7] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 0);
			if (input.compare("pickup") == 0) {
				if (keytf[0] == 0) {
					inventory[13].InInventory = 1;
					keytf[0] = 1;
					cout << "You found a Circle Key" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the key" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 21:
			//cout << "You are in room 21." << endl;
			cout << "You can go north and east" << endl;
			maps[2][8] = (char)200;
			maps[2][9] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			thingsforall(input);
			break;
		case 22:
			//cout << "You are in room 22." << endl;
			cout << "You can go east and west" << endl;
			maps[2][10] = (char)205;
			maps[2][11] = (char)205;
			map();
			cout << endl << endl;
			if (combattf[1] == 0) {
				combat();
				combattf[1] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 23:
			//cout << "You are in room 23." << endl;
			cout << "You can go east and west" << endl;
			maps[2][12] = (char)205;
			maps[2][13] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 24:
			//cout << "You are in room 24." << endl;
			cout << "You can go north and west" << endl;
			maps[2][14] = (char)188;
			maps[2][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 1, 0);
			thingsforall(input);
			break;
		case 25:
			//cout << "You are in room 25." << endl;
			cout << "You can go north, south, and east" << endl;
			maps[3][0] = (char)204;
			maps[3][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 1);
			thingsforall(input);
			break;
		case 26:
			//cout << "You are in room 26." << endl;
			cout << "You can go west" << endl;
			maps[3][2] = (char)205;
			maps[3][3] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 0);
			thingsforall(input);
			break;
		case 27:
			//cout << "You are in room 27." << endl;
			cout << "You can go north and south" << endl;
			maps[3][4] = (char)186;
			maps[3][5] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 28:
			//cout << "You are in room 28." << endl;
			cout << "You can go south and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[3][6] = (char)201;
			maps[3][7] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[3] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[3] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 29:
			//cout << "You are in room 29." << endl;
			cout << "You can go east and west" << endl;
			maps[3][8] = (char)205;
			maps[3][9] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 30:
			//cout << "You are in room 30." << endl;
			cout << "You can go east and west" << endl;
			maps[3][10] = (char)205;
			maps[3][11] = (char)205;
			map();
			cout << endl << endl;
			if (combattf[2] == 0) {
				combat();
				combattf[2] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 31:
			//cout << "You are in room 31." << endl;
			cout << "You can go south, east, and west" << endl;
			maps[3][12] = (char)203;
			maps[3][13] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 1);
			thingsforall(input);
			break;
		case 32:
			//cout << "You are in room 32." << endl;
			cout << "You can go south and west" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[3][14] = (char)187;
			maps[3][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			if (input.compare("pickup") == 0) {
				if (goldtf[4] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[4] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 33:
			//cout << "You are in room 33." << endl;
			cout << "You can go north and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[4][0] = (char)200;
			maps[4][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[5] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[5] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 34:
			//cout << "You are in room 34." << endl;
			cout << "You can go south and west" << endl;
			maps[4][2] = (char)187;
			maps[4][3] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			thingsforall(input);
			break;
		case 35:
			//cout << "You are in room 35." << endl;
			cout << "You can go north and south" << endl;
			maps[4][4] = (char)186;
			maps[4][5] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			thingsforall(input);
			break;
		case 36:
			//cout << "You are in room 36." << endl;
			cout << "You can go north and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[4][6] = (char)200;
			maps[4][7] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[6] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[6] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 37:
			//cout << "You are in room 37." << endl;
			cout << "You can go south, east, and west" << endl;
			maps[4][8] = (char)203;
			maps[4][9] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 1);
			thingsforall(input);
			break;
		case 38:
			//cout << "You are in room 38." << endl;
			cout << "You can go west" << endl;
			cout << "You see a triangular looking key" << endl;
			maps[4][10] = (char)205;
			maps[4][11] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 0);
			if (input.compare("pickup") == 0 && keytf[1] == 0) {
				inventory[14].InInventory = 1;
				keytf[1] = 1;
				cout << "You found a Triangle Key" << endl;
			}
			else
				thingsforall(input);
			break;
		case 39:
			//cout << "You are in room 39." << endl;
			cout << "You can go north and south" << endl;
			maps[4][12] = (char)186;
			maps[4][13] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 40:
			//cout << "You are in room 40." << endl;
			cout << "You can go north and south" << endl;
			maps[4][14] = (char)186;
			maps[4][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 41:
			//cout << "You are in room 41." << endl;
			cout << "You can go south and east" << endl;
			maps[5][0] = (char)201;
			maps[5][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			thingsforall(input);
			break;
		case 42:
			//cout << "You are in room 42." << endl;
			cout << "You can go north and west" << endl;
			maps[5][2] = (char)188;
			maps[5][3] = ' ';
			map();
			cout << endl << endl;
			if (combattf[3] == 0) {
				combat();
				combattf[3] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 1, 0);
			thingsforall(input);
			break;
		case 43:
			//cout << "You are in room 43." << endl;
			cout << "You can go north and south" << endl;
			maps[5][4] = (char)204;
			maps[5][5] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 1);
			thingsforall(input);
			break;
		case 44:
			//cout << "You are in room 44." << endl;
			cout << "You can go east and west" << endl;
			maps[5][6] = (char)205;
			maps[5][7] = (char)205;
			map();
			cout << endl << endl;
			if (combattf[4] == 0) {
				combat();
				combattf[4] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 45:
			//cout << "You are in room 45." << endl;
			cout << "You can go north, south, and west" << endl;
			maps[5][8] = (char)185;
			maps[5][9] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 1, 0);
			if (input.compare("investigate") == 0) {
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
			//cout << "You are in room 46." << endl;
			cout << "You can go south and east" << endl;
			maps[5][10] = (char)201;
			maps[5][11] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 1);
			thingsforall(input);
			break;
		case 47:
			//cout << "You are in room 47." << endl;
			cout << "You can go north, south, and west" << endl;
			maps[5][12] = (char)185;
			maps[5][13] = (char)' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 1, 0);
			thingsforall(input);
			break;
		case 48:
			//cout << "You are in room 48." << endl;
			cout << "You can go north" << endl;
			maps[5][14] = (char)186;
			maps[5][15] = ' ';
			map();
			cout << endl << endl;
			if (combattf[5] == 0) {
				combat();
				combattf[5] = 1;
				break;
			}
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 0);
			thingsforall(input);
			break;
		case 49:
			//cout << "You are in room 49." << endl;
			cout << "You can go north and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[6][0] = (char)200;
			maps[6][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[7] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[7] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 50:
			//cout << "You are in room 50." << endl;
			cout << "You can go south and west" << endl;
			maps[6][2] = (char)187;
			maps[6][3] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 1, 0);
			thingsforall(input);
			break;
		case 51:
			//cout << "You are in room 51." << endl;
			cout << "You can go north and south" << endl;
			maps[6][4] = (char)186;
			maps[6][5] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 52:
			//cout << "You are in room 52." << endl;
			cout << "You can go south" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[6][6] = (char)186;
			maps[6][7] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 1, 0, 0);
			if (input.compare("pickup") == 0) {
				if (goldtf[8] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[8] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 53:
			//cout << "You are in room 53." << endl;
			cout << "You can go north and south" << endl;
			maps[6][8] = (char)186;
			maps[6][9] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 54:
			//cout << "You are in room 54." << endl;
			cout << "You can go north and south" << endl;
			maps[6][10] = (char)186;
			maps[6][11] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 1, 0, 0);
			thingsforall(input);
			break;
		case 55:
			//cout << "You are in room 55." << endl;
			cout << "You can go north and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[6][12] = (char)200;
			maps[6][13] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[9] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[9] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 56:
			//cout << "You are in room 56." << endl;
			cout << "You can go west" << endl;
			maps[6][14] = (char)205;
			maps[6][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 0);
			thingsforall(input);
			break;
		case 57:
			//cout << "You are in room 57." << endl;
			cout << "You can go east" << endl;
			cout << "You also see a chest in the corner." << endl;
			maps[7][0] = (char)205;
			maps[7][1] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 0, 1);
			if (input.compare("open") == 0) {
				if (inventory[14].InInventory == 1) {
					int x = rand() % 3 + 1;
					if (x == 1) {
						cout << "You found what looks like a magic sword." << endl;
						inventory[2].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					if (x == 2) {
						cout << "You found what looks like a magic axe." << endl;
						inventory[4].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					if (x == 3) {
						cout << "You found what looks like a magic mace." << endl;
						inventory[6].InInventory = 1;
						getchar();
						system("Pause>nul");
					}
					inventory[14].InInventory = 0;
				}
				else {
					cout << "You have not found the triangle key." << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 58:
			//cout << "You are in room 58." << endl;
			cout << "You can go north and west" << endl;
			maps[7][2] = (char)188;
			maps[7][3] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 1, 0);
			thingsforall(input);
			break;
		case 59:
			//cout << "You are in room 59." << endl;
			cout << "You can go north" << endl;
			cout << "You also see a large pile of gold on the ground." << endl;
			maps[7][4] = (char)186;
			maps[7][5] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 0);
			if (input.compare("pickup") == 0) {
				if (goldtf[10] == 0) {
					int c = rand() % 31 + 20;
					inventory[11].Quantity += c;
					goldtf[10] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 60:
			//cout << "You are in room 60." << endl;
			cout << "You can go north and east" << endl;
			maps[7][6] = (char)200;
			maps[7][7] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			thingsforall(input);
			break;
		case 61:
			//cout << "You are in room 61." << endl;
			cout << "You can go north and west" << endl;
			maps[7][8] = (char)188;
			maps[7][9] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 1, 0);
			thingsforall(input);
			break;
		case 62:
			//cout << "You are in room 62." << endl;
			cout << "You can go north and east" << endl;
			cout << "You also see a pile of gold on the ground." << endl;
			maps[7][10] = (char)200;
			maps[7][11] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 1, 0, 0, 1);
			if (input.compare("pickup") == 0) {
				if (goldtf[11] == 0) {
					int c = rand() % 16 + 5;
					inventory[11].Quantity += c;
					goldtf[11] = 1;
					cout << "You found " << c << " gold" << endl;
					getchar();
					system("Pause>nul");
				}
				else {
					cout << "You already picked up the gold" << endl;
					getchar();
					system("Pause>nul");
				}
			}
			else
				thingsforall(input);
			break;
		case 63:
			//cout << "You are in room 63." << endl;
			cout << "You can go east and west" << endl;
			maps[7][12] = (char)205;
			maps[7][13] = (char)205;
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 1);
			thingsforall(input);
			break;
		case 64:
			//cout << "You are in room 64." << endl;
			//cout << "" << endl;
			//cout << "It took you " << turns << " turns to complete the game." << endl;
			maps[7][14] = (char)205;
			maps[7][15] = ' ';
			map();
			cout << endl << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			movement(input, 0, 0, 1, 0);
			//thingsforall(input);
			boss();
			DidIWin = 1;
			break;
		case 65:
			//easter egg room
			int z = 0;
			string map1 = { (char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)66,(char)177,(char)89,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)65,(char)177,(char)73,(char)177,(char)68,(char)177,(char)65,(char)177,(char)78,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)66,(char)177,(char)65,(char)177,(char)82,(char)177,(char)79,(char)177,(char)83,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177,(char)177 };
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 16; j++) {
					maps[i][j] = map1[z];
					z++;
				}
			}
			map();
			system("PAUSE>nul");
			break;
		}
	} while (input.compare("quit") != 0 && PlrHealth >= 0 && DidIWin == 0);
	cout << "Thanks for playing." << endl;
}


//function that is accsesd in every room
void thingsforall(string s) {
	// this is being applyed to all rooms it is just the things that would be repeated over and over.
	string wall = "Oops you ran into a wall";
	string input;
	cout << endl;
	if (s.compare("go north") == 0 || s.compare("north") == 0 || s.compare("n") == 0 || s.compare("go south") == 0 || s.compare("south") == 0 || s.compare("s") == 0 || s.compare("go east") == 0 || s.compare("east") == 0 || s.compare("e") == 0 || s.compare("go west") == 0 || s.compare("west") == 0 || s.compare("w") == 0 || s.compare("a") == 0 || s.compare("d") == 0)
		return;
	else if (s.compare("go north") == 0 || s.compare("north") == 0 || s.compare("n") == 0) {
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
		//cout << "map" << endl;
		cout << "shop" << endl;
		cout << "investigate" << endl;
		//cout << "health" << endl;
		cout << "active weapon" << endl;
		cout << "active armor" << endl;
		cout << "quit" << endl;
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
	/*else if (s.compare("map") == 0) {
		map();
	}*/
	else if (s.compare("shop") == 0) {
		shop();
	}
	else if (s.compare("investigate") == 0) {
		cout << "You did not find anything." << endl;
	}
	/*else if (s.compare("health") == 0) {
		cout << "You are at " << PlrHealth << " HP" << endl;
	}*/
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
	else if (s.compare("~") == 0 && dev == 1) {
		int rooms = 0;
		cin >> rooms;
		room = rooms;
	}
	else if (s.compare("@") == 0 && dev == 1) {
		int z = 0;
		string map = { {(char)200, (char)205, (char)203, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187, ' ', (char)201, (char)205, (char)205, (char)205, (char)187, ' ',(char)201,(char)205,(char)188,' ',(char)201,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)186,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)205,(char)205,(char)205,(char)205,(char)188,' ',(char)204,(char)205,(char)205,' ',(char)186,' ',(char)201,(char)205,(char)205,(char)205,(char)205,(char)205,(char)203,(char)205,(char)187,' ',(char)200,(char)205,(char)187,' ',(char)186,' ',(char)200,(char)205,(char)203,(char)205,(char)205,' ',(char)186,' ',(char)186,' ',(char)201,(char)205,(char)188,' ',(char)204,(char)205,(char)205,(char)205,(char)185,' ',(char)201,(char)205,(char)185,' ',(char)186,' ',(char)200,(char)205,(char)187,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)186,' ',(char)200,(char)205,(char)205,' ',(char)205,(char)205,(char)188,' ',(char)186,' ',(char)200,(char)205,(char)188,' ',(char)200,(char)205,(char)205,(char)205,(char)205,' '} };
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 16; j++) {
				maps[i][j] = map[z];
				z++;
			}
		}
	}
	else if (s.compare("quit") == 0) {
		cout << endl;
	}
	else {
		cout << "Sorry, not an option. (Press enter)" << endl;
	}
	system("PAUSE>nul");

}


//the shop function
void shop() {
	// shop i may add more items in the future
	string input;
	cout << "Your Gold -- " << inventory[11].Quantity << endl;
	cout << "Welcome to the shop." << endl;
	cout << "Axe - 75 gold" << endl;
	cout << "Sword - 75 gold" << endl;
	cout << "Mace - 75 gold" << endl;
	cout << "Shield - 125 gold" << endl;
	cout << "Health Potion  - 100 gold" << endl;
	getline(cin, input);
	if (input == "Axe" && inventory[11].Quantity >= 75) {
		inventory[3].InInventory = 1;
		inventory[3].Quantity++;
		inventory[11].Quantity -= 75;
	}
	else if (input == "Sword") {
		if (inventory[11].Quantity >= 75) {
			inventory[1].InInventory = 1;
			inventory[1].Quantity++;
			inventory[11].Quantity -= 75;
		}
		else {
			cout << "You don't have enough gold." << endl;
		}
	}
	else if (input == "Mace") {
		if (inventory[11].Quantity >= 75) {
			inventory[5].InInventory = 1;
			inventory[5].Quantity++;
			inventory[11].Quantity -= 75;
		}
		else {
			cout << "You don't have enough gold." << endl;
		}
	}
	else if (input == "Shield") {
		if (inventory[11].Quantity >= 125) {
			inventory[10].InInventory = 1;
			inventory[10].Quantity++;
			inventory[11].Quantity -= 125;
		}
		else {
			cout << "You don't have enough gold." << endl;
		}
	}
	else if (input == "Health Potion") {
		if (inventory[11].Quantity >= 100) {
			inventory[12].InInventory = 1;
			inventory[12].Quantity++;
			inventory[11].Quantity -= 100;
		}
		else {
			cout << "You don't have enough gold." << endl;
		}
	}
	else {
		cout << "Not an option." << endl;
	}
}


//generates a monster to fight throught the combat function
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


//the combat function that is activated when you go into a room with a monster
void combat() {
	int MONAT;

	item PlayerWeapon;
	item PlayerArmor;

	string input;
	int whichattack;
	bool MonsterBlock = 0;
	bool ShieldActive = 0;

	system("cls");

	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveWeapon == 1)
			PlayerWeapon = inventory[i];
	}
	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveArmor == 1)
			PlayerArmor = inventory[i];
	}

	int PlayerHealth = PlrHealth + PlayerArmor.ArmourBonus;

	monster();

	cout << "You have entered combat!" << endl;

	system("Pause>nul");

	while (PlayerHealth >= 0 && MonHealth >= 0) {
		system("cls");
		cout << "HP - " << PlayerHealth << endl;
		cout << "Monster HP - " << MonHealth << endl;
		if (inventory[10].InInventory == 1 && inventory[12].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
			cout << "Block" << endl;
			cout << "Health Potion" << endl;
			whichattack = 4;
		}
		else if (inventory[12].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
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

		int Attack = rand() % 5 + PlayerWeapon.BaseAttack;
		int crit = rand() % 5;

		if (MonsterBlock == 1) {
			cout << "You tried to " << input << " but the monster blocked." << endl;
			MonsterBlock = 0;
		}
		else if (input.compare("slash") == 0) {
			if (MonCls == 1) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % MonAT + 1;
			int MAttack = rand() % 5 + 1;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 4) {
				cout << "The monster blocks" << endl;
				MonsterBlock = 1;
			}
		}
		else if (input.compare("jab") == 0) {
			if (MonCls == 2) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % MonAT + 1;
			int MAttack = rand() % 5 + 1;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 4) {
				cout << "The monster blocks" << endl;
				MonsterBlock = 1;
			}
		}
		else if (input.compare("strike") == 0) {
			if (MonCls == 3) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % MonAT + 1;
			int MAttack = rand() % 5 + 1;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 4) {
				cout << "The monster blocks" << endl;
				MonsterBlock = 1;
			}
		}
		else if (input.compare("block") == 0 && (whichattack == 2 || whichattack == 4)) {
			ShieldActive = 1;
			cout << "You block." << endl;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
		}
		else if (input.compare("health potion") == 0 && (whichattack == 3 || whichattack == 4)) {
			PlayerHealth += rand() % 15 + 5;
		}
		else
			cout << "Sorry, not an option. (Press enter)" << endl;
		system("Pause>nul");
	}
	PlrHealth = PlayerHealth;
	int c = rand() % 16 + 5;
	inventory[11].Quantity += c;
	cout << "You found " << c << " gold of the Skeletion." << endl;
	getchar();
	system("Pause>nul");
}


//the function that operates the map 
void map() {
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 16; j++) {
			cout << maps[i][j];
		}
		cout << endl;
	}*/

	int mapXCoord;
	if ((room - 1) < 8) {
		mapXCoord = ((room * 2) - 2);
	}
	else {
		int moduloRoom = room % 8;
		if (moduloRoom == 0) {
			mapXCoord = ((8 * 2) - 2);
		}
		else {
			mapXCoord = ((moduloRoom * 2) - 2);
		}
	}
	int mapYCoord = floor((room - 1) / 8);
	if(room != 65)
		cout << "HP - " << PlrHealth << endl;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 16; ++j) {
			if ((i == mapYCoord && j == mapXCoord) || (i == mapYCoord && j == mapXCoord + 1)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			cout << maps[i][j];
		}
		cout << endl;
	}
}


//this is the movment function that detemins which dirsction the player moves
void movement(string s, bool up, bool down, bool left, bool right) {
	if (up == true) { // if up is an exit
		if (wasd == true) {
			if (s.compare("w") == 0) {
				room -= 8;
			}
		}
		else {
			if (s.compare("go north") == 0 || s.compare("north") == 0 || s.compare("n") == 0) {
				room -= 8;
			}
		}
	}
	if (down == true) { // if down is an exit
		if (wasd == true) {
			if (s.compare("s") == 0) {
				room += 8;
			}
		}
		else {
			if (s.compare("go south") == 0 || s.compare("south") == 0 || s.compare("s") == 0) {
				room += 8;
			}
		}
	}
	if (right == true) { // if right is an exit
		if (wasd == true) {
			if (s.compare("d") == 0) {
				room += 1;
			}
		}
		else {
			if (s.compare("go east") == 0 || s.compare("east") == 0 || s.compare("e") == 0) {
				room += 1;
			}
		}
	}
	if (left == true) { // if left is an exit
		if (wasd == true) {
			if (s.compare("a") == 0) {
				room -= 1;
			}
		}
		else {
			if (s.compare("go west") == 0 || s.compare("west") == 0 || s.compare("w") == 0) {
				room -= 1;
			}
		}
	}
}


//the function that runs when in room 64
void boss() {
	int MONAT;

	item PlayerWeapon;
	item PlayerArmor;

	string input;
	int whichattack;
	bool MonsterBlock = 0;
	bool ShieldActive = 0;

	MonHealth = 150;

	system("cls");

	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveWeapon == 1)
			PlayerWeapon = inventory[i];
	}
	for (int i = 0; i < 13; i++) {
		if (inventory[i].ActiveArmor == 1)
			PlayerArmor = inventory[i];
	}

	int PlayerHealth = PlrHealth + PlayerArmor.ArmourBonus;

	cout << "Before you, you see the Skeleton King." << endl;
	cout << "You have entered combat!" << endl;

	system("Pause>nul");

	bool fightOver = false;

	while (fightOver == false) {
		if (PlayerHealth <= 0 || MonHealth <= 0) {
			fightOver = true;
		}
		system("cls");
		cout << "HP - " << PlayerHealth << endl;
		cout << "Boss HP - " << MonHealth << endl;
		if (inventory[10].InInventory == 1 && inventory[12].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
			cout << "Block" << endl;
			cout << "Health Potion" << endl;
			whichattack = 4;
		}
		else if (inventory[12].InInventory == 1) {
			cout << "What would you like to do?" << endl;
			cout << "Slash" << endl;
			cout << "Jab" << endl;
			cout << "Strike" << endl;
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

		int Attack = rand() % 5 + PlayerWeapon.BaseAttack;
		int crithit = rand() % 10 + 1;
		int crit = rand() % 5;

		if (MonsterBlock == 1) {
			cout << "You tried to " << input << " but the monster blocked." << endl;
			MonsterBlock = 0;
		}
		else if (input.compare("slash") == 0) {
			if (crithit == 1) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % 3 + 1;
			int MAttack = rand() % 5 + 4;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
		}
		else if (input.compare("jab") == 0) {
			if (crithit == 1) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % 3 + 1;
			int MAttack = rand() % 5 + 1;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
		}
		else if (input.compare("strike") == 0) {
			if (crithit == 1) {
				MonHealth -= (Attack + crit);
				cout << "You did " << Attack + crit << " damage." << endl << endl;
				if (dev == 1)
					cout << Attack << ", " << crit << endl;
			}
			else {
				MonHealth -= Attack;
				cout << "You did " << Attack << " damage." << endl << endl;
			}
			MONAT = rand() % 3 + 1;
			int MAttack = rand() % 5 + 1;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
			else if (MONAT == 1) {
				cout << "The monster slashs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 2) {
				cout << "The monster jabs at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
			else if (MONAT == 3) {
				cout << "The monster strikes at you dealing " << MAttack << " damage." << endl;
				PlayerHealth -= MAttack;
			}
		}
		else if (input.compare("block") == 0 && (whichattack == 2 || whichattack == 4)) {
			ShieldActive = 1;
			cout << "You block." << endl;
			if (ShieldActive == 1) {
				cout << "The monster attacked you but did 0 damage because you blocked." << endl;
				ShieldActive = 0;
			}
		}
		else if (input.compare("health potion") == 0 && (whichattack == 3 || whichattack == 4)) {
			int HPup = rand() % 15 + 5;
			PlayerHealth += HPup;
			cout << "You gained " << HPup << " Hit Points" << endl;
		}
		else {
			cout << "Sorry, not an option. (Press enter)" << endl;
		}
		system("Pause>nul");
	}
	PlrHealth = PlayerHealth;
	int c = rand() % 16 + 5;
	inventory[11].Quantity += c;
	cout << "Congratulations you have defeated the Skeleton King" << endl;
	getchar();
	system("Pause>nul");
}
//LOL 2000 lines
