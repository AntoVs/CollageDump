#include <stdio.h>

void inputarr(int arr[10],int *n ,int *k){

	printf("enter the number of elements : ");
	scanf( "%d", n);
	for (int i=0 ; i< *n ; i++){
		printf ("enter element no %d :", i +1);
		scanf ("%d" ,& arr[i]);
		printf("\n");
	}

	printf("enter the key : ");
	scanf ("%d" , k);
	printf("\n");
}

void disp(int arr[10], int n){
	printf("array elements are : ");
	for (int i=0 ; i<n ; i++){
		printf (" %d " ,arr[i]);
	}
printf ("\n");
}


int linearsearch(int arr[10], int n, int k){
	for (int i=0; i<n; i++){
		if (arr[i] == k)
			return i;
		}	
return -1;
}

void sortarr(int arr[10], int n){
	for (int i= 0; i < n-1 ;i++ ){
		for (int j= 0; j < n-i-1 ;j++){
			if (arr[j] > arr[j+1])	{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int BinSrchRec(int arr[10],int low , int high ,int k){
	if (low > high)
		return -1;
	
	int mid = (low + high)/2;
	if (arr[mid] == k)
		return mid;
	else if (arr[mid] < k)
		return BinSrchRec(arr, mid +1, high, k);
	else
		return BinSrchRec(arr, low, mid-1 ,k);

}

int main(){
	int choice;
	int arr[10];
	int n,k;

	while(1){
		printf ("\n");
		printf ("1. linear search \n");
		printf ("2. binary search \n");
		printf ("3. exit \n");
		printf ("enter your choice : ");
		scanf  ("%d", &choice);
		printf ("\n");
	
	switch(choice){
		case 1 :
			{
				printf("enter the array to linear search \n");
				inputarr(arr, &n, &k);
				disp(arr, n);
				int index = linearsearch( arr, n, k);
				if (index != -1)
					printf("\n element found at position %d \n", index+1);
				else 
					printf("\n element not found \n");
				break;
			}
		case 2 :
			{
				printf("enter the array to binary search\n");
				inputarr(arr, &n, &k);
				disp(arr, n);
				sortarr(arr, n);
				printf ("sorted ");
				disp(arr,n);
				int high = n-1,low = 0;
				int bindex = BinSrchRec(arr,low,high,k);

				if (bindex != -1)
					printf ("element found at position %d \n",bindex +1);
				else 
					printf ("element not found \n");
				break;
			}
		case 3 :
			{
				printf("exiting \n");
				return 0;
			}
		default : printf ("enter a valid choice \n");
		}
	}
return 0;
}
