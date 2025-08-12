#include <stdio.h>

int myStrlen(char str[]);
void myStrcat(char dest[], char src[]);

int main() {
    char str1[200], str2[100];  // Ensure str1 is large enough to hold the result

    printf("Enter first string: ");
    scanf(" %[^\n]", str1);  // Read string with spaces

    printf("Enter second string: ");
    scanf(" %[^\n]", str2);  // Read string with spaces

    printf("Length of str1: %d\n", myStrlen(str1));

    myStrcat(str1, str2);  // Concatenate str2 to str1

    printf("Concatenated string: %s\n", str1);

    return 0;
}

// Function to calculate the length of a string
int myStrlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to concatenate src string to dest string
void myStrcat(char dest[], char src[]) {
    int len = myStrlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';  // Add null terminator at the end
}