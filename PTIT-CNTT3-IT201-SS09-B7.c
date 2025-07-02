//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>

#define MAX 1000

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm phân chia số âm, 0 và dương
void customSort(int input[], int output[], int n) {
    int index = 0;

    // Đưa số âm vào đầu
    for (int i = 0; i < n; i++) {
        if (input[i] < 0)
            output[index++] = input[i];
    }

    // Đưa số 0 vào giữa
    for (int i = 0; i < n; i++) {
        if (input[i] == 0)
            output[index++] = input[i];
    }

    // Đưa số dương vào cuối
    for (int i = 0; i < n; i++) {
        if (input[i] > 0)
            output[index++] = input[i];
    }
}

int main() {
    int n;
    int arr[MAX], result[MAX];

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    printf("Nhap %d so nguyen (co the am, 0, hoac duong):\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nMang truoc khi sap xep:\n");
    printArray(arr, n);

    customSort(arr, result, n);

    printf("\nMang sau khi sap xep (am -> 0 -> duong):\n");
    printArray(result, n);

    return 0;
}
