#include <stdio.h>
#include <stdlib.h>
/*Count number of characters in a file. Create a file myfile.txt and put a paragraph in it.*/
int main() {
    FILE *file = fopen("myfile.txt", "rb");  // Open in binary mode
    if (file == NULL) {
        perror("Error opening myfile.txt");
        return EXIT_FAILURE;
    }

    long count = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    printf("Number of ASCII characters: %ld\n", count);
    return EXIT_SUCCESS;
}