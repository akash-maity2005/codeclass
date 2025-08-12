#include <stdio.h>

void searchItem(int arr[], int n);

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    searchItem(arr, n);
    return 0;
}

void searchItem(int arr[], int n) {
    int item, found = 0;
    printf("Enter the item to search: ");
    scanf("%d", &item);
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            printf("Item found at position: %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, item not found.\n");
    }
}