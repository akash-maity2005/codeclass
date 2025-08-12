#include<stdio.h>
#include<string.h>

int main(){
    char num[20];
    printf("Enter the number:");
    scanf("%s",&num);

    char *digits[]= {"Zero", "One", "Tow", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    for(int i=0; i<strlen(num);i++){
        if(num[i]>='0'&& num[i]<='9'){
            printf("%s",digits[num[i]-'0']);
        }
    }
    printf("\n");
    return 0;
}