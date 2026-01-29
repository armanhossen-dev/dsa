#include <stdio.h>
int stack[10];
int top = -1;

void push(int num) {
    if (top == 9) {
        printf("Stack is full. Cannot push %d.\n", num);
    } else {
        top++;
        stack[top] = num;
        printf("Pushed %d to the stack.\n", num);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}


void P_stack() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Current stack elements (from top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("\nStack after pushing elements:\n");
    P_stack();

    pop();
    printf("\nStack after popping one element:\n");
    P_stack();

    return 0;
}
