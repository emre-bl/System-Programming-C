#include<stdio.h>
int main() {
    int is_prime;
    printf("Please enter a number greater than 100000: ");
    scanf("%d", &is_prime);
    while(is_prime <= 100000) {
        printf("This number is less than 100000. Please re-enter: ");
        scanf("%d", &is_prime);
    }
    if(is_prime%2 == 0) {
        printf("Is not a prime number");
        return 0;
    }
    for(int i = 3; i < sqrt(is_prime); i=i+2) {
        if(is_prime%i == 0) {
            printf("Is not a prime number");
            return 0;
        }
    }
    printf("Is a prime number");
    return 0;
}
