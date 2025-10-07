#include <stdio.h>

int front=-1,rear=-1;

void Enqueuerear(int dq[],int N,int data){
	if (front==(rear+1)%N)
  		printf("DEque Overflow,Insertion is not possible\n");
	else if (front==-1 && rear==-1){
  		front =0;
  		rear=0;
  		dq[rear]=data;
 	}
 	else {
  		rear=(rear+1)%N;
  		dq[rear]=data;
	}
}
 
void Enqueuefront(int dq[],int N,int data){
 	if (front==(rear+1)%N)
  		printf("DEque Queue Overflow,Insertion is not possible\n");
	else if (front==-1 && rear==-1){
  		front =0;
  		rear=0;
  		dq[rear]=data;
 	}
 	else if(front==0) {
		front=N-1;
  		dq[front]=data;
 	}
 	else {
  		front=front-1;
  		dq[front]=data;
 	}
}

void Dequefront(int dq[],int N){
 	if (front==-1 && rear==-1)
  		printf("DEque Queue Underflow !\n");
 	else if(front == rear){
  		int d=dq[front];
  		printf("Deleted element:%d\n",d);
  		front=-1;
  		rear=-1;
 	}
 	else {
  		int d=dq[front];
  		printf("Deleted element:%d\n",d);
  		front=(front+1)%N;
 	}
}

void Dequerear(int dq[],int N){
 	if (front==-1 && rear==-1)
  		printf("DEQue Underflow !\n");
 	else if(front == rear){
  		int d=dq[rear];
  		printf("Deleted element:%d\n",d);
  		front=-1;
  		rear=-1;
 	}
 	else if (rear==0){
  		int d=dq[rear];
  		printf("Deleted element:%d\n",d);
  		rear=N-1;
 	}
 	else {
  		int d=dq[rear];
  		printf("Deleted element:%d\n",d);
  		rear=rear-1;
 	}
}

void Display(int dq[],int N){
    	if (front==-1) {
        	printf("DEque Queue Underflow\n");
        	return;
    	}
    	printf("DEque Queue elements are: ");
    	for (int i = front; ; i=(i+1)%N) {
        	printf("%d ",dq[i]);
        	if(i==rear)
            	break;
    	}
    	printf("\n");
}

int main(){
 	int dq[100],n,num,ch,innerch;
 	printf("Enter a max number of elements in DEque: ");
    	scanf("%d", &n);

	do {
        	printf("\n___MENU___\n");
        	printf("1. Input restricted DEque\n2. Output restricted DEque\n3. Exit menu\n");
        	printf("Enter your choice: ");
        	scanf("%d", &ch);

        switch (ch) {
		case 1:
	    		do{
				printf("\nMenu\n1.InsertionAtrear\n2.DeletionAtfront\n3.DeletionAtrear\n4.Display\n5.Exit\n");
             			printf("Enter your choice: ");
         			scanf("%d", &innerch);

	         		if(innerch==1) {
        	        		printf("Enter a number to insert into DEque from rear: ");
                			scanf("%d", &num);
                			Enqueuerear(dq,n,num);
            			}
            			else if (innerch ==2)
             				Dequefront(dq,n);
	            		else if(innerch==3)
        	     			Dequerear(dq,n);
            			else if(innerch==4)
             				Display(dq,n);
	        	}while(innerch!=5);
        		break;

		case 2:
    			do{
				printf("\nMenuInside\n1.InsertionAtrear\n2.InsertionAtfront\n3.DeletionAtfront\n4.Display\n5.Exit\n");
			        printf("Enter your choice: ");
         			scanf("%d", &innerch);
			if (innerch==1) {
                		printf("Enter a number to insert into DEque from rear: ");
				scanf("%d", &num);
                		Enqueuerear(dq,n,num);
            		}
            		else if(innerch==2){
                		printf("Enter a number to insert into DEque from front: ");
                		scanf("%d", &num);
                		Enqueuefront(dq,n,num);
            		}
            		else if(innerch==3)
                		Dequefront(dq,n);
            		else if(innerch==4){
                		Display(dq,n);
            		}
        		}while(innerch!=5);
        		break;

		case 3:
            		printf("Exit the menu\n");
            		break;

        	default:
            		printf("Invalid choice, try again\n");
            		break;
		}
	} while (ch != 3);
 	return 0;
}
