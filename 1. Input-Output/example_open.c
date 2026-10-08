#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    char mensaje[] = "Hola mundo!\nTan tan.\n";

    printf("fd = %d\n", fd);
    if (fd == -1) {
        perror("opening");
        exit(1);
    }
    int n = write(fd, mensaje, strlen(mensaje));
    printf("n = %d\n", n);
    close(fd);
    return 0;
}
