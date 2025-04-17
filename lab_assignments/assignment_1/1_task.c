#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int args_count, char *args[]){
  if (args_count == 1){
    printf("Error, File Name Missing | execute the file again with *ONE* file name.");
  }
  else if (args_count > 2 ){
    printf("Error, Multiple File Names Added | execute the file again with *ONE* file name.");
  }
  else{
    char *filename = strcat(args[1],".txt");
    int out_f = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666), n;
    char buffer[50];
    write(0, "INPUT: ",8);
    n = read(0, buffer, 50);
    while ((buffer[0] != '-')||(buffer[1] != '1')){
      write(out_f, buffer, n);
      write(0, "INPUT: ",8);
      n = read(0, buffer, 50);
    }
  }
  return 0;
}
