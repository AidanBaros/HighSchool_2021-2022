#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void rev(string x);

int main() {
	string data;
	cout << "enter the num" << endl;
	cin >> data;
	rev(data);
}


void rev(string x) {
	int leg = x.length();
	vector<string> duck;
	string temp;
	for (int i = 0; i <= leg; i++) {
		temp = x.substr(i, 1);
		duck.push_back(temp);
	}
	cout << endl << "Now in reverse" << endl << endl;
	for (int i = 0; i <= leg; i++) {
		cout << duck.back();
		if (leg > 1){
			duck.pop_back();
		}
		
	}

}
