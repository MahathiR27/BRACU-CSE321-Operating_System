#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int arr[5];


void *input(void *arg);
void *search(void *arg);
int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL, input, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2,NULL, search, NULL);
    pthread_join(t2, NULL);
    return 0;
}


void *input(void *arg){
  printf("Input: ");
  scanf("{%d, %d, %d, %d, %d}", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
}


void *search(void *arg){
  int val;
  printf("Find the value: ");
  scanf("%d",&val);
  for(int i = 0; i<5; i++){
    if (arr[i]== val){
      printf("Dap");
    }
  }
}
