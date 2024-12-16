#include <stdio.h>

void inputArray(int arr[], int *size) {
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", size);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int length(int size) {
    return size;
}

int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int max(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong.\n");
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[100];
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cua chung\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu\n");
        printf("5. Tim phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                displayArray	(arr, size);
                break;
            case 3:
                printf("Do dai mang: %d\n", length(size));
                break;
            case 4:
                printf("Tong cac phan tu: %d\n", sum(arr, size));
                break;
            case 5:
                printf("Phan tu lon nhat: %d\n", max(arr, size));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);

    return 0;
}
