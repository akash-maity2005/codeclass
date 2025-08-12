#include<stdio.h>
int main(){
    int r1,r2,c1,c2;

    printf("Enter the row and the column of the matrix A : ");
    scanf("%d %d",&r1,&c1);

    printf("Enter the row and the column of the matrix B: ");
    scanf("%d %d",&r2,&c2);

    if(c1!=r2){
        printf("Multiplication is not possible for this.");
        return 0;
    }

    int a[r1][c1],b[r2][c2], product[r1][c2];

    printf("Enter matrix A: \n");
    for(int i=0; i<r1;i++){
        for(int j=0; j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter matrix B: \n");
    for(int i=0; i<r2;i++){
        for(int j=0; j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;i++){
            product[i][j]=0;
            for(int k=0;k<c1;k++){
                product[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("Result of the matrix multiplication is ; ");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}