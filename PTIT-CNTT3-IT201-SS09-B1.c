#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong danh sách liên kết đơn
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo một nút mới với giá trị cho trước
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    // Tạo danh sách liên kết đơn với 5 phần tử bất kỳ
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // In danh sách
    printf("Danh sách liên kết gồm 5 phần tử:\n");
    printList(head);

    return 0;
}
