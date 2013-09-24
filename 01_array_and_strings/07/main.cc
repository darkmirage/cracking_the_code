#include <iostream>
#include <cstdlib>

using namespace std;

void propagateZero(int *matrix, int m, int n) {
	bool *rows = (bool *) calloc(m, sizeof(bool));
	bool *cols = (bool *) calloc(n, sizeof(bool));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i * n + j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (rows[i] || cols[j]) matrix[i * n + j] = 0;
		}
	}
}

void printMatrix(int *matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << to_string(matrix[i * n + j]) << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int m = 5;
	int n = 10;
	int matrix[m * n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i * n + j] = 1;
		}
	}
	matrix[3 * n + 4] = 0;
	matrix[1 * n + 7] = 0;
	cout << "Original" << endl;
	printMatrix(matrix, m, n);

	propagateZero(matrix, m, n);
	cout << "Modified" << endl;
	printMatrix(matrix, m, n);
	return 0;
}