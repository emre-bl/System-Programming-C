#include <stdio.h>
#include <math.h>

int main() {
    int arr[1000] = {0};
    for(int i = 2; i < 1000; i++) arr[i]+=1;

    int rem;

    for(int i = 2; i < 1000; i++) {
        if(arr[i] == 1) {
            for(int j = i+1; j < 1000; j++) {
                rem = j%i;
                if(rem == 0) arr[j] = 0;
            }
        }
    }

    for(int i = 1; i < 1000; i++) {
        if(arr[i] == 1) {
            printf("%d ",i);
        }
    }
    
    return 0;

}