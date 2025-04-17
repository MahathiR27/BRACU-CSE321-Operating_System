#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // Create a new process

    if (pid == -1) {
        // If fork() returns -1, an error occurred
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This is executed by the child process
        printf("Child process: PID = %d\n", getpid());
        printf("Performing some task...\n");
        sleep(2); // Simulate a task
        printf("Child process is done.\n");
        exit(EXIT_SUCCESS); // Child process exits
    } else {
        // This is executed by the parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Waiting for child process to finish...\n");
        //wait(&status); // Wait for the child process to finish
        printf("Parent process is done.\n");
    }

    return EXIT_SUCCESS;
}
