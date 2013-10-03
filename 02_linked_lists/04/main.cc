#include <iostream>
#include <time.h>

using namespace std;

struct node {
	node *next;
	int value;
};

void separateList(node **ls, int value) {
	node *list = *ls;
	node *left = NULL;
	node *right = NULL;
	node *right_head = NULL;

	node *cur = list;
	while (cur) {
		node *next = cur->next;
		if (cur->value < value) {
			if (left == NULL) {
				*ls = cur;
				left = cur;
			} else {
				left->next = cur;
				left = cur;
			}
		} else {
			if (right == NULL) {
				right_head = cur;
				right = cur;
			} else {
				right->next = cur;
				right = cur;
			}
		}
		cur = next;
	}

	if (left == NULL) {
		*ls = right_head;
	} else {
		left->next = right_head;
	}

	if (right) {
		right->next = NULL;
	}
}


void printNodes(node *list) {
	for (node *cur = list; cur != NULL; cur = cur->next) {
		cout << cur->value << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	node *list = new node;
	list->value = rand() % 10;
	node *cur = list;
	for (int i = 0; i < 30; i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = rand() % 10;
	}
	cur->next = NULL;

	cout << "Original" << endl;
	printNodes(list);
	
	int value = list->value;
	separateList(&list, value);
	
	cout << "Separated by x = " << value << endl;
	printNodes(list);

	return 0;
}