#include<iostream>
#include<random>
#include<string>
#include<Windows.h>
#include<ctime>
using namespace std;

bool running = 0;

int main(){
	srand(time(NULL));
	
	string pre[] = { "Dr", "Dw", "L", "M", "Qu", "Thr", "Tr", "Tw", "Scr", "Sl", "Sm", "Sp", "Spl", "Squ", "Wh","Y" };
	string vow[] = { "a", "e", "i", "o", "u", "ee", "oo" };
	string e1[] = { "bb", "ck", "dd", "mf", "mp", "mpf", "ng", "nk", "pp", "rf", "rk", "rp", "zz" };
	string e2[] = { "aldo", "et", "et", "le", "le", "le", "o", "ok" };
		
	do {
		
		cout << pre[rand() % 16] << vow[rand() % 7] << e1[rand() % 13] << e2[rand() % 8] << endl;
		
		system("pause");
		system("cls");

	} while (running == 0);

}
