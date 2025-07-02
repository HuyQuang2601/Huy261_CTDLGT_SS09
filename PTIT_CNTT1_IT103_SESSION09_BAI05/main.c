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
    head = addNoteAtFirst(head, 1);
    head = addNoteAtFirst(head, 2);
    head = addNoteAtFirst(head, 3);
    head = addNoteAtFirst(head, 4);
    printList(head);
    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);
    if (value <= 0) {
        printf("So khong hop le");
        return 0;
    }
    head = addNoteAtFirst(head, value);
    printList(head);
    return 0;
}