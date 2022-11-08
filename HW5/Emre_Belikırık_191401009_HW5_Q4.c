#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h> 

typedef struct hardware {
    int record;
    char toolname[20];
    int quantity;
    float cost;
} hw;

int main(int argc, char const *argv[])
{

    char buf[50];
    FILE * fp = NULL;
    
    fp = fopen("hardware.txt", "w+");

    if(fp == NULL) {
        printf("\nUnable to create file.\n");
        exit(EXIT_FAILURE);
    }

    hw hw1 = {3,"Electric sander",7,57.98};
    hw hw2 = {17,"Hammer",76,11.99};
    hw hw3 = {24,"Jig saw",21,11.00};
    hw hw4 = {39,"Lawn mower",3,79.50};
    hw hw5 = {56,"Power saw",18,99.99};
    hw hw6 = {68,"Screwdriver",106,6.99};
    hw hw7 = {77,"Sledge hammer",11,21.50};
    hw hw8 = {68,"Screwdriver",106,6.99};
    hw hw9 = {83,"Wrench",34,7.50};
    fpwrite(&hw1,&fp); fpwrite(&hw2,&fp);
    fpwrite(&hw3,&fp); fpwrite(&hw4,&fp);
    fpwrite(&hw5,&fp); fpwrite(&hw6,&fp);
    fpwrite(&hw7,&fp); fpwrite(&hw8,&fp);
    fpwrite(&hw9,&fp);

    char choice,ch;
    int exit = 0;

    while(exit != 1) {
        puts("---------SELECT YOUR CHOICE---------");
        puts("a. initializes the file \"hardware.dat\" to 100 empty record");
        puts("b. lets you input the data concerning each tool");
        puts("c. enables you to list all your tool");
        puts("d. lets you delete a record for a tool that you no longer have");
        puts("e. lets you update any information in the file");
        puts("t. for EXIT");
        scanf("%c",&choice);
        if(choice == 't') exit = 1;
        else if(choice == 'a') {
            size_t i = 0;
            for(i; i<100; i++) {
                hw temphw = {0,"\0",0,0};
                fpwrite(&temphw,&fp);
            }
        } else if(choice == 'c') {
            rewind(fp);
            char line[100];
            while (fgets(line, sizeof(line), fp)) {
                printf("%s", line); 
            }
        } else if(choice == 'd') {
            printf("Bu secenegi yapamadim.\n");
        } else if(choice == 'b') {
            printf("Bu secenegi yapamadim.\n");
        } else if(choice == 'e') {
            printf("Bu secenegi yapamadim.\n");
        }
    }

    fclose(fp);
    return 0;
}

void fpwrite(hw *obj, FILE** fp) {
    char str[10];
    fprintf(*fp, "%s ", itoa(obj->record, str, 10));
    fprintf(*fp, "%s ", obj->toolname); 
    fprintf(*fp, "%s ", itoa(obj->quantity, str, 10));
    gcvt(obj->cost, 5,str);
    fprintf(*fp, "%s ", str);
    fprintf(*fp, "%s", "\n"); 
}
