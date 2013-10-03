#include <iostream>
#include <time.h>
#include <stack>

using namespace std;

struct node {
	node *next;
	char value;
};

// Prints the full list and then prints the loop after |
void printNodes(node *list) {
	for (node *cur = list; cur != NULL; cur = cur->next) {
		cout << cur->value << " ";
	}
	cout << endl;
}

node *createList(string word) {
	node *list = new node;
	list->value = word[0];
	node *cur = list;

	for (int i = 1; i < word.length(); i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = word[i];
	}
	cur->next = NULL;

	return list;
}

bool isPalindrome(node *list) {
	node *slow = list;
	node *fast = list;
	stack<char> saved;
	int count = 0;

	while (fast) {
		saved.push(slow->value);
		fast = fast->next;
		count++;
		if (fast){
			fast = fast->next;
			count++;
		}
		slow = slow->next;
	}

	if (count % 2 != 0) {
		saved.pop();
	}

	while (slow) {
		char check = saved.top();
		saved.pop();
		if (check != slow->value) return false;
		slow = slow->next;
	}

	return true;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	string input;
	getline(cin, input);

	node *list = createList(input);

	cout << "Word: " << endl;
	printNodes(list);

	cout << isPalindrome(list) << endl;

	return 0;
}