#include<iostream>
using namespace std;

int CircleArea(int(rad));

int main() {
	int input;

	cout << "Input the radius of your circle" << endl;
	cin >> input;

	cout << "The are of your circle with a radius of " << input << " is " << CircleArea(input) << endl;
}

int CircleArea(int(rad)) {
	double A = (3.1416 * (rad * rad));
	return A;
}
