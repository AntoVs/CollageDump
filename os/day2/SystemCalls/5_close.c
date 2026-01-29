#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("hello.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        printf("File open error\n");
        return 1;
    }
    printf("File opened successfully\n");
    close(fd);
    return 0;
}