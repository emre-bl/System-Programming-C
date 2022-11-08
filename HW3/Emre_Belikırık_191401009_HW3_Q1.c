#include <stdio.h>

int main()
{
    float A,B,C;
    printf("A :");
    scanf("%f",&A);
    printf("B :");
    scanf("%f",&B); 
    printf("C :");
    scanf("%f",&C);
    
    float D = (A*B)*C;
    float E = A*(C*B);
    if(E==D) {
        printf("D is equal to E.");
    } else{
        printf("D is NOT equal to E.");
    } 
    return 0;
}
