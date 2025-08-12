#include <stdio.h>

void fibonacci(int n);

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}

void fibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("Fibonacci sequence up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}