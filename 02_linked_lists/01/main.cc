#include <iostream>
#include <string>
#include <map>
#include <time.h>

using namespace std;

struct node {
	node *next;
	int value;
};

void printNodes(node *list) {
	for (node *cur = list; cur != NULL; cur = cur->next) {
		cout << cur->value << " ";
	}
	cout << endl;
}

// O(n) memory and O(n) runtime
void removeDuplicates(node *list) {
	map<int, node *> positions;
	for (node *cur = list; cur != NULL; cur = cur->next) {
		if (positions.find(cur->value) == positions.end()) {
			positions[cur->value] = cur;
		}
	}

	node *prev = list;
	for (node *cur = list->next; cur != NULL; cur = cur->next) {
		if (positions[cur->value] != cur) {
			prev->next = cur->next;
			delete cur;
			cur = prev;
		} else {
			prev = cur;
		}
	}
}

// O(1) memory and O(n^2) runtime
void removeDuplicatesNoMap(node *list) {	
	for (node *cur = list; cur != NULL; cur = cur->next) {
		node *prev = cur;
		for (node *check = cur->next; check != NULL; check = check->next) {
			if (cur->value == check->value) {
				prev->next = check->next;
				delete check;
				check = prev;
			} else {
				prev = check;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

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

	removeDuplicates(list);

	cout << "Remove Duplicates" << endl;
	printNodes(list);

	return 0;
}