#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        printf("Failed to create child process.\n");
        return 1;
    }

    if (child_pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", child_pid);
    }

    return 0;
}
