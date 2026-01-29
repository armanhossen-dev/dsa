#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int n) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = n;
    new->next = top;
    top = new;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    pop();

    struct Node *current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    return 0;
}