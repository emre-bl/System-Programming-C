#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int A[3][3]; int B[3][3];

    for(size_t i = 0; i <3; i++) {
        for(size_t j = 0; j <3; j++) {
            srand(time(NULL));
            A[i][j] = (rand() % (127 - (-127))) + (-127);
            B[i][j] = (rand() % (127 - (-127))) + (-127);
        }
    }

    for(size_t i = 0; i <3; i++) {
        for(size_t j = 0; j <3; j++) {
            printf("%d ",A[i][j]);
            if(j == 2) printf("\n");
        }
    }

    return 0;
}
