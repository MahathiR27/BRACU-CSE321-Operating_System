#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func_thread(void *arg);
void *t_ret;

int main(){
	pthread_t t1;
	int n=5;
	pthread_create(&t1,NULL,func_thread,&n);
	pthread_join(t1,&t_ret);
	printf("Thread returned: %d\n",*(int *)t_ret);
	
	return 0;
}
void *func_thread(void *arg){
    int *v = (int *)arg;
    int *result = malloc(sizeof(int));
    *result=(*v)*5;
	pthread_exit((void *)result);
}