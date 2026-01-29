#include <stdio.h>

int front = -1, rear = -1;
int queue[5];            

//add  element to queue
void enqueue(int data) {
    if (rear == 4) {
        printf("Queue is full (overflow).\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

//remove  element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty (underflow).\n");
    } else if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

int main() {
    // adding
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);   
    dequeue();
   
    if (front == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
    return 0;
}