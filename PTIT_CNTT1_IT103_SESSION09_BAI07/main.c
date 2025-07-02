#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* addNoteAtLast(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return  newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* addNotePos(Node* head, int value, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int index = 0;
    while (current->next != NULL && index < pos - 1) {
        current = current->next;
        index++;
    }
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Khong con cho trong");
        free(newNode);
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = addNoteAtLast(head, 1);
    head = addNoteAtLast(head, 2);
    head = addNoteAtLast(head, 3);
    head = addNoteAtLast(head, 4);
    head = addNoteAtLast(head, 5);
    printList(head);
    head = addNotePos(head, 6, 3);
    printList(head);
    return 0;
}