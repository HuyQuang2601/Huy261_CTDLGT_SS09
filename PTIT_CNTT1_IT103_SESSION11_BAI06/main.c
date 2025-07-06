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

void xoaPhanTuDau(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }

    struct Node* temp = *head_ref;

    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }

    free(temp);
}

void printList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }
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

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;

    printf("Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    printf("Thực hiện xóa phần tử đầu...\n");
    xoaPhanTuDau(&head);

    printf("Danh sách sau khi xóa phần tử đầu:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}