#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string message;
		cout << "Enter your message (lowercase only):\n";
		getline(cin, message);
		string type;
		cout << "Would you like to encode or decode?\n";
		cin >> type;
		
		if (type == "encode") {
			for (int i = 0; i < message.size(); i++) {
				if (message[i] >= 97 and message[i] <= 122) {
					message[i] = message[i] += 3;
				}
				if (message[i] > 122) {
					message[i] = message[i] -= 26;
				}
			}
			cout << "After encoding, the message is now:\n" << message << "\n\n\n";
		}
		else if (type == "decode") {
			for (int i = 0; i < message.size(); i++) {
				if (message[i] >= 97 and message[i] <= 122) {
					message[i] = message[i] -= 3;
				}
				if (message[i]+3 >= 97 and message[i] < 97) {
					message[i] = message[i] += 26;
				}
			}
			cout << "After decoding, the message is now:\n" << message << "\n\n\n";
		}
		else {
			cout << "Invalid input, please type either \"encode\" or \"decode\" next time\n\n\n";
		}
		getchar(); //clears the buffer? maybe?
	}
}
