#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

unsigned int packCharacters(char chars[]);
void displayBits( unsigned int value );
void unpackCharacters(unsigned int x);

int main(int argc, char const *argv[]) {
    printf("Question-1\n");
    char characters[4];
    printf("input: ");
    scanf("%s", characters);
    printf("characters: %s\n",characters);
    for(size_t i = 0; i < 4; i++) {
        printf("%c : %u --> ",characters[i],(unsigned int)characters[i]);
        displayBits((unsigned int)characters[i]);
        printf("\n");
    }
    unsigned int char_bits = packCharacters(characters);
    printf("After packed: ");
    displayBits(char_bits);

    printf("\nQuestion-2\n");

    printf("\nOur unsigned int: %u\n",char_bits);

    printf("Our characters in Question-1: ");
    unpackCharacters(char_bits);
    return 0;
}

unsigned int packCharacters(char chars[]){
    unsigned int combine = 0;
    for(size_t i = 0; i < 4; i++) {
        unsigned int temp  = (unsigned int)chars[i];
        combine = temp | combine;
        if(i!=3) combine<<=8;
    }
    return combine;
}

void unpackCharacters(unsigned int x){
    unsigned int mask = 4278190080;
    
    unsigned int t;
        
    char temp[4];
    for(int i = 0; i < 4; i++) {
        t = x & mask;
        t>>=(3-i)*8;
        printf("%c", (char)t);
        mask>>=8;
    }
}


// display bits of an unsigned int value
void displayBits( unsigned int value )
{ 
   unsigned int c; // counter
   unsigned int displayMask = 1 << 31; 

   for ( c = 1; c <= 32; ++c ) { 
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1; 
      if ( c % 8 == 0 ) { 
         putchar( ' ' );
      } 
   }
   putchar( '\n' );
} 