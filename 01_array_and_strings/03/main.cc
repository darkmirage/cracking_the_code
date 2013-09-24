#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool isAnagramSort(string first, string second) {
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	return first == second;
}

bool isAnagramArray(string first, string second) {
	// TODO
}

map<char, int> countCharacters(string word) {
	map<char, int> result;
	for (int i = 0; i < word.length(); i++) {
		char c = word[i];
		if (result.find(c) == result.end()) result[c] = 0;
		result[c]++;
	}
	return result;
}

bool isAnagramMap(string first, string second) {
	map<char, int> first_counts = countCharacters(first);
	map<char, int> second_counts = countCharacters(second);
	if (first_counts.size() != second_counts.size()) return false;
	for (pair<const char, int> kv : first_counts) {
		if (second_counts[kv.first] != kv.second)
			return false;
	}
	return true;
}

bool isAnagram(string first, string second) {
	if (first.length() != second.length()) return false; // easy optimization
	return isAnagramSort(first, second);
}

int main(int argc, char *argv[]) {
	string first, second;
	getline(cin, first);
	getline(cin, second);
	cout << isAnagram(first, second) << endl;
	return 0;
}