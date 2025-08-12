#include <stdio.h>

// Function signature
int linearSearch(int arr[], int n, int key);

int main() {
    int n, key, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key);
    
    if(result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}