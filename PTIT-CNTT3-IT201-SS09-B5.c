//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>

// Hàm hoán đổi 2 giá trị
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm chia mảng và trả về chỉ số pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1;        // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Đặt pivot vào đúng vị trí
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Hàm quick sort đệ quy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Chia mảng

        quickSort(arr, low, pi - 1);  // Sắp xếp mảng bên trái
        quickSort(arr, pi + 1, high); // Sắp xếp mảng bên phải
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int arr[n];

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep:\n");
    printArray(arr, n);

    // Gọi hàm quick sort
    quickSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep (Quick Sort):\n");
    printArray(arr, n);

    return 0;
}
