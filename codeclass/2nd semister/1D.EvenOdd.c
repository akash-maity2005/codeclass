#include <stdio.h>

void separateEvenOdd(int arr[], int n);

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    separateEvenOdd(arr, n);
    return 0;
}

void separateEvenOdd(int arr[], int n) {
    int even[n], odd[n], e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[e++] = arr[i];
        } else {
            odd[o++] = arr[i];
        }
    }
    printf("Even numbers: ");
    for (int i = 0; i < e; i++) {
        printf("%d ", even[i]);
    }
    printf("\nOdd numbers: ");
    for (int i = 0; i < o; i++) {
        printf("%d ", odd[i]);
    }
    printf("\nCount of even numbers: %d\n", e);
    printf("Count of odd numbers: %d\n", o);
}