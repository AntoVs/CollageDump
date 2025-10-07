#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *lc, *rc;
}*root = NULL;

struct tree* insert(struct tree* ptr, int val) {
	if(ptr == NULL){
        	struct tree* newn = (struct tree*)malloc(sizeof(struct tree));
		if(newn == NULL){
		printf("Memory allocation failed!\n");
		return NULL;
        }
        newn->data = val;
        newn->lc = NULL;
        newn->rc = NULL;
        return newn;
	}else{
        	if(val < ptr->data)
            		ptr->lc = insert(ptr->lc, val);
        	else if(val > ptr->data)
            		ptr->rc = insert(ptr->rc, val);
        	else
            printf("Node existed in BST\n");
    }
    return ptr;
}

struct tree* search(struct tree* ptr, int skey) {
    if (ptr == NULL) {
        return NULL;
    }
    if (ptr->data == skey) {
        return ptr;
    }
    if (skey < ptr->data) {
        return search(ptr->lc, skey);
    } else {
        return search(ptr->rc, skey);
    }
}

struct tree* successor(struct tree* ptr) {
    while (ptr->lc != NULL) {
        ptr = ptr->lc;
    }
    return ptr;
}

struct tree* delete(struct tree* ptr, int val) {
	if (ptr != NULL && ptr->data != val){
        	if (val > ptr->data)
			ptr->rc = delete(ptr->rc, val);
        	else
			ptr->lc = delete(ptr->lc, val);
	}else{
        	if(ptr == NULL){
            		printf("%d Node not found\n", val);
            		return ptr;
        	}
        	if(ptr->lc == NULL && ptr->rc == NULL) {
            		free(ptr);
            		return NULL;
        	}else if (ptr->lc != NULL && ptr->rc == NULL){
            		struct tree* par = ptr->lc;
			free(ptr);
            		return par;
        	}else if (ptr->lc == NULL && ptr->rc != NULL){
            		struct tree* par = ptr->rc;
            		free(ptr);
            		return par;
        	}else if(ptr->lc != NULL && ptr->rc != NULL) {
            		struct tree* succ = successor(ptr->rc);
            		ptr->data = succ->data;
            		ptr->rc = delete(ptr->rc, succ->data);
		}
	}
	return ptr;
}

void inorder(struct tree *node) {
	if(node != NULL){
        	inorder(node->lc);
        	printf(" %d ", node->data);
        	inorder(node->rc);
    	}
}

void preorder(struct tree* node) {
	if(node != NULL) {
		printf(" %d ", node->data);
        	preorder(node->lc);
        	preorder(node->rc);
	}
}

void postorder(struct tree* node) {
	if(node != NULL){
        	postorder(node->lc);
        	postorder(node->rc);
        	printf(" %d ", node->data);
	}
}

int main(){
    int ch,val;
    struct tree*res;

    while(1){
        printf("\nbst\n1.Insertion\n2.Deletion\n3.Inorder\n4.Preorder\n5.Postorder\n6.SearchForNode\n7.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                res = search(root, val);
                if (res != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}
