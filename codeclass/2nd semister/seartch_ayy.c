#include<stdio.h>
int main(){
    int n,item,found=0;
    printf("Enter the Size of the Arrray : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the Element of the array : ");
    for(int i=0; i<n; i++){
        scanf("%d", arr[i]);
    }
    printf("Enter the element to find the ");
    scanf("%d",&item);

    for(int i=0; i<n;i++){
        if(arr[i]==item){
            printf("The Element found in the position : %d \n",i+1);
            found=1;
            break;

        }
    }
    if(!found){
        printf("Sorry!Item not found");
    }
    return 0;
}