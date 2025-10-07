#include <stdio.h>
int t,d,front=-1,rear=-1;
void Enqueue(int q[],int data,int N){
	if (rear==N-1){
	printf("Queue Overflow");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=data;
	}
	else
	{
		rear++;
		q[rear]=data;
	}
}
void Dequeue(int q[]){
	if (front==-1 && rear==-1){
	printf("Queue Underflow,Deletion is not possible");
	}
	else if(front == rear){
		d = q[front];
		printf("Deleted element : %d\n",d);
		front == -1;
		rear == -1;
	}
	else
	{
		d = q[front];
	 	printf("Deleted element:%d\n",d);
	 	front++;
	 
	}
}
void IsEmpty(){
	if (front == -1 && rear == -1){
		printf("Queue underflow\n");
	}
	else
	{
		printf("Queue is not empty\n");
	}
}
void IsFull(int N){
	if (rear == N-1)
		printf("Queue Overflow\n");
	else
		printf("Queue is not full\n");
}
void Display(int q[])
{
	if (front==-1 && rear==-1){
		printf("Queue underflow\n");
		return;
	}
	printf("Queue elements are:");
	for(int i=front;i<=rear;i++){
		printf("%d ",q[i]);
	}
	printf("\n");
}

int main(){
	int q[10],N,num,ch;
	printf("Enter a max no of elements in queue:");
	scanf("%d",&N);

	while(1){
		printf("\nMenu : \n");
		printf("1.Enqueue\n2.Dequeue\n3.IsEmpty\n4.IsFull\n5.Display\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			printf("Enter a no to insert into queue:");
			scanf("%d",&num);
			Enqueue(q,num,N);
			break;
		case 2:
			Dequeue(q);
			break;
		case 3:
			IsEmpty();
			break;
		case 4:
			IsFull(N);
			break;
		case 5:
			Display(q);
			break;
		case 6:
			printf("Exitting....\n");
			return 0;
		default:
			printf("Invalid choice !\n");
			break;
		}
	}
}	
	
