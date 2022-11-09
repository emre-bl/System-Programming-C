#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int A[512][512]; int B[512][512];
    srand(time(NULL));
    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            A[i][j] = (rand() % (127 - (-127))) + (-127);
            B[i][j] = (rand() % (127 - (-127))) + (-127);
        }
    }
    printf("A:\n");
    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            printf("%4d ",A[i][j]);
            if(j == 511) printf("\n");
        }
    }
    printf("\nB:\n");
    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            printf("%4d ",B[i][j]);
            if(j == 511) printf("\n");
        }
    }
    FILE *aptr = NULL, *bptr= NULL, *cptr = NULL;

    aptr = fopen("A.txt","w");

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            fprintf(aptr,"%5d ",A[i][j]);
            if(j == 511 && i!= 511) fprintf(aptr,"%c",'\n');
        }
    }

    bptr = fopen("B.txt","w");

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            fprintf(bptr, "%5d", B[i][j]);
            if(j == 511 && i!= 511) fprintf(bptr,"%c",'\n');
        }
    }

    fclose(aptr); fclose(bptr);

    /*int C[512][512];
    int* aP = NULL;
    int* bP = NULL;
    int* cP = NULL;

    aP = &A;
    bP = &B;
    cP = &C;

    for(size_t m = 0; m < 512*512; m++) {
        printf("%d\n",*(aP+m));
        //*(C+m) = (*(aP+m)) * (*(bP+m));
    } */


    /*aptr = fopen("A.txt","r");
    bptr = fopen("B.txt","r");

    

    char astr[5]; char bstr[5];
    for(size_t i = 0; i <3; i++) {
        for(size_t j = 0; j <3; j++) {
            if (fscanf(aptr, "%s", astr)!=EOF && fscanf(bptr, "%s", bstr)!=EOF) {
                C[i][j] = atoi(astr)*atoi(bstr);
            }
        }
    } */


    /*

    printf("\nC:\n");
    for(size_t i = 0; i <3; i++) {
        for(size_t j = 0; j <3; j++) {
            printf("%6d ",C[i][j]);
            if(j == 511) printf("\n");
        }
    }


    cptr = fopen("C.txt","w");

    for(size_t i = 0; i <3; i++) {
        for(size_t j = 0; j <3; j++) {
            fprintf(cptr, "%6d", C[i][j]);
            if(j == 2 && i!= 2) fprintf(cptr,"%c",'\n');
        }
    }
    

    fclose(cptr); */

    return 0;
}
