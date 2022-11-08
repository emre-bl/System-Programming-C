#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE * fPtr = NULL;
    char fname[20];
    printf("Your file name for writing on it: ");
    gets (fname);
    fPtr = fopen(fname, "w");
    if(fPtr == NULL) {
        printf("\nUnable to create file.\n");
        exit(EXIT_FAILURE);
    }

    int i;
    int num;

    printf("\nEnter telephone number: ");
    scanf("%d",&num);
    int temp = num;
    int boolean = 1;
    int digit;
    for(i = 0; i < 7; i++) {
        digit = temp%10;
        if(digit == 1 || digit == 0) {
            printf("\nPhone number cannot contains 0-1 digits. \nPlease re-enter phone number.");
            printf("\nEnter telephone number: ");
            scanf("%d",&num);
            temp = num;
            i = 0;
            continue;
        }
        temp/=10;
    }

    printf("\ngiven telephone number: %d",num);
    int count = 0;
    int n[7];
    for(i = 6; i >= 0; i--) {
        n[i] = num%10;
        num/=10;
    }

    
    int i1,i2,i3,i4,i5,i6,i7;
    int index;
    char word[7],c;
       for(i1 = 0; i1 < 3; i1++) {     
            c = generate_variation(n[0],i1);
            word[0] = c; 
            for(i2 = 0; i2 < 3; i2++) {
                c = generate_variation(n[1],i2);
                word[1] = c; 
                for(i3 = 0; i3 < 3; i3++) {
                    c = generate_variation(n[2],i3);
                    word[2] = c; 
                    for(i4 = 0; i4 < 3; i4++) {
                        c = generate_variation(n[3],i4);
                        word[3] = c; 
                        for(i5 = 0; i5 < 3; i5++) {
                            c = generate_variation(n[4],i5);
                            word[4] = c; 
                            for(i6 = 0; i6 < 3; i6++) { 
                                c = generate_variation(n[5],i6);
                                word[5] = c; 
                                for(i7 = 0; i7 < 3; i7++) {
                                    c = generate_variation(n[6],i7);
                                    word[6] = c; 
                                    fputc(word[0],fPtr); fputc(word[1],fPtr);fputc(word[2],fPtr);
                                    fputc(word[3],fPtr); fputc(word[4],fPtr);fputc(word[5],fPtr);
                                    fputc(word[6],fPtr);
                                    fputs("\n",fPtr);
                                }
                            }
                        }
                    }
                }
            }
        }

    fclose(fPtr);
    return 0; 
}

int generate_variation(int digit, int i) {
    if(digit == 2){
            char letters[3] = {'A','B','C'}; return (int)letters[i];
        } else if(digit == 3){
            char letters[3] = {'D','E','F'}; return (int)letters[i];
        } else if(digit == 4){
            char letters[3] = {'G','H','I'}; return (int)letters[i];
        } else if(digit == 5){
            char letters[3] = {'J','K','L'}; return (int)letters[i];
        } else if(digit == 6){
            char letters[3] = {'M','N','O'}; return (int)letters[i];
        } else if(digit == 7){
            char letters[3] = {'P','R','S'}; return (int)letters[i];
        } else if(digit == 8){
            char letters[3] = {'T','U','V'}; return (int)letters[i];
        }  else if(digit == 9){
            char letters[3] = {'W','X','Y'}; return (int)letters[i];     
        }
}
