#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child\n");
    } else {
        wait(NULL);
        printf("Parent | childTerminated\n");
    }
    return 0;
}