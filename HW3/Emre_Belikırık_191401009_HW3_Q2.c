#include <stdio.h>
#include <math.h>
void printFactors(int num) {
    int rem;
    for(int i = 1; i <= num/2; i++) {
        rem = num%i;
        if(rem == 0) printf("%d ",i);
    }
}
int isPerfect(int num) {
    int sum = 0;
    int rem;
    for(int i = 1; i <= num/2; i++) {
        rem = num%i;
        if(rem == 0) sum+=i;
    }
    if(sum == num) return 1;
    else return 0;
}
int main()
{   
    for(int i = 1; i <= 1000; i++) {
        if(isPerfect(i)) {
            printf("%d :",i);
            printFactors(i);
            printf("\n\n");
        }
    }
    return 0;
}
