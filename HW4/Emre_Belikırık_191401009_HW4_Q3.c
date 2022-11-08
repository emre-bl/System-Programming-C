#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int value;
    printf("Value of elements: ");
    scanf("%d",&value);

    int row = 0, column = 0;
    printf("\nEnter Matrix dimensions: \n");
    
    printf("row: ");
    scanf("%d",&row);
    fflush(stdin);
    printf("column: ");
    scanf("%d",&column);
    fflush(stdin);

    while(row > 10 || column > 10) {
        printf("Matrix dimensions must be smaller than 10! Re-enter.\n");
    
        printf("row: ");
        scanf("%d",&row);
        fflush(stdin);
        printf("column: ");
        scanf("%d",&column);
        fflush(stdin);
    }
    
    int A[10][10];
    int *ptr = &A[0][0];
    int len = row*column;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
        *(ptr + i * column + j) = (rand() % 1000) + 1;
        }
    }
    printf("\nRandomly Initialized Array:\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            printf("%d ", *(ptr + i * column + j));
        }
        printf("\n"); // new line
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
        *(ptr + i * column + j) = value;
        }
    }
    printf("\nFinal Array: \n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            printf("%d ", *(ptr + i * column + j));
        }
        printf("\n"); // new line
    }
    return 0;
}
