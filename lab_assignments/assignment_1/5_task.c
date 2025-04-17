#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  pid_t child, grandchild;
  int status;

  printf("1. Parent process ID : %d\n", getpid());

  child = fork();

  if (child < 0) {
      printf("Fork failed");
  } 
  else if (child == 0) {
      printf("2. Child process ID: %d\n", getpid());

      for (int i = 3; i < 6; i++) {
          grandchild = fork();

          if (grandchild < 0) {
            printf("Fork failed");
          } 
          else if (grandchild == 0) {
              printf("%d. Grand Child process ID: %d\n",i,getpid());
              return 0;
          }
          else{
            wait(&status);
          }
      }
  } else {
      wait(&status);
  }

  return 0;
}