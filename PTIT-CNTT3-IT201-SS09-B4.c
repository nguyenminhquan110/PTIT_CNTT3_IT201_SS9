#include <stdio.h>
#include <stdlib.h>

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

// In danh sách dạng 1->2->3->...->NULL
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

// Đếm số lượng phần tử trong danh sách
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    // Đếm số phần tử và in ra kết quả
    int total = countNodes(head);
    printf("Danh sách liên kết có %d phần tử\n", total);

    return 0;
}
