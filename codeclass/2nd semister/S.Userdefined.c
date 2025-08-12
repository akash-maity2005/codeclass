#include <stdio.h>

int myStrlen(char str[]);
void myStrcat(char dest[], char src[]);
void myStrrev(char str[]);
void myStrcpy(char dest[], char src[]);
int myStrcmp(char str1[], char str2[]);

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]", str2);
    printf("Length of str1: %d\n", myStrlen(str1));
    myStrcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    myStrrev(str1);
    printf("Reversed string: %s\n", str1);
    myStrcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    printf("Comparison result: %d\n", myStrcmp(str1, str2));
    return 0;
}

int myStrlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void myStrcat(char dest[], char src[]) {
    int len = myStrlen(dest);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + myStrlen(src)] = '\0';
}

void myStrrev(char str[]) {
    int len = myStrlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void myStrcpy(char dest[], char src[]) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int myStrcmp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}