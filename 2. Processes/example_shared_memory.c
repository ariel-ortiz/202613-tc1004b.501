#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

typedef struct _info_t {
    int an_int;
    float a_float;
    char a_char;
} info_t;

int main()
{
    info_t* my_info_ptr = mmap(NULL, sizeof(info_t),
                               PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS,
                              -1, 0);
    my_info_ptr->an_int = 42;
    my_info_ptr->a_float = 3.1415;
    my_info_ptr->a_char = '*';

    if (my_info_ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    printf("[PARENT] Values: %d %f %c\n",
                my_info_ptr->an_int,
                my_info_ptr->a_float,
                my_info_ptr->a_char);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        munmap(my_info_ptr, sizeof(info_t));
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("[CHILD] Original values: %d %f %c\n",
                my_info_ptr->an_int,
                my_info_ptr->a_float,
                my_info_ptr->a_char);
        my_info_ptr->an_int++;
        my_info_ptr->a_float = (int) my_info_ptr->a_float;
        my_info_ptr->a_char = '@';
        munmap(my_info_ptr, sizeof(info_t));
        exit(0);
    }

    // Parent process
    wait(NULL);
    printf("[PARENT] New values: %d %f %c\n",
                my_info_ptr->an_int,
                my_info_ptr->a_float,
                my_info_ptr->a_char);
    munmap(my_info_ptr, sizeof(info_t));

    return 0;
}
