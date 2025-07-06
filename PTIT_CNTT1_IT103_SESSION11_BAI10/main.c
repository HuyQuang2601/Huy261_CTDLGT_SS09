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

void hoanViCapLienKe(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }

    struct Node* p = *head_ref;
    struct Node* q = p->next;

    *head_ref = q;

    while (1) {
        struct Node* temp = q->next;

        q->next = p;
        q->prev = p->prev;
        p->next = temp;
        p->prev = q;

        if (q->prev != NULL) {
            q->prev->next = q;
        }
        if (temp != NULL) {
            temp->prev = p;
        } else {
            break;
        }
        p = temp;
        if (p->next == NULL) {
            break;
        }
        q = p->next;
    }
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
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(40);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->prev = head->next->next->next;


    printf("🔗 Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    hoanViCapLienKe(&head);

    printf("✅ Danh sách sau khi hoán vị các cặp liền kề:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}