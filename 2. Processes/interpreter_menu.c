#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FOREVER while (1)

// Helper function to handle fork and execl for interpreters
void run_interpreter(const char *path, const char *arg) {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("Fork failed");
        return;

    } else if (pid == 0) {
        // Child process: replace image with the interpreter using execl
        execl(path, arg, NULL);

        // If execl returns, it means an error occurred
        perror("execl failed");
        exit(1);

    } else {
        // Parent process: wait for the child process to terminate
        wait(NULL);
        printf("\n[Process returned to menu]\n");
    }
}

int main(void) {
    int choice;

    FOREVER {
        printf("\n=========================\n");
        printf("       MAIN MENU         \n");
        printf("=========================\n");
        printf("1. Run Python\n");
        printf("2. Run Node.js\n");
        printf("3. Run Ruby\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        int scan_result;
        if ((scan_result = scanf("%d", &choice)) != 1) {
            if (scan_result == EOF) {
                printf("Exiting program. Goodbye!\n");
                exit(0);
            }
            printf("Invalid input %d. Please enter a number.\n", scan_result);
            // Clear the input buffer to prevent infinite loops on bad input
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nLaunching Python...\n");
                run_interpreter("/home/codespace/.python/current/bin/python", "python");
                break;

            case 2:
                printf("\nLaunching Node.js...\n");
                run_interpreter("/home/codespace/nvm/current/bin/node", "node");
                break;

            case 3:
                printf("\nLaunching Ruby...\n");
                run_interpreter("/usr/local/rvm/rubies/ruby-3.4.1/bin/irb", "irb");
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
