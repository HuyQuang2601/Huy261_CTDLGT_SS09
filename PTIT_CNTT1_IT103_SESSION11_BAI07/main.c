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

void themVaoViTriBatKy(struct Node** head_ref, int newData, int position) {
    if (position == 1) {
        themVaoDau(head_ref, newData);
        return;
    }

    struct Node* newNode = createNode(newData);
    struct Node* current = *head_ref;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Vị trí %d không hợp lệ. Vị trí phải nhỏ hơn hoặc bằng độ dài + 1.\n", position);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    newNode->prev = current;
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
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);

    head->next = n2;
    n2->prev = head; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3;

    printf("Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    int valueToAdd, position;
    printf("Nhập giá trị cần thêm: ");
    scanf("%d", &valueToAdd);
    printf("Nhập vị trí muốn thêm: ");
    scanf("%d", &position);

    themVaoViTriBatKy(&head, valueToAdd, position);

    // 4. IN RA DANH SÁCH SAU KHI THÊM
    printf("\nDanh sách sau khi thêm:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}