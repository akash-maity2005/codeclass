#include <stdio.h>

// Function signatures
int binarySearch(int arr[], int left, int right, int key);
void bubbleSort(int arr[], int n);

int main() {
    int n, key, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Binary search requires sorted array
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    result = binarySearch(arr, 0, n-1, key);
    
    if(result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == key) {
            return mid;
        }
        
        if(arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Bubble sort function used to sort array before binary search
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}