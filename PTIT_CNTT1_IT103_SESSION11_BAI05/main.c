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

void themVaoDau(struct Node** head_ref, int newData) {
    struct Node* newNode = createNode(newData);

    newNode->next = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }

    *head_ref = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* n2 = createNode(25);
    struct Node* n3 = createNode(40);
    struct Node* n4 = createNode(65);
    struct Node* n5 = createNode(80);

    head->next = n2;
    n2->prev = head; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4;

    printf("Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    int valueToAdd;
    printf("Mời bạn nhập số nguyên để thêm vào đầu danh sách: ");
    scanf("%d", &valueToAdd);

    themVaoDau(&head, valueToAdd);

    printf("\nDanh sách sau khi thêm %d vào đầu:\n", valueToAdd);
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}