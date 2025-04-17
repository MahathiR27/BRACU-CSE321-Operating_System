#include <unistd.h> // Library for system call
#include <fcntl.h> // Handling I/O
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
fork();
printf("Hello World\nPID=%d\n", getpid());
}
