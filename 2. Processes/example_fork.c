#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("PARENT> Process ID = %d\n", getpid());
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("CHILD> PID from fork = %d\n", pid);
        printf("CHILD> I'm the child, my PID = %d\n", getpid());
        execl("/usr/games/cowsay", "cowsay", "Hello, World!", NULL);
        // Shouldn't return if success
        perror("Exec failed");
        exit(1);
    } else {
        printf("PARENT> PID from fork = %d\n", pid);
        printf("PARENT> I'm the parent, my PID = %d\n", getpid());
        printf("PARENT> Waiting for the child to end...\n");
        pid_t end_pid = wait(NULL);
        printf("PARENT> Process PID %d just finished...\n", end_pid);
    }

    return 0;
}
