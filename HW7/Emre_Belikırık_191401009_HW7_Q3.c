#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void signalHandler(int signum) {
    printf("%s\n", strsignal(signum));
    sleep(5);
}

int main(int argc, char const *argv[]) {
    signal(SIGINT, signalHandler);
    signal(SIGTSTP, signalHandler);
    signal(SIGQUIT, signalHandler);
    while (1) {
        printf("enter CTRL+C - CTRL+Z - CTRL+\\.\n");
        sleep(1);
    }
    return 0;
} 


