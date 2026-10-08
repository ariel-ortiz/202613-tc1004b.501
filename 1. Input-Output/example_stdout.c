#include <unistd.h>
#include <string.h>

int main()
{
    char buffer[] = "hola";
    write(STDOUT_FILENO, buffer, strlen(buffer));

    return 0;
}
