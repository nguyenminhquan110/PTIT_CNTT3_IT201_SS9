#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cấu trúc một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// In danh sách theo dạng 1->2->3->...->NULL
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

// Tìm kiếm giá trị trong danh sách, trả về true/false
bool search(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target)
            return true;
        current = current->next;
    }
    return false;
}

// Hàm main
int main() {
    // Tạo danh sách liên kết 1->2->3->4->5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sách
    printList(head);

    // Nhập giá trị cần tìm
    int x;
    printf("Nhập số cần tìm: ");
    scanf("%d", &x);

    // Tìm kiếm và in kết quả
    if (search(head, x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
