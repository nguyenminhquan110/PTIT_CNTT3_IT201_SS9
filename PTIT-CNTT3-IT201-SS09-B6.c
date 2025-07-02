//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>

// Hàm trộn hai mảng con đã được sắp xếp
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // Tạo mảng tạm

    // Sao chép dữ liệu vào mảng tạm
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn mảng tạm lại vào arr[left..right]
    i = 0; // chỉ số mảng L
    j = 0; // chỉ số mảng R
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép các phần tử còn lại nếu có
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Hàm merge sort đệ quy
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Đệ quy chia nhỏ
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gộp lại sau khi chia
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep (Merge Sort):\n");
    printArray(arr, n);

    return 0;
}
