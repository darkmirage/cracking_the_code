#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string hay, string needle) {
	return hay.find(needle) != string::npos;
}

bool isRotation(string s1, string s2) {
	return s1.length() == s2.length() && isSubstring(s1 + s1, s2);
}

int main(int argc, char *argv[]) {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	cout << isRotation(s1, s2) << endl;

	return 0;
}