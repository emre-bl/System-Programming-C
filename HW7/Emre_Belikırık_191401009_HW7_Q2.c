#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);
    int pid1 = fork();
    if (pid1 == 0) {
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        dup2(fd1[0], 0);
        execlp("grep", "grep", "coder", NULL);
    }
    else {
        int pid2 = fork();
        if (pid2 == 0) {
            close(fd1[0]);
            close(fd2[1]);
            dup2(fd1[1], 1);
            dup2(fd2[0], 0);
            execlp("cat", "cat", "a.txt", NULL);
        } else {
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[0]);
            dup2(fd2[1], 1);
            execlp("wc", "wc", "-l", NULL);
        }
    }
    return 0;
}