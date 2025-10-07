#include <stdio.h>

int push(int stack[], int data, int n, int top) {
    if (top == n - 1)
        printf("Stack is full\n");
    else {
        top++;
        stack[top] = data;
    }
    return top;
}

int pop(int stack[], int top) {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Element deleted: %d\n", stack[top]);
        top--;
    }
    return top;
}

void peek(int stack[], int top) {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void isfull(int top, int n) {
    if (top == n - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is not Full\n");
}

void isempty(int top) {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[100], n, ch, data, top = -1;

    printf("Enter the size of stack: ");
    scanf("%d", &n);

    while (1) {
        printf("\nChoice Menu:\n1. Insertion\n2. Deletion\n3. Peek\n4. IsEmpty\n5. IsFull\n6. Display\n7. Exit\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                top = push(stack, data, n, top);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                isempty(top);
                break;
            case 5:
                isfull(top, n);
                break;
            case 6:
                display(stack, top);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

