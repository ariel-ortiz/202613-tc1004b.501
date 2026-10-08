#include <unistd.h>

#define BUFFER_SIZE 4096

char translate(char c)
{
    if ('A' <= c && c <= 'Z') {
        return (((c - 'A') + 13) % 26) + 'A';
    }
    if ('a' <= c && c <= 'z') {
        return (((c - 'a') + 13) % 26) + 'a';
    }
    return c;
}

int main()
{
    char buffer[BUFFER_SIZE];
    ssize_t result;

    while((result = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < result; i++) {
            buffer[i] = translate(buffer[i]);
        }
        write(STDOUT_FILENO, buffer, result);
    }

    return 0;
}
