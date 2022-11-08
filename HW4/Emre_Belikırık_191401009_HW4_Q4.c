#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{   
    int arr1[50],arr2[50];
    int len1,len2;
    printf("1st array length: ");
    scanf("%d",&len1);
    printf("\n2nd array length: ");
    scanf("%d",&len2);
    int i,temp = 0;
    for(i = 0; i < len1; i++) {
        temp = rand() % (10000000 - temp) + temp;
        arr1[i] = temp;
    }
    temp = 0;
    printf("\n1st array: ");
    for(i = 0; i < len1; i++) {
        printf("%d ",*(arr1+i));
    }
    for(i = 0; i < len2; i++) {
        temp = rand() % (10000000 - temp) + temp;
        arr2[i] = temp;
    }

    printf("\n2nd array: ");
    for(i = 0; i < len2; i++) {
        printf("%d ",*(arr2+i));
    }

    int merged_arr[100];

    int min1=0,min2=0;
    
    for(i = 0; i< len1+len2; i++) {
        if(arr1[min1] <= arr2[min2] && min1 < len1) {
            merged_arr[i] =arr1[min1];
            min1+=1;
        } else if(arr1[min1] > arr2[min2] && min2 < len2) {
            merged_arr[i] =arr2[min2];
            min2+=1;
        } else {
            if(min1 == len1) {
                merged_arr[i] = arr2[min2];
                min2+=1;
            } else if(min2 == len2) {
                merged_arr[i] = arr1[min1];
                min1+=1;
            } 
        }
    }
    printf("\nMerged array: ");
    for(i = 0; i< len1+len2; i++) {
         printf("%d ",*(merged_arr+i));
    }

    return 0;
}
