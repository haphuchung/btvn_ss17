#include <stdio.h>

void reverseString(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int countWords(char *str) {
    int count = 0;
    int inWord = 0;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void toUpperCase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';
        }
        str++;
    }
}

void concatenateStrings(char *str1, char *str2) {
    while (*str1) {
        str1++;
    }
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap chuoi\n");
        printf("2. Dao nguoc chuoi\n");
        printf("3. Dem tu trong chuoi\n");
        printf("4. So sanh chuoi\n");
        printf("5. In hoa chuoi\n");
        printf("6. Them chuoi\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();  // Doc ky tu '\n' con lai sau scanf

        switch (choice) {
            case 1:
                printf("Nhap chuoi: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Xoa ky tu '\n' cuoi chuoi
                break;

            case 2:
                reverseString(str1);
                printf("Chuoi dao nguoc: %s\n", str1);
                reverseString(str1); // Dao lai chuoi ve ban dau
                break;

            case 3:
                printf("So tu trong chuoi: %d\n", countWords(str1));
                break;

            case 4:
                printf("Nhap chuoi so sanh: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Xoa ky tu '\n' cuoi chuoi
                if (strlen(str2) < strlen(str1))
                    printf("Chuoi 2 ngan hon chuoi 1.\n");
                else if (strlen(str2) > strlen(str1))
                    printf("Chuoi 2 dai hon chuoi 1.\n");
                else
                    printf("Hai chuoi co do dai bang nhau.\n");
                break;

            case 5:
                toUpperCase(str1);
                printf("Chuoi in hoa: %s\n", str1);
                break;

            case 6:
                printf("Nhap chuoi de them: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Xoa ky tu '\n' cuoi chuoi
                concatenateStrings(str1, str2);
                printf("Chuoi sau khi them: %s\n", str1);
                break;

            case 7:
                printf("Thoat.\n");
                return 0;

            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
