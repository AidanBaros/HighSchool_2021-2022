#include<iostream>
#include<random>
#include<ctime>
#include<Windows.h>
using namespace std;


int main() {
	srand(time(NULL));
	int something = 42;
	int whatever = 1;
	int thing = 0;
	do {
		whatever = rand() % 50 + 1;
		cout << whatever << endl;
		thing++;
		Beep(500,100);

	} while (whatever != something);
	cout << "It took " << thing << " trys to get to 42." << endl;
}
