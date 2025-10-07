#include <stdio.h>

int inputsprx(int rows, int cols, int sparse[50][3]){
	int val,k=1;

	printf("enter elements %d x %d :\n",rows,cols);
	for (int i=0 ;i < rows ; ++i ){
		for (int j=0; j < cols ; ++j){
			scanf("%d", &val);
			if (val != 0){
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = val;
				k++;
			}

		}
	}
	sparse[0][0] = rows;
	sparse[0][1] = cols;
	sparse[0][2] = k-1;	//non zero numbers assumed ,change if not correct -_-
	
	return k;
}

void disp(int sparse[50][3], int count){
	printf("the matrix in sparse form (triplet ) : \n");
	for (int i=0 ;i < count ; ++i)
		printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

void addsprx(){
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
			k++;
		} else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
			C[k][0] = B[j][0];
			C[k][1] = B[j][1];
			C[k][2] = B[j][2];
			j++;
			k++;
		} else {
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2] + B[j][2];
			i++;
			j++;
			k++;
		}
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

}

int main(){
	int choice,rows,cols,n1,n2,n3;
	int A[50][3], B[50][3], C[50][3];

	while(1){
		printf("\n");
		printf("1. Addition \n");
		printf("2. transpose \n");
		printf("3. exit \n");
		printf("enter your choice :");
		scanf ("%d", &choice);
	
	switch(choice){
		case 1 :
			printf("enter the number of rows and cols : ");
			scanf ("%d %d", &rows, &cols);

			printf("enter matrix 1 :\n");
			n1 = inputsprx(rows ,cols ,A);
			disp(A, n1);

			printf("enter matrib 2 :\n");
			n2 = inputsprx(rows ,cols ,B);
			disp(B, n2);

			n3 = addsprx(A, B, C);
			printf("resultant sparx matrix :\n");
			disp(C ,n3);

			break;
		
		case 2 :
			printf("enter the number of rows and cols : ");
			scanf ("%d %d", &rows, &cols);
			n = inputsprx(rows ,cols ,sparse);
			disp(sparse, n);
			break;

		case 3 :
			return 0;
		
		default :
			printf("enter valid option bro : :) \n");
			break;
		}
	}
}
