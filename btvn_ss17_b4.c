#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void sortArrayAsc(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortArrayDesc(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int searchElement(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int arr[100], size, choice, target, index;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   1. Tang dan\n");
        printf("   2. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Cac phan tu la so chan: ");
                for (int i = 0; i < size; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("Cac phan tu la so nguyen to: ");
                for (int i = 0; i < size; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 4:
                reverseArray(arr, size);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Chon phuong thuc sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                int sortChoice;
                scanf("%d", &sortChoice);

                if (sortChoice == 1) {
                    sortArrayAsc(arr, size);
                    printf("Mang sau khi sap xep tang dan: ");
                } else if (sortChoice == 2) {
                    sortArrayDesc(arr, size);
                    printf("Mang sau khi sap xep giam dan: ");
                } else {
                    printf("Lua chon khong hop le.\n");
                    break;
                }
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                index = searchElement(arr, size, target);
                if (index != -1) {
                    printf("Phan tu %d tim thay tai vi tri %d.\n", target, index);
                } else {
                    printf("Phan tu %d khong co trong mang.\n", target);
                }
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}
