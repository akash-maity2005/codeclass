#include <stdio.h>
//Copy content of one file to another. source.txt must have some data in it.
int main() {    
    int c;
    FILE *src = fopen("source.txt", "rb");
    FILE *dest = fopen("dest.txt", "wb");
    
 
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }
    
    fclose(src);
    fclose(dest);
    
    return 0;
}