#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int fd[2];
    char input[256];
    char output[256];
    pipe(fd);
    int pid = fork();
    if (pid == 0) {
        close(fd[1]);
        read(fd[0], input, 256);
        printf("Child process: PID: %d, PPID: %d, GID: %d \n", getpid(), getppid(), getgid());
        printf("Child process: %s \n", input);
        int i = 0;
        int j = strlen(input) - 1;
        while (i < j) {
            char temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
        printf("Child process: %s \n", input);
        close(fd[0]);
    } else {
        close(fd[0]);
        printf("Parent process: PID: %d, PPID: %d, GID: %d \n", getpid(), getppid(), getgid());
        printf("Parent process: Enter a string: ");
        scanf("%s", input);
        write(fd[1], input, 256);
        close(fd[1]);
    }
    return 0;
}





