#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int main() {
    int end = 1;
    srand ( time(NULL) );
    while(end == 1) {
        int random = 1 + rand() % 1000;

        printf("I have a number between 1 and 1000 \n");
        printf("Can you guess my number? \n");
        printf("Please type yout first guess.\n");
        printf("Your Guess: ");

        int your_guess = scanf("%d", &your_guess);

        while(your_guess != random || your_guess == 1001) {
            

            if(your_guess < random) {
                printf("Too low. Try again.\n");
                printf("Your Guess: ");
                scanf("%d", &your_guess);
            } else if(your_guess > random) {
                printf("Too high. Try again.\n");
                printf("Your Guess: ");
                scanf("%d", &your_guess);
            } 
        }

        char s[1];
        printf("Excellent! You guessed the number!\nWould you like to play again (y or n)?: ");
        scanf("%s",s);
        if(*s == 'y') end = 1;  
        else if(*s == 'n') return 1;

        printf("\n*******************Another Game*******************");
        printf("\n");
    }
}
