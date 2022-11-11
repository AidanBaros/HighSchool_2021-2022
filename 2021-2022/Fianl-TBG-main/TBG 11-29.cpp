#include <iostream>
#include<algorithm>
#include<string>
#include<random>
using namespace std;

//function declarations (needed for each one you write)
void thingsforall(string s, item &items);
void shop();
void monster();
void combat();
void player();
void map();

//global variables (in general, not a good idea, but for this small of a game, ok)

int MonHealth;
int MonCls;
int MonAT;

int PlrHealth = 100;
int PlrWep;
bool sheild = 0;
bool armour = 0;

int swordAT = 10;
int axeAT = 10;
int maceAT = 10;
int MGswordAT = 15;
int MGaxeAT = 15;
int MGmaceAT = 15;
int stickAT = 1000;

//struct 
struct item {
	bool InInventory;
	bool ActiveWeapon;
	bool ActiveArmor;
	string ItemName;
	int Quantity;
	int BaseAttack;
	int AttackBoost;
};

item inventory[13];

item RustySword;
item Sword;
item MagicSword;
item Axe;
item MagicAxe;
item Mace;
item MagicMace;
item Stick;
item LeatherArmor;
item ChainMaleArmor;
item Sheild;
item Gold;
item HealthPotions;


int main() {
	//Deffining all the struct varables
	RustySword.InInventory = 1;
	RustySword.ActiveWeapon = 1;
	RustySword.ActiveArmor = 0;
	RustySword.ItemName = "Rusty Sword";
	RustySword.Quantity = 1;
	RustySword.BaseAttack = 5;
	RustySword.AttackBoost = 0;
	
	Sword.InInventory = 0;
	Sword.ActiveWeapon = 0;
	Sword.ActiveArmor = 0;
	Sword.ItemName = "Sword";
	Sword.Quantity = 0;
	Sword.BaseAttack = 10;
	Sword.AttackBoost = 0;
	
	MagicSword.InInventory = 0;
	MagicSword.ActiveWeapon = 0;
	MagicSword.ActiveArmor = 0;
	MagicSword.ItemName = "Magic Sword";
	MagicSword.Quantity = 0;
	MagicSword.BaseAttack = 10;
	MagicSword.AttackBoost = 5;
	
	Axe.InInventory = 0;
	Axe.ActiveWeapon = 0;
	Axe.ActiveArmor = 0;
	Axe.ItemName = "Axe";
	Axe.Quantity = 0;
	Axe.BaseAttack = 10;
	Axe.AttackBoost = 0;
	
	MagicAxe.InInventory = 0;
	MagicAxe.ActiveWeapon = 0;
	MagicAxe.ActiveArmor = 0;
	MagicAxe.ItemName = "Magic Axe";
	MagicAxe.Quantity = 0;
	MagicAxe.BaseAttack = 10;
	MagicAxe.AttackBoost = 5;
	
	Mace.InInventory = 0;
	Mace.ActiveWeapon = 0;
	Mace.ActiveArmor = 0;
	Mace.ItemName = "Mace";
	Mace.Quantity = 0;
	Mace.BaseAttack = 10;
	Mace.AttackBoost = 0;
	
	MagicMace.InInventory = 0;
	MagicMace.ActiveWeapon = 0;
	MagicMace.ActiveArmor = 0;
	MagicMace.ItemName = "Magic Mace";
	MagicMace.Quantity = 0;
	MagicMace.BaseAttack = 10;
	MagicMace.AttackBoost = 5;
	
	Stick.InInventory = 0;
	Stick.ActiveWeapon = 0;
	Stick.ActiveArmor = 0;
	Stick.ItemName = "Stick";
	Stick.Quantity = 0;
	Stick.BaseAttack = 1000;
	Stick.AttackBoost = 0;
	
	LeatherArmor.InInventory = 1;
	LeatherArmor.ActiveWeapon = 0;
	LeatherArmor.ActiveArmor = 1;
	LeatherArmor.ItemName = "Leather Armor";
	LeatherArmor.Quantity = 1;
	LeatherArmor.BaseAttack = 0;
	LeatherArmor.AttackBoost = 0;
	
	ChainMaleArmor.InInventory = 0;
	ChainMaleArmor.ActiveWeapon = 0;
	ChainMaleArmor.ActiveArmor = 0;
	ChainMaleArmor.ItemName = "Chain Male Armor";
	ChainMaleArmor.Quantity = 0;
	ChainMaleArmor.BaseAttack = 0;
	ChainMaleArmor.AttackBoost = 0;
	
	Sheild.InInventory = 0;
	Sheild.ActiveWeapon = 0;
	Sheild.ActiveArmor = 0;
	Sheild.ItemName = "Sheild";
	Sheild.Quantity = 0;
	Sheild.BaseAttack = 0;
	Sheild.AttackBoost = 0;
	
	Gold.InInventory = 0;
	Gold.ActiveWeapon = 0;
	Gold.ActiveArmor = 0;
	Gold.ItemName = "Gold";
	Gold.Quantity = 0;
	Gold.BaseAttack = 0;
	Gold.AttackBoost = 0;
	
	HealthPotions.InInventory = 0;
	HealthPotions.ActiveWeapon = 0;
	HealthPotions.ActiveArmor = 0;
	HealthPotions.ItemName = "Health Potion";
	HealthPotions.Quantity = 0;
	HealthPotions.BaseAttack = 0;
	HealthPotions.AttackBoost = 0;

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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 2;
			else if (input.compare("~") == 0)
				room = 64;
			else
				thingsforall(input, item);
			break;
		case 2:
			cout << "You are in room 2." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 13;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 4;
			else if (input.compare("pickup") == 0 && goldtf[0] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[0] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 6:
			cout << "You are in room 6." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 2;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 9;
			else if (input.compare("pickup") == 0 && goldtf[1] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[1] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 11:
			cout << "You are in room 11." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 19;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 12;
			else if (input.compare("pickup") == 0 && goldtf[2] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[2] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 12:
			cout << "You are in room 12." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 14;
			else
				thingsforall(input);
			break;
		case 16:
			cout << "You are in room 16." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 12;
			else
				thingsforall(input);
			break;
		case 21:
			cout << "You are in room 21." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 25;
			else
				thingsforall(input);
			break;
		case 27:
			cout << "You are in room 27." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 36;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 29;
			else if (input.compare("pickup") == 0 && goldtf[3] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[3] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 29:
			cout << "You are in room 29." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 40;
			else if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 31;
			else if (input.compare("pickup") == 0 && goldtf[4] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[4] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 33:
			cout << "You are in room 33." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 25;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 34;
			else if (input.compare("pickup") == 0 && goldtf[5] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[5] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 34:
			cout << "You are in room 34." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 27;
			else if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 43;
			else if (input.compare("pickup") == 0 && goldtf[6] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[6] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 36:
			cout << "You are in room 36." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 37;
			else
				thingsforall(input);
			break;
		case 39:
			cout << "You are in room 39." << endl;
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
					Stick.InInventory = 1;
					Stick.Quantity++;
				}
				else if (success > 1)
					cout << "You did not find anything." << endl;
			}
			else
				thingsforall(input);
			break;
		case 46:
			cout << "You are in room 46." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 40;
			else
				thingsforall(input);
			break;
		case 49:
			cout << "You are in room 49." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 41;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 50;
			else if (input.compare("pickup") == 0 && goldtf[7] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[7] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 50:
			cout << "You are in room 50." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go south") == 0 || input.compare("south") == 0 || input.compare("s") == 0)
				room = 60;
			else if (input.compare("pickup") == 0 && goldtf[8] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[8] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 53:
			cout << "You are in room 53." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 47;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 56;
			else if (input.compare("pickup") == 0 && goldtf[9] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[9] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 56:
			cout << "You are in room 56." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go west") == 0 || input.compare("west") == 0 || input.compare("w") == 0)
				room = 55;
			else
				thingsforall(input);
			break;
		case 57:
			cout << "You are in room 57." << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 58;
			else
				thingsforall(input);
			break;
		case 58:
			cout << "You are in room 58." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 51;
			else if (input.compare("pickup") == 0 && goldtf[0] == 0) {
				int c = rand() % 31 + 20;
				Gold.Quantity += c;
				goldtf[0] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 60:
			cout << "You are in room 60." << endl;
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
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input.compare("go north") == 0 || input.compare("north") == 0 || input.compare("n") == 0)
				room = 54;
			else if (input.compare("go east") == 0 || input.compare("east") == 0 || input.compare("e") == 0)
				room = 63;
			else if (input.compare("pickup") == 0 && goldtf[11] == 0) {
				int c = rand() % 16 + 5;
				Gold.Quantity += c;
				goldtf[11] = 1;
				cout << "You found " << c << " gold" << endl;
			}
			else
				thingsforall(input);
			break;
		case 63:
			cout << "You are in room 63." << endl;
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

void thingsforall(string s, item *items) {
	// this is being applyed to all rooms it is just the things that would be repeated over and over.
	string wall = "Oops you ran into a wall";
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
	else if (s.compare("inventory") == 0){
		cout << "yes or whatever" << endl;
		for (int i = 0; i < 13; i++) {
			cout << inventory[i].InInventory;
			if (inventory[i].InInventory == 1)
				cout << inventory[i].ItemName << endl;
		}

		if (s.compare("active weapon") == 0) {
			cout << "This is your curent active weapon";
			for (int i = 0; i < 13; i++) {
				if (inventory->ActiveWeapon == 1)
					cout << inventory->ItemName[i] << endl;
			}
			cout << endl << endl;
			for (int i = 0; i < 13; i++) {
				if (inventory->BaseAttack > 0 && inventory->InInventory == 1)
					cout << inventory->ItemName[i] << endl;
			}
			cout << "Which weaopn do you want to make active?" << endl;
			for (int i = 0; i < 13; i++) {
				if (s.compare(inventory->ItemName) == 0) {
					cout << inventory->ItemName[i] << " Is now your active item." << endl;
					//inventory->ActiveWeapon[i] = 1;
				}
			}
		}

		else if (s.compare("active armor") == 0) {

		}
	}
	else if (s.compare("help") == 0) {
		cout << "The commands you can do are:" << endl;
		cout << "go north, go south, go east, go west, north, south, east, west, n, s, e, w" << endl;
		cout << "inventory" << endl;
		cout << "gold" << endl;
		cout << "look" << endl;
		cout << "pickup" << endl;
		cout << "open" << endl;
		cout << "investigate" << endl;
		cout << "health" << endl;
	}
	else if (s.compare("gold") == 0)
		cout << "You have " << Gold.Quantity << " gold" << endl;
	else if (s.compare("health") == 0)
		cout << "You are at " << PlrHealth << " HP" << endl;
	else if (s.compare("pickup") == 0)
		cout << "There is nothing to pickup." << endl;
	else if (s.compare("open") == 0)
		cout << "There is nothing to open." << endl;
	else if (s.compare("shop") == 0)
		shop();
	else if (s.compare("map") == 0)
		map();
	else if (s.compare("investigate") == 0)
		cout << "You did not find anything." << endl;
	else
		cout << "sorry, not an option." << endl;
}

void shop() {
	// shop i may add more items in the future
	string input;
	do {
		cout << "Welcom to the shop. \n Choose one item" << endl;
		cout << "A for Axe - 75 gold" << endl;
		cout << "Sw for Sword - 75 gold" << endl;
		cout << "Ma for Mace - 75 gold" << endl;
		cout << "Sh for Sheild - 125 gold" << endl;
		cout << "HP for Health Potion  - 100 gold" << endl;
		cin >> input;
		if (input == "A" && Gold.Quantity >= 75) {
			Axe.InInventory = 1;
			Gold.Quantity -= 75;
		}
		else if (input == "Sw" && Gold.Quantity >=75){
			Sword.InInventory = 1;
			Gold.Quantity -= 75;
		}
		else if (input == "Ma" && Gold.Quantity >= 75) {
			Mace.InInventory = 1;
			Gold.Quantity -= 75;
		}
		else if (input == "Sh" && Gold.Quantity >= 125) {
			Sheild.InInventory = 1;
			Gold.Quantity -= 125;
		}
		else if (input == "HP" && Gold.Quantity >= 100) {
			HealthPotions.InInventory = 1;
			Gold.Quantity -= 100;
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

void player() {
	/*if (inventory[0] == "rusty sword") {
		PlrWep = 1;
	}
	else if (inventory[0] == "sword") {
		PlrWep = 2;
	}
	else if (inventory[0] == "axe") {
		PlrWep = 3;
	}
	else if (inventory[0] == "mace") {
		PlrWep = 4;
	}
	else if (inventory[0] == "MGsword") {
		PlrWep = 5;
	}
	else if (inventory[0] == "MGaxe") {
		PlrWep = 6;
	}
	else if (inventory[0] == "MGmace") {
		PlrWep = 7;
	}
	else if (inventory[0] == "stick") {
		PlrWep = 8;
	}

	if (inventory[1] == "sheild") {
		sheild = 1;
	}

	if (inventory[2] == "MGarmour") {
		armour = 1;
	}*/
}

void combat() {
	int MONAT;
	monster();
	cout << "You have entered combat!" << endl;
	while (PlrHealth >= 0 && MonHealth >= 0) {
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

}
