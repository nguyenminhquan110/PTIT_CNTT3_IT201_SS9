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

// In danh sách
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

// Thêm phần tử vào đầu danh sách
Node* insertAtHead(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode; // newNode trở thành head mới
}

// Hàm main
int main() {
    // Tạo danh sách 1->2->3->4->5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sách ban đầu
    printList(head);

    // Nhập giá trị cần thêm
    int x;
    printf("Nhập số cần thêm vào đầu danh sách: ");
    scanf("%d", &x);

    // Thêm vào đầu danh sách
    head = insertAtHead(head, x);

    // In danh sách sau khi thêm
    printList(head);

    return 0;
}
