#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int size;

    printf("Array size: ");
    scanf("%d",&size);

    int arr1[20], arr2[20];
   
    for(int i = 0; i < size; i++) {
        arr1[i] = (rand() % 50) + 1;
        arr2[i] = (rand() % 50) + 1;
    }

    printf("\nOriginal Arrays \nArray 1: ");
    for(int i = 0; i < size-1; i++) {
        printf("%d - ",arr1[i]);
    } printf("%d",arr1[size]);
    printf("\nArray 2: ");
    for(int i = 0; i < size-1; i++) {
        printf("%d - ",arr2[i]);
    } printf("%d",arr2[size]);


    int temp;
    for(int i = 0; i < size; i++) {
        temp = *(arr1+i);
        *(arr1+i) = *(arr2+i);
        *(arr2+i) = temp;
    }
    

    printf("\n\nAfter Swap \nArray 1: ");

    for(int i = 0; i < size-1; i++) {
        printf("%d - ",arr1[i]);
    } printf("%d",arr1[size]);
    printf("\nArray 2: ");
    for(int i = 0; i < size-1; i++) {
        printf("%d - ",arr2[i]);
    } printf("%d",arr2[size]);
    return 0;
}
