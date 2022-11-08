
#include <stdio.h>
#include <math.h>

long long int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double e_x(int x) {
    double sum = 1.0;
    double pay = x;
    double payda = 1.0;
    for(int i = 1; i <= 15; i++) {
        sum+=((double)x/payda);
        pay*=x;
        payda*=i;
    }
    return sum;
}



 
int main()
{
    printf("Question 5-a:\n");
    int num;
    printf("Please enter a non-zero number: ");
    scanf("%d", &num);
    while(num <= 0) {
        printf("This number is less than zero. Please re-enter: ");
        scanf("%d", &num);
    }
    
    printf("Factorial of %lld is %lld\n", num, factorial(num));

    printf("\nQuestion 5-b:\n");
    long double temp = 1.0;
    float e = 1.0; 

    for(int i = 1;i<=50;i++)  {
        temp = temp*i;
        e+=(1.0/temp); 
    } 

    printf("Estimated value of e is %lf\n",(float)e); 

    printf("\nQuestion 5-c:\n");

    int k;
    printf("Input x for e^x calculation: ");
    scanf("%d",&k);
    printf("e^(%d) = %lf\n",k,e_x(k));

    printf("\nQuestion 5-d:\n");

    int ret = 0;
    while(factorial(ret) > 0) ret+=1;

    printf("maximum number is %d with factorial value %lld",ret-1,factorial(ret-1));
    
    return 0;

}


