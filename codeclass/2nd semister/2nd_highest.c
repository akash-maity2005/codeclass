#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the element of the array: \n");
    for(int i =0; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    int first=arr[0],second=arr[0];
    for(int i=0 ; i<n ; i++){
        if(arr[i]>first){
            first=second;
            second=arr[i];
        }
        else if(arr[i]>second&&arr[i]!=first){
            second=arr[i];
        }
    }
    printf("Second Highest number is:%d \n", second);
    return 0;

}