#include <stdio.h>

int countWords(char str[]);

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Number of words: %d\n", countWords(str));
    return 0;
}

int countWords(char str[]) {
    int words = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') {
            words++;
        }
    }
    return words + 1;
}
