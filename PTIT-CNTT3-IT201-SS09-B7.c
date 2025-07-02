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
        printf("Lỗi cấp phát bộ nhớ\n");
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

// Chèn node vào vị trí bất kỳ
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);

    // Nếu chèn vào đầu hoặc danh sách rỗng
    if (position <= 0 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int index = 0;

    // Duyệt đến vị trí trước vị trí cần chèn
    while (current->next != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Chèn node mới
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Hàm main
int main() {
    // Tạo danh sách ban đầu: 1->2->3->4->5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sách ban đầu
    printList(head);

    // Nhập giá trị và vị trí
    int value, position;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &position);

    // Thêm vào danh sách
    head = insertAtPosition(head, value, position);

    // In danh sách sau khi chèn
    printList(head);

    return 0;
}
