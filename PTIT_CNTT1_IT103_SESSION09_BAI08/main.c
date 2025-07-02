#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* addNoteAtLast(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap nhat that bai");
        return 0;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteAtIndex(Node* head, int index) {
    if (head == NULL) {
        printf("Danh sach rong khong the xoa");
        return NULL;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    int count = 0;
    while (count < index - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    if (current != NULL && current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    } else {
        printf("Vi tri khong hop le");
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
    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);
    head = deleteAtIndex(head, pos);
    printList(head);
    return 0;
}