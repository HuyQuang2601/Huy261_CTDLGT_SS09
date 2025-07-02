#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* addNoteAtFirst(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* deleteNoteAtLast(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return NULL;
    }
    Node* current = head;
    head = head->next;
    free(current);
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
    head = addNoteAtFirst( head,1);
    head = addNoteAtFirst(head,2);
    head = addNoteAtFirst(head,3);
    head = addNoteAtFirst(head,4);
    printList(head);
    head = deleteNoteAtLast(head);
    printList(head);
    return 0;
}