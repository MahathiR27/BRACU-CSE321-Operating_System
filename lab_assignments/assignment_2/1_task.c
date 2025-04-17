#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fibo(void *v);
void *search(void *arg);
void *t_ret;

int main(){
	pthread_t t1, t2;
	int n;
  printf("Enter the term of fibonacci sequence:\n");
  scanf("%d",&n);
	pthread_create(&t1,NULL,fibo,&n);
	pthread_join(t1,&t_ret);

	int *val = (int *)t_ret;

    for(int i=0;i<=n;i++){
        printf("a[%d]: %d\n",i,val[i]);
    }
	
  pthread_create(&t2,NULL,search,val);
	pthread_join(t2,NULL);

  free(t_ret);
	return 0;
}
void *fibo(void *arg){
    int *count = (int *)arg;
    int *a=malloc(sizeof(int)*(*count));
    a[0] = 0;
    a[1] = 1;

    for(int i=2;i<=*count;i++){
      a[i] = a[i-1]+a[i-2];
    }
    return a;
}

void *search(void *arg){
  int *arr = (int *)arg;
  int num, count;

  printf("How many numbers you are willing to search?:\n");
  scanf("%d",&count);

  for(int i=1;i<=count;i++){
    printf("Enter Search %d:\n", i);
    scanf("%d",&num);
    if(num>sizeof(arr)){
      printf("Result of search #%d = -1\n",i);
    }
    else{
      printf("Fesult of search #%d = %d\n",i,arr[num]);
    }

  }
}