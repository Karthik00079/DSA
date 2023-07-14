#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        default:
            return 0;
    }
}

void infixToPostfix(char *expression) {
    struct Stack stack;
    stack.top = -1;
    char postfix[MAX_SIZE];
    int i, j;

    for (i = 0, j = 0; expression[i] != '\0'; i++) {
        if (isalnum(expression[i])) {
            postfix[j++] = expression[i];
        } else if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1 || stack.items[stack.top] != '(') {
                printf("Invalid Expression\n");
                return;
            }
            pop(&stack);
        } else if (isOperator(expression[i])) {
            while (stack.top != -1 && precedence(expression[i]) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, expression[i]);
        }
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid Expression\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an Infix Expression: ");
    fgets(expression, MAX_SIZE, stdin);

    infixToPostfix(expression);

    return 0;
}
