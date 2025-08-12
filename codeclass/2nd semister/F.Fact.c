#include <stdio.h>

unsigned long int fact(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d: %lu\n", n, fact(n));
    return 0;
}

unsigned long int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}