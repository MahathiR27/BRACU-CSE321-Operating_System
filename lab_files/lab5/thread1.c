#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *funcThread(void *arg);
int main(){
    pthread_t t1;
    pthread_create(&t1,NULL, funcThread, NULL);
    printf("Dap 1\n");
    pthread_join(t1, NULL);
    printf("Dap 2\n");
    return 0;
}

void *funcThread(void *arg){
    printf("Entering thread1:.. \n");
    for (int i=0; i<5; i++  ){
        printf("Thread 1: %d\n",i);
        sleep(1);
    }
    printf("Done with thread1 \n");
}