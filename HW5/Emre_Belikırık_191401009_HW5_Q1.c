#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h> 
#define bufferLength 255
#define size 10000
 

void count_letters(char str[],int num_of_str) {
    int char_val = 'a',char_end = 'z',i,count;
    char letter;
    
    printf("letter  #occurrences\n");
    for(char_val; char_val<=char_end; char_val++) {
        count = 0;
        letter = char_val;
        for(i = 0; i < num_of_str*100; i++) {
            if(str[i] == letter) {
                count++;
            }
        }

        printf(" \'%c\'           %d\n",letter,count);
    }
}


int main(int argc, char const *argv[])
{   
    FILE* filePointer;
    char str[size];
    char buffer[bufferLength];
    char fname[10];
    char chr; 
    printf("Your file name for question A: ");
    gets (fname);
    printf("\n\n");
    filePointer = fopen(fname, "r");
    int num = 0;
    int i;
    while(fgets(buffer, bufferLength, filePointer)) {
        num++;
        i = 0;
        while (buffer[i]) { 
            chr = buffer[i]; 
            buffer[i] = tolower(chr); 
            i++; 
        }
        strcat(str, buffer);
    }

    fclose(filePointer);

    printf("Your input from file: \n%s\n\n",str);
    count_letters(str,num);

    FILE* filePointer2;
    char str2[size];
    char buffer2[bufferLength];
    char fname2[10];
    printf("\nYour file name for question B: ");
    gets (fname2);
    printf("\n");
    filePointer2 = fopen(fname2, "r");
    num = 0;
    int word_lengths[50];
    int index = 0;
    int len = 0, numberOfWord = 0,max_len = 0;

    while(fgets(buffer2, bufferLength, filePointer2)) {
        num++;
        i = 0;
        while (buffer2[i]) {
            chr = buffer2[i];
            if(chr == ' ' || chr == '\n' || chr == '\t') {
                word_lengths[index] = len;
                if(len > max_len) max_len = len;
                len = 0; index++;
                numberOfWord+=1;
            } else {
                len++;
            }
            buffer2[i] = tolower(chr); 
            i++; 
        }
        strcat(str2, buffer2);
    } 
    fclose(filePointer2);
    word_lengths[index] = len;


    printf("Your input from file: \n%s\n\n",str2);
    
    int *temp_ptr = word_lengths;

    int j,count;
    printf("Word Length     Occurences\n");

    for(j = 1; j <= max_len; j++) {
        temp_ptr = word_lengths;
        count = 0;
        for(int m = 0; m < numberOfWord+1; m++) {
            if (*(temp_ptr+m) == j) {
                count+=1;
            }
        }
        printf("%3d%20d\n",j,count);
    }

    FILE* filePointer3;
    
    char str3[size];
    char buffer3[bufferLength];
    char fname3[20];
    printf("\nYour file name for question C: ");
    gets (fname3);
    printf("\n");
    filePointer3 = fopen(fname3, "r");
    i = 0;
    while(fgets(buffer3, bufferLength, filePointer3)) {
        while (buffer3[i]) { 
            chr = buffer3[i]; 
            buffer3[i] = tolower(chr); 
            i++; 
        }
        strcat(str3, buffer3);
    }
    int n;
    printf("Word        #occurences\n");
    filePointer3 = fopen(fname3, "r");
    while( fscanf(filePointer3, "%s", buffer3) != EOF){
        printf("'%s'%16d\n",buffer3,check(str3,buffer3));
    }

    
    fclose(filePointer3); 

    return 0;
}

int check(char *s,char *w) {
    int n,a[1000],i,j,k=0,l,found=0,t=0;

    for(i=0;s[i];i++) 
        if(s[i]==' ')
            a[k++]=i;

	a[k++]=i;
	j=0;
	for(i=0;i<k;i++) {
		n=a[i]-j;
		if(n==strlen(w)) {
			t=0;
			for(l=0;w[l];l++) if(s[l+j]==w[l]) t++;

			if(t==strlen(w)) found++;	 
		}
		j=a[i]+1;
	}
    return found;
}

typedef struct counted_word {
    char str[20];
    int count;
    int index;
}word;
