#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int args_count,char *args[]){
  if(args_count<2){
    printf("Enter Numbers");
  }
  else{
    pid_t pid = fork();
    int status;
    if (pid < 0){
      printf("Fork Failed");
    }
    else if (pid > 0){
      wait(&status);
      FILE *in_f = fopen("array.txt", "r");
      execv("./oddeven", args);
    }
    else{
      execv("./sort", args);
    }
  }
}