#include <stdio.h>

int isKrishnamurthy(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isKrishnamurthy(n)) {
        printf("%d is a Krishnamurthy number.\n", n);
    } else {
        printf("%d is not a Krishnamurthy number.\n", n);
    }
    return 0;
}

int isKrishnamurthy(int n) {
    int original = n, sum = 0;
    while (n > 0) {
        int digit = n % 10;
        int fact = 1;
        for (int i = 1; i <= digit; i++) {
            fact *= i;
        }
        sum += fact;
        n /= 10;
    }
    return sum == original;
}