#include <stdio.h>
#include<stdlib.h>
#define ARRAY_LENGHT 20

int main(int argc, char const *argv[]) {
    printf("Matrix boyutlarini giriniz: \n");
    int r = 0, c = 0;
    printf("row: ");
    scanf("%d",&r);
    printf("column: ");
    scanf("%d",&c);
    int m1[ARRAY_LENGHT][ARRAY_LENGHT];
    int m2[ARRAY_LENGHT][ARRAY_LENGHT];
    int i,j,temp;

    printf("---------Matrix 1:--------- \n");
    for(i = 0; i < r; i++) {
        printf("Matrix1'in %d. row'u icin %d integer giriniz: ",i+1,c);
        for(j = 0; j < c;j++) {
            scanf("%d",&temp);
            m1[i][j]=  temp;
        }
        fflush(stdin);

    }
    

    printf("---------Matrix 2:--------- \n");
    for(i = 0; i < r; i++) {
        printf("Matrix2'nin %d. row'u icin %d integer giriniz: ",i+1,c);
        for(j = 0; j < c;j++) {
            scanf("%d",&temp);
            m2[i][j] = temp;
        }
        fflush(stdin);
    }

    int new_matrix[ARRAY_LENGHT][ARRAY_LENGHT];

    for(i = 0; i < r; i++) {
        for(j = 0; j < c;j++) {
            temp = m2[i][j]*m1[i][j];
            new_matrix[i][j] = temp;
        }
    }

    printf("\nElement-wise product:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c;j++) {
            printf("%d ",new_matrix[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}