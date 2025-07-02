//
// Created by Macbook Air on 2/7/25.
//
#include <stdio.h>
#include <string.h>

// Hàm hoán đổi 2 ký tự
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp các ký tự trong chuỗi theo thứ tự a → z
void sortCharacters(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                swap(&str[i], &str[j]);
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Nhap chuoi ky tu: ");
    fgets(str, sizeof(str), stdin);

    // Xóa ký tự newline nếu có
    str[strcspn(str, "\n")] = '\0';

    printf("Chuoi truoc khi sap xep: %s\n", str);

    // Gọi hàm sắp xếp ký tự
    sortCharacters(str);

    printf("Chuoi sau khi sap xep: %s\n", str);

    return 0;
}
