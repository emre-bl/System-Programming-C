#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>


int main(int argc, char const *argv[])
{
    int num;
    printf("Integer: ");
    scanf("%d",&num);

    int temp = 0;
    while(num%2 == 0) {
        temp+=1;
        num/=2;
    }
    if(temp != 0 && num == 1) printf("%d^(%d)",2,temp);
    else if(temp != 0) printf("%d^(%d) * ",2,temp);
    
    for(int i = 3; i <= num; i+=2){
        temp = 0;
        while(num%i == 0) {
            temp+=1;
            num/=i;
        }
        if(temp != 0 && num == 1) printf("%d^(%d)",i,temp);
        else if(temp != 0) printf("%d^(%d) * ",i,temp);
    }
    return 0;
}
