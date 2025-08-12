#include <stdio.h>

void alterCase(char text[]);

int main() {
    char text[100];
    printf("Enter a text: ");
    scanf(" %[^\n]", text);
    alterCase(text);
    printf("Altered text: %s\n", text);
    return 0;
}

void alterCase(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] += 32;
        }
    }
}