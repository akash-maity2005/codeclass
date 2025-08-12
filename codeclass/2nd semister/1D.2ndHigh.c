#include<stdio.h>

void findSecondHighest(int arr[], int n);

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findSecondHighest(arr, n);
    return 0;
}

void findSecondHighest(int arr[], int n) {
    int first = arr[0], second = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    printf("Second highest: %d\n", second);
}