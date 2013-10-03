#include <iostream>
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

node *randomNumber(int digits) {
	node *number = new node;
	number->value = rand() % 10;
	node *cur = number;
	for (int i = 0; i < digits; i++) {
		cur->next = new node;
		cur = cur->next;
		cur->value = rand() % 10;
	}
	cur->next = NULL;

	return number;
}

node *add(node *n1, node *n2) {
	node *top = n1;
	node *bottom = n2;

	node *sum_head = NULL;
	node *sum = NULL;

	int carry = 0;
	while (top && bottom) {
		int total = top->value + bottom->value + carry;
		if (total > 9) {
			carry = 1;
			total -= 10;
		} else {
			carry = 0;
		}

		if (sum_head == NULL) {
			sum_head = new node;
			sum = sum_head;
		} else {
			sum->next = new node;
			sum = sum->next;
		}
		sum->next = NULL;
		sum->value = total;

		top = top->next;
		bottom = bottom->next;
	}

	node *remaining = NULL;
	if (top) remaining = top;
	if (bottom) remaining = bottom;

	while (remaining) {
		sum->next = new node;
		sum = sum->next;
		sum->next = NULL;
		int total = remaining->value + carry;
		if (total > 9) {
			carry = total / 10;
			total -= 10;
		} else {
			carry = 0;
		}
		sum->value = total;
		remaining = remaining->next;
	}

	if (carry != 0) {
		sum->next = new node;
		sum = sum->next;
		sum->next = NULL;
		sum->value = carry;
		carry = 0;
	}

	return sum_head;
}

node *recursiveAdd(node *n1, node *n2, int carry) {
	if (!n1 && !n2 && carry == 0) {
		return NULL;
	}

	node *nn1, *nn2;
	node *sum = new node;
	int total = carry;

	if (n1) {
		total += n1->value;
		nn1 = n1->next;
	} else {
		nn1 = NULL;
	}

	if (n2) {
		total += n2->value;
		nn2 = n2->next;
	} else {
		nn2 = NULL;
	}

	if (total > 9) {
		carry = total / 10;
		total -= 10;
	} else {
		carry = 0;
	}

	sum->value = total;
	sum->next = recursiveAdd(nn1, nn2, carry);
	return sum;
}

node *recursiveAdd(node *n1, node *n2) {
	return recursiveAdd(n1, n2, 0);
}

int reverseAdd(node **result, node *n1, node *n2) {
	if (!n1 && !n2) return 0;

	node *sum = new node;
	int total = 0;
	node *nn1, *nn2;

	if (n1) {
		total += n1->value;
		nn1 = n1->next;
	} else {
		nn1 = NULL;
	}

	if (n2) {
		total += n2->value;
		nn2 = n2->next;
	} else {
		nn2 = NULL;
	}

	int carry = reverseAdd(&(sum->next), nn1, nn2);

	total += carry;
	if (total > 9) {
		carry = total / 10;
		total -= 10;
	} else {
		carry = 0;
	}
	sum->value = total;
	*result = sum;
	return carry;
}

node *reverseAdd(node *n1, node *n2) {
	node *sum = NULL;

	int carry = reverseAdd(&sum, n1, n2);
	if (carry > 0) {
		node *head = new node;
		head->value = carry;
		head->next = sum;
		sum = head;
	}

	return sum;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	node *n1 = randomNumber(5);
	node *n2 = randomNumber(5);

	cout << "n1  : ";
	printNodes(n1);
	
	cout << "n2  : ";
	printNodes(n2);

	cout << "sum1: ";
	printNodes(add(n1, n2));

	cout << "sum2: ";
	printNodes(recursiveAdd(n1, n2));

	cout << "sum3: ";
	printNodes(reverseAdd(n1, n2));
	return 0;
}