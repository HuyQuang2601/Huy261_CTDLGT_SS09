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

int layDoDai(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    printf("Danh sách hiện tại: 10 <-> 25 <-> 40 <-> 65 <-> 80 -> NULL\n");

    int doDai = layDoDai(head);
    printf("📏 Độ dài của danh sách liên kết là: %d\n", doDai);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}