#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo nút mới
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

// Hàm in từng nút
void printNodes(Node* head) {
    Node* current = head;
    int index = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
}

// Hàm main
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printNodes(head);

    return 0;
}
