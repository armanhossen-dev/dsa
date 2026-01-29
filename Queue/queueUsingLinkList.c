#include <stdio.h>
#include <stdlib.h>

struct q {
    int num;
    struct q *next;
};

struct q *f = NULL;
struct q *r = NULL;

void enqueue(int data) {
    struct q *newq = (struct q *)malloc(sizeof(struct q));
    if (newq == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newq->num = data;
    newq->next = NULL;

    if (r == NULL) {
        f = r = newq;
    } else {
        r->next = newq;
        r = newq;
    }
    printf("Added %d to the queue.\n", data);
}

void dequeue() {
    if (f == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct q *temp = f;
    f = f->next;

    if (f == NULL) {
        r = NULL;
    }

    printf("Removed %d from the queue.\n", temp->num);
    free(temp);
}

void print_out() {
    if (f == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct q *current = f;
        while (current != NULL) {
            printf("%d ", current->num);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    enqueue(35);

    print_out();
    dequeue();
    dequeue();
    print_out();

    return 0;
}
