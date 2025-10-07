#include <stdio.h>

int main(){
	int poly1[40], poly2[40], res[40];
	int n1,n2,maxdegree;

	printf("enter the degree of the polynomial 1 : ");
	scanf("%d",&n1);
	for (int i=0; i<=n1; i++){
		printf("enter the coefficient of x^%d :",i);
		scanf("%d", &poly1[i]);
		printf("\n");
	}
	printf("\n enter the degree of the polynomial 2 :");
	scanf ("%d",&n2);
	for (int i=0; i<=n2; i++){
		printf("enter the coefficient of x^%d :",i);
		scanf("%d",&poly2[i]);
		printf("\n");
	}
	
	if(n1 > n2 )
		maxdegree = n1;
	else maxdegree = n2;

	for (int i=0; i <=maxdegree ;i++){
		res[i] = poly1[i] + poly2[i];
	}	

	for (int i=0; i <= maxdegree; i++){
		printf("%d x^%d ",res[i],i);
		if (i != (maxdegree))
			printf(" + ");
	}
	printf("\n");
	return 0;
}
