#include <iostream>
#include <time.h>

using namespace std;

struct node {
	node *next;
	int value;
};

// Prints the full list and then prints the loop after |
void printNodes(node *list, int elems) {
	int counter = 0;
	for (node *cur = list; cur != NULL; cur = cur->next) {
		if (counter == 2 * elems) break;
		if (counter == elems) cout << "| ";
		cout << cur->value << " ";
		counter++;
	}
	cout << endl;
}

node *createCircularList(int elems, int loop_at) {
	node *list = new node;
	list->value = 0;
	node *cur = list;
	node *loop;

	for (int i = 1; i < elems; i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = i;
		if (loop_at == i) loop = cur;
	}

	if (loop_at == 0) loop = list;
	cur->next = loop;

	return list;
}

bool findLoop(node *list) {
	node *slow = list;
	node *fast = list;
	for(;;) {
		if (!slow) return false;
		slow = slow->next;
		if (!fast) return false;
		fast = fast->next;
		if (!fast) return false;
		fast = fast->next;

		if (slow == fast) break;
	}

	slow = list;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	cout << "Loop at: ";
	cout << fast->value << endl;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	int elems = 10;
	node *list = createCircularList(elems, rand() % elems);

	cout << "Circular List" << endl;
	printNodes(list, elems);

	findLoop(list);

	return 0;
}