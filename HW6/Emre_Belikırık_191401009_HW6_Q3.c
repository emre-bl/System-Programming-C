#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    short A[512][512]; short B[512][512];
    srand(time(NULL));
    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            A[i][j] = (rand() % (127 - (-127))) + (-127);
            B[i][j] = (rand() % (127 - (-127))) + (-127);
        }
    }
     
    FILE *aptr = NULL, *bptr= NULL, *cptr = NULL;

    aptr = fopen("A.dat","w");

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            fprintf(aptr,"%5d ",A[i][j]);
            if(j ==511 && i!=511) fprintf(aptr,"%c",'\n');
        }
    }

    bptr = fopen("B.dat","w");

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            fprintf(bptr, "%5d", B[i][j]);
            if(j ==511 && i!=511) fprintf(bptr,"%c",'\n');
        }
    }

    fclose(aptr); fclose(bptr);

    short C[512][512];
    short (*aP)[512] = &A[0];
    short (*bP)[512] = &B[0];
    short (*cP)[512] = &C[0];

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            *(*(cP + i)+j) = *(*(aP + i)+j) * *(*(bP + i)+j);
        }
    }

    cptr = fopen("C.dat","w");

    for(size_t i = 0; i <512; i++) {
        for(size_t j = 0; j <512; j++) {
            fprintf(cptr, "%7d", C[i][j]);
            if(j ==511 && i!=511) fprintf(cptr,"%c",'\n');
        }
    }
    

    fclose(cptr); 

    return 0;
}
