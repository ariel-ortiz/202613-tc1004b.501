#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Helper function to handle fork and execl for interpreters
void run_interpreter(const char *path, const char *arg) {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Child process: replace image with the interpreter using execl
        execl(path, arg, NULL);

        // If execl returns, it means an error occurred
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process: wait for the child process to terminate
        int status;
        waitpid(pid, &status, 0);
        printf("\n[Process returned to menu]\n");
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\n=========================\n");
        printf("       MAIN MENU         \n");
        printf("=========================\n");
        printf("1. Run Python\n");
        printf("2. Run Node.js\n");
        printf("3. Run Ruby\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        int r;
        if ((r = scanf("%d", &choice)) != 1) {
            if (r == EOF) {
                printf("Exiting program. Goodbye!\n");
                exit(0);
            }
            printf("Invalid input %d. Please enter a number.\n", r);
            // Clear the input buffer to prevent infinite loops on bad input
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nLaunching Python...\n");
                run_interpreter("/usr/bin/python", "python");
                break;

            case 2:
                printf("\nLaunching Node.js...\n");
                run_interpreter("/usr/bin/node", "node");
                break;

            case 3:
                printf("\nLaunching Ruby...\n");
                run_interpreter("/usr/bin/irb", "irb");
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose 1, 2, or 3.\n");
        }
    }

    return 0;
}
