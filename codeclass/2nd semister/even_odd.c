#include<stdio.h>
int main(){
    int n, evencount=0, oddcount=0;
    printf("Enter the size of array: ");
    scanf("%d",n);
    int arr[n], even[n], odd[n];

    printf("Enter the alement of the array: ");
    for(int i=0 ; i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]%2 ==0 ){
            even[evencount++]=arr[i];
        }
        else{
            odd[oddcount++]=arr[i];
        }
    }

    printf("Even number: %d",evencount);
    for(int i=0; i<evencount ;i++){
        printf("%d",even[i]);
    }
     printf("Odd number: %d",oddcount);
    for(int i=0; i<oddcount ;i++){
        printf("%d",odd[i]);
    }
    printf("\n");
    return 0;
}    