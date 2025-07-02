//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>

// Hàm sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Tìm chỉ số phần tử nhỏ nhất trong đoạn chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử ở vị trí i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
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

    // Gọi hàm sắp xếp
    selectionSort(arr, n);

    printf("Mang sau khi sap xep (Selection Sort):\n");
    printArray(arr, n);

    return 0;
}
