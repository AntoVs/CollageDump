#include <stdio.h>
#include<stdlib.h>

struct node{
	int data,priority;
	struct node*next;
}*start=NULL;

void display(){
	if(start == NULL)
		printf("LL Underflow\n");
	else{
		struct node*temp = start;
		while (temp != NULL){
			printf("%d ", temp->data);
        	if(temp->next != NULL)
        		printf(" -> ");
        	temp=temp->next;
        }
	printf("\n");
    }
}



void insert(int data,int priority){
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	newn->priority=priority;
	if(start==NULL||start->priority <= priority){
		newn->next=start;
		start=newn;
	}
	else{
		struct node*temp=start;
		while(temp->next!=NULL && temp->next->priority >= priority){
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
	printf("%d inserted at priority %d",data,priority);
}

void deletenode(){
	if(start==NULL)
		printf("PRIORITY QUEUE underflow");
	else{
	struct node*temp=start;
	printf("deleted element is %d with priority %d",temp->data,temp->priority);
	start=start->next;
	free(temp);
	}
}

int main(){
	int ch,data,priority;
	do{
		printf("\n__MENU__\n");
		printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
		printf("Enter choice:");
		scanf("%d",&ch);
		switch (ch){
			case 1: 
				printf("Enter data and priority: ");
				scanf("%d",&data);
				scanf("%d",&priority);
				insert(data,priority);
				break;
			case 2:
				deletenode();
				break;
			case 3: 
				display();
				break;
			case 4: 
				printf("EXITING");
				break;
		}
	}while(ch!=4);
	return 0;
	}
