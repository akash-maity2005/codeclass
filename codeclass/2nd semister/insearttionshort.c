#include<stdio.h>
void inseartionshort(int n , int arr[]){
    for(int i=0; i<n ; i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the element of the array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    inseartionshort(n,arr);
    
    printf("Shorted array is: \n");
    for(int i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;

}