#include <stdio.h>
int main(){
	int n,i,j, temp;
	int at[10],bt[10],ct[10],tat[10],wt[10];
	int time = 0;
	int tota = 0,totwt = 0,totet = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Enter AT and BT for P%d: ", i+1);
		scanf("%d %d", &at[i], &bt[i]);
	}
/*	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
        		if(at[i] > at[j]) {
            			temp = at[i];
           			at[i] = at[j];
				at[j] = temp;
            			temp = bt[i];
            			bt[i] = bt[j];
            			bt[j] = temp;
        		}
    		}
	}
*/
	for(i = 0; i < n; i++){
		if(time < at[i]) time = at[i];
		ct[i] = time + bt[i];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		time = ct[i];
		tota = tota + tat[i];
		totwt = totwt + wt[i];
//		totet = totet + bt[i];
	}
	printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
	printf("Avg Tat = %.2f\n",(float)(tota/n));
	printf("Avg wt = %.2f\n",(float)(totwt/n));
	printf("Throughput = %.2f\n",(float)n/time);
	return 0;
}
