#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp(args[0], args);
    printf("Execution Failed\n");
    return 0;
}