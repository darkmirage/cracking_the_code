#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void replace(string &str, int len) {
	int spaces = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') spaces++;
	}
	int end = len + spaces * 2 - 1;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[end] = '0';
			str[end - 1] = '2';
			str[end - 2] = '%';
			end -= 3;
		} else {
			str[end] = str[i];
			end--;
		}
	}
}

// This mostly serves to set up the inputs as described by the problem.
string encode(string input) {
	string result = input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') result += "  ";
	}
	replace(result, input.length());
	return result;
}

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	cout << encode(input) << endl;
	return 0;
}