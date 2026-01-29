#include <stdio.h>
#include <stdlib.h>

//define  structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// insert  node at the beginning
struct Node* add_first(struct Node* head, int data) {
    struct Node* new_n = (struct Node*)malloc(sizeof(struct Node));
    new_n->data = data;
    new_n->prev = NULL;
    new_n->next = head;
    if (head != NULL) {
        head->prev = new_n;
    }
    return new_n;
}




// insert node at a specific index
void add_Index(struct Node* head, int index, int data) {
    struct Node* new_n = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int i = 0;

    while (i != index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        new_n->data = data;
        new_n->next = temp->next;
        new_n->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = new_n;
        }
        temp->next = new_n;
    }
}

// insert  at the end
void add_end(struct Node* head, int data) {
    struct Node* new_n = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    new_n->data = data;
    new_n->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    new_n->prev = temp;
    temp->next = new_n;
}

// print the list from start to end
void s_list(struct Node* head) {
    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// print  list from end to start
void s_rev(struct Node* head) {
    struct Node* temp = head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List (Reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // creating nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 5;
    head->prev = NULL;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 15;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 25;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    // print list before insertions
    printf("Before adding new elements:\n");
    s_list(head);
    s_rev(head);

    //insertions
    head = add_first(head, 1);    
    add_Index(head, 2, 12);      
    add_end(head, 35);            

    // print after insertions
    printf("\nAfter adding new elements:\n");
    s_list(head);
    s_rev(head);

    return 0;
}