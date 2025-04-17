#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("PID of ex1.c = %d\n", getpid());
    char *args[] = {"Hello", NULL};
    execv("./ex2", args);//executable file not the c file. Pauses the process and brings the other process in this file to run.
    printf("Back to ex1.c");
    return 0;
}
