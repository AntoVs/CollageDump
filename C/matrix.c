#include <stdio.h>

int inputsprx(int rows, int cols, int sparse[50][3]) {
	int val, k = 1;

	printf("Enter elements (%d x %d):\n", rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			scanf("%d", &val);
			if (val != 0) {
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = val;
				k++;
			}
		}
	}
	sparse[0][0] = rows;
	sparse[0][1] = cols;
	sparse[0][2] = k - 1; // Number of non-zero elements
	return k;
}

void disp(int sparse[50][3], int count) {
	printf("The matrix in sparse form (triplet):\n");
	for (int i = 0; i < count; ++i)
		printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

int addsprx(int A[50][3], int B[50][3], int C[50][3]) {
	if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
		printf("Addition not possible. Dimensions mismatch.\n");
		return 0;
	}

	int i = 1, j = 1, k = 1;
	C[0][0] = A[0][0];
	C[0][1] = A[0][1];

	while (i <= A[0][2] && j <= B[0][2]) {
		if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2];
			i++;
		} else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
			C[k][0] = B[j][0];
			C[k][1] = B[j][1];
			C[k][2] = B[j][2];
			j++;
		} else {
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2] + B[j][2];
			i++;
			j++;
		}
		k++;
	}
	while (i <= A[0][2]) {
		C[k][0] = A[i][0];
		C[k][1] = A[i][1];
		C[k][2] = A[i][2];
		i++;
		k++;
	}
	while (j <= B[0][2]) {
		C[k][0] = B[j][0];
		C[k][1] = B[j][1];
		C[k][2] = B[j][2];
		j++;
		k++;
	}
	C[0][2] = k - 1;
	return k;
}

int transpose(int sparse[50][3], int trans[50][3]) {
	int k = 1;
	trans[0][0] = sparse[0][1]; // new rows
	trans[0][1] = sparse[0][0]; // new cols
	trans[0][2] = sparse[0][2]; // non-zero count remains

	for (int col = 0; col < sparse[0][1]; col++) {
		for (int i = 1; i <= sparse[0][2]; i++) {
			if (sparse[i][1] == col) {
				trans[k][0] = sparse[i][1]; // new row
				trans[k][1] = sparse[i][0]; // new col
				trans[k][2] = sparse[i][2]; // value
				k++;
			}
		}
	}
	return k;
}

int main() {
	int choice, rows, cols, n1, n2, n3;
	int A[50][3], B[50][3], C[50][3];

	while (1) {
		printf("\n1. Addition\n2. Transpose\n3. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter number of rows and columns: ");
				scanf("%d %d", &rows, &cols);

				printf("Enter matrix 1:\n");
				n1 = inputsprx(rows, cols, A);
				disp(A, n1);

				printf("Enter matrix 2:\n");
				n2 = inputsprx(rows, cols, B);
				disp(B, n2);

				n3 = addsprx(A, B, C);
				if (n3 > 0) {
					printf("Resultant sparse matrix (after addition):\n");
					disp(C, n3);
				}
				break;

			case 2:
				printf("Enter number of rows and columns: ");
				scanf("%d %d", &rows, &cols);

				printf("Enter matrix:\n");
				n1 = inputsprx(rows, cols, A);
				disp(A, n1);

				n2 = transpose(A, B);
				printf("Transposed matrix (sparse form):\n");
				disp(B, n2);
				break;

			case 3:
				printf("Exiting...\n");
				return 0;

			default:
				printf("Enter a valid option, bro! :)\n");
				break;
		}
	}
}

