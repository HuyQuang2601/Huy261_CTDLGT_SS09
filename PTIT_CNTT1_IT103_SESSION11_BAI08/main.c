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

void xoaTaiViTri(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Lỗi: Danh sách đang rỗng, không thể xóa.\n");
        return;
    }

    struct Node* current = *head_ref;

    if (position == 1) {
        *head_ref = current->next;
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL;
        }
        free(current); // Giải phóng node đầu cũ
        printf("Đã xóa thành công phần tử ở đầu danh sách.\n");
        return;
    }

    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Lỗi: Vị trí %d không hợp lệ hoặc không tồn tại.\n", position);
        return;
    }


    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Đã xóa thành công phần tử ở vị trí %d.\n", position);
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
    struct Node* n5 = createNode(50);

    head->next = n2;
    n2->prev = head; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4;

    printf("Danh sách ban đầu:\n");
    printList(head);
    printf("\n");

    int position;
    printf("Nhập vị trí bạn muốn xóa (bắt đầu từ 1): ");
    scanf("%d", &position);

    xoaTaiViTri(&head, position);

    printf("\nDanh sách sau khi xóa:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}