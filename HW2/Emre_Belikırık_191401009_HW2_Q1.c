#include<stdio.h>
#include<math.h>
int main() {
    int is_prime;
    printf("Enter an integer: ");
    scanf("%d", &is_prime);
    while(is_prime <= 1) {
        printf("Please enter an integer between 1-100: ");
        scanf("%d", &is_prime);
    }
    if(is_prime == 2) {
        printf("Is a prime number");
        return 0;
    }
    if(is_prime%2 == 0) {
        printf("is not a prime number");
        return 0;
    }
    for(int i = 3; i < sqrt(is_prime); i=i+2) {
        if(is_prime%i == 0) {
            printf("is not a prime number");
            return 0;
        }
    }
    printf("Is a prime number");
    return 0;
}
