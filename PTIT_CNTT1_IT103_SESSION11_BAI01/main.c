#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    printf("Danh sách các phần tử: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = createNode(10);
    struct Node* second = createNode(25);
    struct Node* third = createNode(40);
    struct Node* fourth = createNode(65);
    struct Node* fifth = createNode(80);

    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;

    printList(head);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}