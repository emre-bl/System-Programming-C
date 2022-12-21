#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int i = 1;
    while (i < 32) {
        printf("%d) %s", i, strsignal(i));
        i++;
    }

    return 0;
}

