#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int args_count,char *args[]){
	char buffer[20];
	write(0, "Enter and integer:\n", 19);
	read(0, buffer, 2);
        pid_t pid;
        int status;
        int num = atoi(buffer);
        pid = fork();
        if (pid == 0){
            if (num % 2 == 0){
                printf("Child Process Claims %d is even.\n", num);
            }
            else{
                printf("Child Process Claims %d is not even.\n", num);
            }
            return 0;
        }
        else{
            wait(&status);
            if (num % 2 == 0){
                printf("Parent Process Claims %d is not odd.\n", num);
            }
            else{
                printf("Child Process Claims %d is odd.\n", num);
            }
}
    return 0;
}
