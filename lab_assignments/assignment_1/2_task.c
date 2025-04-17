#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  pid_t pid;
  int status;

  pid = fork(); // Create a new process
  if (pid == -1) {
      // If fork() returns -1, an error occurred
      perror("fork failed");
      exit(EXIT_FAILURE);
  } else if (pid == 0) {
      pid = fork();
      if (pid == -1) {
        // If fork() returns -1, an error occurred
        perror("fork failed");
        exit(EXIT_FAILURE);
      }
      else if (pid == 0){
        printf("I am grandchild\n");
      }
      else{
        wait(&status);
        printf("I am child\n");
      }
  } else {
    wait(&status);
    printf("I am parent\n");
  }

  return EXIT_SUCCESS;
}