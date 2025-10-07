#include <stdio.h>

char stack[100];
int top = -1;

int evalStack[100];
int evalTop = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

void pushEval(int val) {
    evalStack[++evalTop] = val;
}

int popEval() {
    if (evalTop == -1)
        return -1;
    return evalStack[evalTop--];
}

int precedence(char cc) {
    if (cc == '^')
        return 3;
    if (cc == '*' || cc == '/')
        return 2;
    if (cc == '+' || cc == '-')
        return 1;
    return 0;
}

void infixtopostfix(int n, char postfix[]) {
    char infix[100], cc;
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((cc = infix[i]) != '\0') {
//character is an oprnd
        if ((cc >= 'a' && cc <= 'z') || (cc >= 'A' && cc <= 'Z') || (cc >= '0' && cc <= '9')) {
            postfix[j++] = cc;
        }
//character is (
        else if (cc == '(') {
            push(cc);
        }
//character is ) pop from the stck
        else if (cc == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
//character is operatr
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(cc)) {
                postfix[j++] = pop();
            }
            push(cc);
        }
        i++;
    }

// Pop remainint hings
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

// postfix
void postfixeval(char postfix[]) {
    int i = 0, op1, op2, result;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
//chr is oprnd
        if (ch >= '0' && ch <= '9') {
            pushEval(ch - '0');
        } 
        else {
// Pop two operands and apply the operator
            op1 = popEval();
            op2 = popEval();

            switch (ch) {
                case '+': 
			result = op2 + op1;
			break;
                case '-':
			result = op2 - op1; 
			break;
                case '*':
			result = op2 * op1;
			break;
                case '/':
			result = op2 / op1; 
			break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return;
            }
            pushEval(result);//push to stck
        }
    }

    printf("Result = %d\n", popEval());
}

int main() {
    int choice, n;
    char postfix[100];

    do {
        printf("\nMenu\n");
        printf("1.Infix to Postfix Conversion\n");
        printf("2.Postfix Evaluation\n");
        printf("3.Exit Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter no of terms in infix expression: ");
                scanf("%d", &n);
                infixtopostfix(n, postfix);
                break;
            case 2:
                postfixeval(postfix);
                break;
            case 3:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}

