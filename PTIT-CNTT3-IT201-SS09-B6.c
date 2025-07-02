#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo một nút mới
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

// In danh sách liên kết
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

// Xóa phần tử đầu tiên của danh sách
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL; // Danh sách rỗng

    Node* temp = head;       // Giữ node đầu để giải phóng
    head = head->next;       // Cập nhật head mới
    free(temp);              // Giải phóng node cũ

    return head;
}

// Hàm main
int main() {
    // Tạo danh sách: 1->2->3->4->5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sách ban đầu
    printList(head);

    // Xóa phần tử đầu
    head = deleteHead(head);

    // In danh sách sau khi xóa
    printList(head);

    return 0;
}
