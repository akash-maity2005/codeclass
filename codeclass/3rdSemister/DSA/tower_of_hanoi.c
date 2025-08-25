#include <stdio.h>

void tower_of_hanoi(int n, int source, int inter, int dest) {
    if (n == 0) {
        return;  
    }
 tower_of_hanoi(n - 1, source, dest, inter);
    printf("Move disk %d from %d to %d\n", n, source, dest);
    tower_of_hanoi(n - 1, inter, source, dest);
}

int main() {
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d", &n);
     tower_of_hanoi(n, 1, 2, 3); 
    return 0;
}