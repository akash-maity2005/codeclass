#include <stdio.h>

void digitToWord(char num[]);

int main() {
    char num[100];
    printf("Enter a number: ");
    scanf("%s", num);
    digitToWord(num);
    return 0;
}

void digitToWord(char num[]) {
    char *words[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            printf("%s ", words[num[i] - '0']);
        }
    }
    printf("\n");
}