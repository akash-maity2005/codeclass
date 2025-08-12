#include <stdio.h>

void countCharacters(char str[]);

int main() {
    char str[100];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);
    countCharacters(str);
    return 0;
}

void countCharacters(char str[]) {
    int vowels = 0, consonants = 0, spaces = 0, special = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            char c = tolower(str[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (str[i] == ' ') {
            spaces++;
        } else {
            special++;
        }
    }
    printf("Vowels: %d\nConsonants: %d\nSpaces: %d\nSpecial characters: %d\n", vowels, consonants, spaces, special);
}