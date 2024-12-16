#include <stdio.h>

void inputString(char *str) {
    printf("Nhap mot chuoi: ");
    getchar(); 
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && i < 99) {
        str[i++] = ch;
    }
    str[i] = '\0';
}

void displayString(const char *str) {
    if (str[0] == '\0') {
        printf("Chuoi rong.\n");
        return;
    }
    printf("Chuoi la: %s\n", str);
}

int countLetters(const char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            count++;
        }
        str++;
    }
    return count;
}

int countDigits(const char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int countSpecialCharacters(const char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9') || *str == ' ')) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100] = "";
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap mot chuoi\n");
        printf("2. Hien thi chuoi\n");
        printf("3. Dem va hien thi so luong chu cai\n");
        printf("4. Dem va hien thi so luong chu so\n");
        printf("5. Dem va hien thi so luong ky tu dac biet\n");
        printf("6. Thoat\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputString(str);
                break;
            case 2:
                displayString(str);
                break;
            case 3:
                printf("So luong chu cai: %d\n", countLetters(str));
                break;
            case 4:
                printf("So luong chu so: %d\n", countDigits(str));
                break;
            case 5:
                printf("So luong ky tu dac biet: %d\n", countSpecialCharacters(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!!\n");
        }
    } while (choice != 6);

    return 0;
}
