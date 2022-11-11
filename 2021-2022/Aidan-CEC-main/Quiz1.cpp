#include<iostream>
using namespace std;

int main()
{
	int in;

	for (int i = 0; i <= 70; i += 10) 
	{
		cout << i << " ";
	}

	cout << endl << endl;

	for (int i = 20; i > -20; i -= 1)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	for (int i = 3; i <= 1875; i *= 5)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	for (int i = 1; i <= 12; i ++)
	{
		for (int j = 1; j <= 8; j ++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "How many times do you want to shuffle the deck" << endl;
	cin >> in;

	int l = 1;
	while (l <= in)
	{
		cout << "shuffle" << endl;
		l++;
	}
}






//for (int i = 0; i >= 70; i += 10)
//{
//	for (int j = 0; j >= 70; j += 10)
//	{
//
//	}
//}
