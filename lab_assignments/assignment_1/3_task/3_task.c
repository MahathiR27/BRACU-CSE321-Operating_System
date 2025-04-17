#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int status;
    file = fopen("process_count.txt", "w");
    fclose(file);

    pid_t a = fork();
    pid_t b = fork();
    pid_t c = fork();

    if (a == 0) {
        file = fopen("process_count.txt", "a");
        fprintf(file, "%d\n", 1);
        fclose(file);

        if (getpid() % 2 != 0) {
            pid_t d = fork();
            if (d == 0) {
                file = fopen("process_count.txt", "a");
                fprintf(file, "%d\n", 1);  
                fclose(file);
            }
        }
        return 0;
    
    }

    if (b == 0) {
        file = fopen("process_count.txt", "a");
        fprintf(file, "%d\n", 1);
        fclose(file);

        if (getpid() % 2 != 0) {
            pid_t e = fork();
            if (e == 0) {

                file = fopen("process_count.txt", "a");
                fprintf(file, "%d\n", 1);
                fclose(file);
            }
        }
        return 0;
    }

    if (c == 0) {
        file = fopen("process_count.txt", "a");
        fprintf(file, "%d\n", 1);
        fclose(file);

        if (getpid() % 2 != 0) {
            pid_t f = fork();
            if (f == 0) {

                file = fopen("process_count.txt", "a");
                fprintf(file, "%d\n", 1); 
                fclose(file);
            }
        }
        return 0; 
    }

    while (wait(&status) > 0);

    file = fopen("process_count.txt", "r");
    int total_count = 0;
    int count;
    while (fscanf(file, "%d", &count)!=EOF) {
        total_count+=count;
    }
    fclose(file);

  printf("Total processes created (including the parent): %d\n", (total_count+4));
  return 0;
}
