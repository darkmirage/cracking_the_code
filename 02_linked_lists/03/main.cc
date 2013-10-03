#include <iostream>
#include <string>

using namespace std;

struct node {
	node *next;
	int value;
};

int deleteNode(node *cur) {
	node *next = cur->next;
	cur->value = next->value;
	cur->next = next->next;
	delete next;
}

void printNodes(node *list) {
	for (node *cur = list; cur != NULL; cur = cur->next) {
		cout << cur->value << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	node *list = new node;
	list->value = 0;
	node *cur = list;
	for (int i = 1; i < 5; i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = i;
	}
	cur->next = NULL;

	cout << "Original" << endl;
	printNodes(list);

	deleteNode(list->next->next);

	cout << "Deleted third node" << endl;
	printNodes(list);

	return 0;
}