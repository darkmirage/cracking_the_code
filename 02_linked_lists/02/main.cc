#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct node {
	node *next;
	int value;
};

int findLastElement(node *list, int k) {
	int total = 0;
	for (node *cur = list; cur != NULL; cur = cur->next) {
		total++;
	}
	for (int i = 0; i < total - k; i++) {
		list = list->next;
	}
	if (k > total) cout << "ERROR" << endl;
	return list->value;
}

void printNodes(node *list) {
	for (node *cur = list; cur != NULL; cur = cur->next) {
		cout << cur->value << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	string input;
	getline(cin, input);
	int k = stoi(input);

	node *list = new node;
	list->value = 1;
	node *cur = list;
	for (int i = 0; i < 30; i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = rand() % 10;
	}
	cur->next = NULL;

	cout << "Original" << endl;
	printNodes(list);
	cout << k << "th last element: " << findLastElement(list, k) << endl;

	return 0;
}