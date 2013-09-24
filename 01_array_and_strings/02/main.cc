#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void reverse(char *word) {
	char *start = word;
	char *end = start;
	while (*end != '\0') end++;
	end--;
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	char *word = (char *) calloc(input.length() + 1, sizeof(char));
	memcpy(word, input.c_str(), input.length());
	reverse(word);
	cout << word << endl;
	free(word);
	return 0;
}