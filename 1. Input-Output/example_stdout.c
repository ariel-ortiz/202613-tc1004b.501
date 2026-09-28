#include <unistd.h>
#include <string.h>

int main()
{
    char buffer[] = "hola";
    write(1, buffer, strlen(buffer));

    return 0;
}
