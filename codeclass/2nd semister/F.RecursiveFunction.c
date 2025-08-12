#include <stdio.h>

int sumUpToN(int n);
void fibonacciRecursive(int n);
int gcd(int a, int b);

int main() {
    int n, a, b;
    printf("Enter n for sum: ");
    scanf("%d", &n);
    printf("Sum up to %d: %d\n", n, sumUpToN(n));
    printf("Enter n for Fibonacci: ");
    scanf("%d", &n);
    printf("Fibonacci series up to %d terms: ", n);
    fibonacciRecursive(n);
    printf("\nEnter two numbers for GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d: %d\n", a, b, gcd(a, b));
    return 0;
}

int sumUpToN(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumUpToN(n - 1);
}

void fibonacciRecursive(int n) {
    static int a = 0, b = 1, next;
    if (n > 0) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
        fibonacciRecursive(n - 1);
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}