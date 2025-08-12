#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of the array :");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter the number of the Elements : ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

    }
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max)max=arr[i];
        if(arr[i]<min)min=arr[i];

    }
    printf("Maximum: %d \n Minimum : %d \n",max,min);
    return 0;
}