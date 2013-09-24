#include <iostream>
#include <string>

using namespace std;

string compress(string input) {
	string output = "";
	char c = input[0];
	int count = 1;

	for (int i = 1; i < input.length(); i++) {
		if (c != input[i]) {
			output += c + to_string(count);
			c = input[i];
			count = 1;
		} else {
			count++;
		}
	}

	output += c + to_string(count);
	return output.length() >= input.length() ? input : output;
}

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	cout << compress(input) << endl;
	return 0;
}