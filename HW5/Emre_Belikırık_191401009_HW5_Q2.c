#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h> 

int main(int argc, char const *argv[])
{
    char date[10];
    printf("Date : ");
    gets (date);
    printf("\n");

    int m = 10*(date[0]-'0')+(date[1]-'0'); //month
    int y = 1000*(date[6]-'0')+100*(date[7]-'0')+10*(date[8]-'0')+(date[9]-'0');
    int d = 10*(date[3]-'0')+(date[4]-'0');
    if(m == 1) printf("January ");
    else if(m == 2) printf("February ");
    else if(m == 3) printf("March ");
    else if(m == 4) printf("April ");
    else if(m == 5) printf("May ");
    else if(m == 6) printf("June ");
    else if(m == 7) printf("July ");
    else if(m == 8) printf("August");
    else if(m == 9) printf("September ");
    else if(m == 10) printf("October ");
    else if(m == 11) printf("November ");
    else if(m == 12) printf("December ");

    printf("%d,%d",d,y);
    return 0;
}
