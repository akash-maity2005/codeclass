#include<stdio.h>
#include<string.h>
int main(){

    char str[100];
    int vowels=0,consonents=0,spaces=0,special=0;
    printf("Enter a sentence : ");
    scanf("%[^\n]", str);

    for(int i=0;str[i]!='0';i++){
        char ch=tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
            vowels++;
        }
        else if(ch >= 'a' && ch<= 'z'){
            consonents++;
        }
        else if(ch == ' '){
            spaces++;
        }
        else{
            special++;
        }
    }
    printf("Vowel: %d\n Consonent: %d\n Space: %d\n special: %d",vowels,consonents,spaces,special);
    return 0;
}