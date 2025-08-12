#include<stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int fibo[n];

    fibo[0]=0;
    if(n>1)fibo[1]=1;

    for(int i=2; i<n ;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];

    }
    printf("Fibonachi Sequense:");
    for(int i=0; i<n;i++){
        printf("%d",fibo[i]);
    }
    printf("\n");
    return 0;
}