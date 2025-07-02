//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>

#define MAX 1000

// Hàm hoán đổi 2 số nguyên
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm in mảng 2 chiều
void printMatrix(int a[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

// Hàm sắp xếp cột k theo thứ tự tăng dần
void sortColumn(int a[][MAX], int rows, int k) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (a[i][k] > a[j][k]) {
                // Hoán đổi cả hàng theo cột k
                for (int col = 0; col < MAX; col++) {
                    swap(&a[i][col], &a[j][col]);
                }
            }
        }
    }
}

int main() {
    int rows, cols;
    int a[MAX][MAX];

    do {
        printf("Nhap so hang (0 < rows < 1000): ");
        scanf("%d", &rows);
        printf("Nhap so cot (0 < cols < 1000): ");
        scanf("%d", &cols);
    } while (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000);

    printf("Nhap cac phan tu cua ma tran %d x %d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMa tran truoc khi sap xep:\n");
    printMatrix(a, rows, cols);

    int k;
    do {
        printf("\nNhap chi so cot can sap xep (0 <= k < %d): ", cols);
        scanf("%d", &k);
    } while (k < 0 || k >= cols);

    // Sắp xếp cột k
    sortColumn(a, rows, k);

    printf("\nMa tran sau khi sap xep cot %d tang dan:\n", k);
    printMatrix(a, rows, cols);

    return 0;
}
