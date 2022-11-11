#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int main() {

    stack<int> Binary;

    int Decimal;
    cout << "Enter a number: ";
    cin >> Decimal;
    int intoStack;
    while(Decimal / 2 != 0) {
        intoStack = Decimal % 2;
        Decimal = floor(Decimal / 2);
        Binary.push(intoStack);
    }
    Binary.push(1);
    int size = Binary.size();
    for (int i = 0; i < size; i++)
    {
        cout << Binary.top();
        Binary.pop();
    }
