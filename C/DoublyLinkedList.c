#include<stdio.h>
#include<stdlib.h>

struct dll{
	int data;
	struct dll *prev, *next;
}*start = NULL;

void IB(int val){
	struct dll *newn = (struct dll*)malloc(sizeof(struct dll));
	newn -> data = val;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(start == NULL){
		start = newn;
	}else{
		newn -> next = start;
		start -> prev = newn;
		start = newn;
	}
}

void IE(int val){
	struct dll *newn = (struct dll*)malloc(sizeof(struct dll));
	newn -> data = val;
      	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(start == NULL){
                start = newn;
        }else{
		struct dll *temp = start;
		while(temp -> next != NULL)
			temp = temp->next;
		temp -> next = newn;
		newn -> prev = temp;
	}
}

void IN(int val, int key) {
	if (start == NULL) {
		printf("List is empty\n");
		return;
	}

	struct dll *temp = start;
	while (temp != NULL && temp->data != key) {
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("Element not found.\n");
		return;
	}

	struct dll *newn = (struct dll*)malloc(sizeof(struct dll));
	newn->data = val;
	newn->next = temp->next;
	newn->prev = temp;
    
	if(temp->next != NULL)
		temp->next->prev = newn;
		temp->next = newn;
}

void DB(){
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dll *temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    printf("Deleted Element is : %d \n",temp -> data);
    free(temp);
}

void DE(){
	if(start == NULL){
        	printf("List is empty.\n");
        	return;
	}
	struct dll *temp = start;
	while(temp -> next != NULL)
		temp = temp -> next;
	if (temp -> prev != NULL)
		temp -> prev -> next = NULL;
	else
		start = NULL;
	printf("Deleted Element is : %d\n",temp -> data);
	free(temp);
}

void DS(int key){
	if (start == NULL){
		printf("List is empty.\n");
		return;
	}
	struct dll *temp = start;
	while (temp != NULL && temp->data != key)
		temp = temp->next;
	if (temp == NULL) {
		printf("Element not found.\n");
		return;
	}
	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	}
	if(temp->next != NULL)
		temp->next->prev = temp->prev;
	if(temp == start)
		start = temp->next;
	printf("Deleted Element is : %d\n",temp -> data);
	free(temp);
}

void displayForward() {
	struct dll *temp = start;
	if(temp == NULL) {
		printf("List is empty.\n");
        return;
	}
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void displayBackward() {
	if (start == NULL) {
		printf("List is empty.\n");
		return;
	}
	struct dll *temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main(){
	int ch,key,data;
	while(1){
		printf("\n1.Insertion at beginning \n");	
		printf("2.Insertion at end \n");
		printf("3.Insertion after node \n");
		printf("4.Deletion at beginning \n");	
		printf("5.Deletion at end \n");
		printf("6.Deletion a specified node \n");
		printf("7.Display foreward \n");
		printf("8.Display Backward \n");
		printf("9.Exit \n");
		printf("Enter yr choice : ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("enter data : ");
				scanf("%d", &data);
				IB(data);
				break;
			case 2:
				printf("enter data : ");
				scanf("%d", &data);
				IE(data);
				break;
			case 3:
				printf("Enter val after which to insert : ");
				scanf("%d", &key);
				printf("enter data : ");
				scanf("%d", &data);
				IN(data ,key);
				break;
			case 4:
				DB();
				break;
			case 5:
				DE();
				break;
			case 6:
				printf("Enter value to delete : ");
				scanf("%d", &key);
				DS(key);
				break;
			case 7:
				displayForward();
				break;
			case 8:
				displayBackward();
				break;
			case 9:
				return(0);
			default:
				printf("invalid ch !");
				break;
		}
	}
	return(0);
}
