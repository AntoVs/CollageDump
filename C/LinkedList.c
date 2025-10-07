#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node*next;
}*start=NULL;

void display(){
	if(start == NULL)
		printf("LL Underflow\n");
	else{
		struct node* temp = start;
		while (temp != NULL){
			printf("%d ", temp->data);
        	if(temp->next != NULL)
        		printf(" -> ");
        	temp=temp->next;
        }
	printf("\n");
    }
}

int count(){
	int n=0;
	struct node*temp = start;
	while (temp != NULL){
		n++;
		temp = temp->next;
	}
	return n;
}

void insert(int data, int pos){
	int n = count();
	struct node* temp = start;
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->data = data;
	newn->next = NULL;

	if(pos<1 || pos>n+1){
		printf("Invalid position.\n");
        	return;
	}
	if(pos == 1){
        	newn->next = start;
        	start = newn;
    	}
	else if (pos==n + 1){
	if (start==NULL){
		start=newn;
		newn->next =NULL;
        }
        else{
		while (temp->next !=NULL){
               temp = temp->next;
		}
	temp->next=newn;
	newn->next =NULL;
        }
    }
    else {
        for(int i=1; i<pos-1; i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}
void delete(int pos){
    int n=count();
    if (pos<1 || pos>n){
        printf("Invalid position\n");
        return;
    }
    struct node*temp = start;
    if (pos==1) {
        start = temp->next;
        free(temp);
    }
    else if (pos == n) {
        struct node* prev =NULL;
        while (temp->next !=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next =NULL;
        free(temp);
    }
    else{
        for(int i =1; i < pos-1; i++){
            temp=temp->next;
        }
        struct node* del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
}

void deleteValue(int data) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node*temp =start;
    struct node*prev =NULL;
    if (temp !=NULL && temp->data==data) {
        start = temp->next;
        free(temp);
        printf("Node with data %d deleted\n", data);
        return;
    }
    while (temp !=NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp ==NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    prev->next =temp->next;
    free(temp);
    printf("Node with data %d deleted\n", data);
}

int main(){
    int ch,n,data,pos;
    while (1){
	printf("\nMENU\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch){
            case 1:
                do{
                    printf("\nInsertion Menu\n1.Insertion at Beginning\n2.Insertion at End\n3.Insertion at Specific Position\n4.Exit\nEnter your choice: ");
                    scanf("%d",&n);
                    switch(n) {
                        case 1:
                            printf("Enter the data: ");
                            scanf("%d",&data);
                            insert(data,1);
                            break;
                        case 2:
                            printf("Enter the data: ");
                            scanf("%d",&data);
                            insert(data,count() + 1);
                            break;
                        case 3:
                            printf("Enter the data: ");
                            scanf("%d",&data);
                            printf("Enter the position: ");
                            scanf("%d",&pos);
                            insert(data,pos);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                    }
                } while(n!=4);
                break;
            case 2:
                do {
                    printf("\nDeletion Menu\n1.Deletion at Beginning\n2.Deletion at End\n3.Deletion by node\n4.Exit\nEnter your choice: ");
                    scanf("%d", &n);
                    switch (n) {
                        case 1:
                            delete(1);
                            break;
                        case 2:
                            delete(count());
                            break;
                        case 3:
                            printf("Enter the node: ");
                            scanf("%d", &data);
                            deleteValue(data);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                    }
                } while(n!=4);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
