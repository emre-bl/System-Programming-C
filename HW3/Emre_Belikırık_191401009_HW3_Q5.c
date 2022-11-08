#include <stdio.h>
#include<stdlib.h>
#define ARRAY_LENGHT 20

int main(int argc, char const *argv[]) {
    int r1 = 0, c1 = 0,r2 = 0, c2 = 0;
    printf("Enter 1st Matrix dimensions: \n");
    
    printf("row: ");
    scanf("%d",&r1);
    fflush(stdin);
    printf("column: ");
    scanf("%d",&c1);
    fflush(stdin);

    printf("Enter 2nd Matrix dimensions: \n");
    
    printf("row: ");
    scanf("%d",&r2);
    fflush(stdin);
    printf("column: ");
    scanf("%d",&c2);
    fflush(stdin);
    while(c1 != r2) {
        printf("Matrix dimensions are not suitable for multiplication! Please Enter Again:\n");
        printf("1st Matrix: \n");
    
        printf("row: "); scanf("%d",&r1); fflush(stdin);
        printf("column: "); scanf("%d",&c1); fflush(stdin);

        printf("2nd Matrix boyutlarini giriniz: \n");
        
        printf("row: "); scanf("%d",&r2); fflush(stdin); 
        printf("column: "); scanf("%d",&c2); fflush(stdin);
    }


    int m1[ARRAY_LENGHT][ARRAY_LENGHT];
    int m2[ARRAY_LENGHT][ARRAY_LENGHT];
    int i,j,temp,i2,j2;

    printf("1st Matrix: \n");
    for(i = 0; i < r1; i++) {
        printf("Enter %d integers for the %d. row of the first matrix: ",c1,i+1);
        for(j = 0; j < c1;j++) {
            scanf("%d",&temp);
            m1[i][j]=  temp;
        }
        fflush(stdin);
    }
    

    printf("2nd Matrix: \n");
    for(i = 0; i < r2; i++) {
        printf("Enter %d integers for the %d. row of the first matrix: ",c2,i+1);
        for(j = 0; j < c2;j++) {
            scanf("%d",&temp);
            m2[i][j] = temp;
        }
        fflush(stdin);
    }
    

    int multiplied[ARRAY_LENGHT][ARRAY_LENGHT];

    for(i = 0; i < r1; i++) {
        for(j2 = 0; j2 < c2;j2++) {
            temp = 0;
            for(j = 0; j < c1; j++) {
                temp+=m1[i][j]*m2[j][j2];
            }
            multiplied[i][j2] = temp;
        }        
    }


    

    printf("\nMultiplied %dx%d:\n",r1,c2);
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2;j++) {
            printf("%d ",multiplied[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}