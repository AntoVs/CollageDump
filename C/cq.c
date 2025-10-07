#include <stdio.h>

int front = -1, rear = -1, cq[20];

//enque
void Eq(int data, int n){
	if(front == (rear + 1)%n)
		printf("CQ Overflow !\n");
	else if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		cq[rear] = data;
	}
	else{
		rear = (rear + 1)%n;
		cq[rear] = data;
	}
}
//deque
void Dq(int n){
	int data;
	if(front == -1 && rear == -1)
		printf("CQ Underflow !\n");
	else if(front == rear){
		data = cq[front];
		front = -1;
		rear = -1;
		printf("\n Deleted element is : %d \n",data);
	}
	else {
		data = cq[front];
		front = (front + 1) % n;
		printf("\n Deleted element is : %d \n",data);
	}
}
//display
void Dp(int n){
	if (front == -1 && rear == -1)
		printf("q underflow ! \n");
	else{
	int i = front;
		while(1){
			printf("%d  ",cq[i]);
			if (i == rear)
				break;
			i = (i + 1) % n;
		}
	printf("\n");
	}
}
//isfull
void isfull(int n){
	if(front == (rear + 1)%n)
		printf("CQ full !\n");
	else
		printf("not full\n");
}
//isempty
void isempty(){
	if (front == -1 && rear == -1)
		printf("empty ! \n");
	else
		printf("not empty \n");
}

int main(){
	int data,ch,n;
	printf("Enter the size of CircularQ : ");
	scanf("%d",&n);

	while(1){
		printf("Menu :\n1.Enqueue \n2.Dequeue \n3.Display \n4.ISfull \n5.IsEmpty \n6.exit : \nEnter your choice : ");
		scanf("%d", & ch);
		
		switch(ch){
		case 1:
			printf("enter data to Enque : ");
			scanf("%d",&data);
			Eq(data,n);
			break;
		
		case 2 :
			Dq(n);
			break;
		
		case 3 :
			Dp(n);
			break;
			
		case 4 :
			isfull(n);
			break;
		case 5 :
			isempty();
			break;
		case 6 :
			return 0;

		default :
			printf("enter a valid choice !");
		}

	}
}


