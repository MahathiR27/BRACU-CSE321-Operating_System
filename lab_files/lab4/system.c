#include <unistd.h> // Library for system call
#include <fcntl.h> // Handling I/O
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
char buffer[50];
int n, fd, fd1;
/*
read(0, buffer, 10); //Reads 10 charecters from terminal and stores in buffer

read(0, buffer, 10); //Replaces the chaedters in buffer from the start
write(1, buffer, 10); //0,1 is from file descriptor stdin, stdout


n = read(0, buffer, 10);
write(1, buffer,n); //Just prints the latest updated part of buffer. Doesnt include the previous buffer
*/

/*
fd = open("input.txt", O_RDONLY);
read(fd,buffer,10);
write(1, buffer, 10);

fd1 = open("output.txt", O_CREAT | O_WRONLY, 0644); //Creates the file and pipes it to the fuction, 644 chmod permission
write(fd1, buffer, 10);
*/

n = read(0, buffer, 50);
fd = open("output.txt", O_WRONLY | O_APPEND); // We need to write only and pipe it to append
write(fd, buffer, n);
write(1, buffer, 10 );
return 0;
}

