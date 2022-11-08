#include <stdio.h>  
#include <conio.h>  

void main() {
    int st = 1;

    for (int i = 1; i <= 10; i++)  
    {  
        for (int j = 1; j <= i; j++)  
        {  
            printf("%d ", st++);
        }  
        printf( "\n");  
    }
}