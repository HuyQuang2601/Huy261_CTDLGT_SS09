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

void duyetVaInDanhSach(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");

    current = head;
    int i = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

int main() {
    struct Node* head = createNode(1);
    struct Node* n2 = createNode(2);
    struct Node* n3 = createNode(3);
    struct Node* n4 = createNode(4);
    struct Node* n5 = createNode(5);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    duyetVaInDanhSach(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}