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

void daoNguoc(struct Node** head_ref) {
    struct Node* temp = NULL;
    struct Node* current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Danh sách trống.\n");
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
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);

    head->next = n2;
    n2->prev = head; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3;

    printf("🔄 Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    daoNguoc(&head);

    printf("✅ Danh sách sau khi đảo ngược:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}