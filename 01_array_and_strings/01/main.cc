#include <iostream>
#include <map>

using namespace std;

// Flat array implementation
bool allUnique(string word) {
	int counts[256] = { 0 };
	for (int i = 0; i < word.length(); i++) {
		char c = word[i];
		counts[c]++;
		if (counts[c] > 1) return false;
	}
	return true;
}

// Map implementation
bool allUniqueMap(string word) {
	map<char, int> counts;
	for (int i = 0; i < word.length(); i++) {
		char c = word[i];
		if (counts.find(c) == counts.end()) counts[c] = 0;
		counts[c]++;
		if (counts[c] > 1) return false;
	}
	return true;
}

// O(1) memory O(n^2) implementation
bool allUniqueCompact(string word) {
	for (int i = 0; i < word.length(); i++) {
		for (int j = i + 1; j < word.length(); j++) {
			if (word[i] == word[j]) return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	string result = allUnique(input) ? "true" : "false";
	cout << result << endl;
	return 0;
}