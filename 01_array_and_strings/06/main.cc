#include <iostream>
#include <string>

using namespace std;

void rotateImage(int *image, int size) {
	for (int layer = 0; layer < size / 2; layer++) {
		int first = layer;
		int last = size - 1 - first;
		for (int j = first; j < last; j++) {
			int offset = j - first;
			int top = image[first * size + j];
			image[first * size + j] = image[(last - offset) * size + first];
			image[(last - offset) * size + first] = image[last * size + last - offset];
			image[last * size + last - offset] = image[j * size + last];
			image[j * size + last] = top;
		}
	}
}

void printImage(int *image, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << to_string(image[i*size + j]) << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int size = 5;
	int image[size][size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			image[i][j] = i;
		}
	}
	cout << "Original" << endl;
	printImage((int *)image, size);

	rotateImage((int *)image, size);
	cout << "Rotated" << endl;
	printImage((int *)image, size);
	return 0;
}