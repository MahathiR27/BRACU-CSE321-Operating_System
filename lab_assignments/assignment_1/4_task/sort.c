#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int args_count,char *args[]){
  int n = args_count - 1;
  int arr[n];
  if(args_count<2){
    printf("Enter Numbers");
  }
  else{

    for(int i = 0; i<n; i++){
      arr[i] = atoi((args[i+1]));
    }

    for (int i = 0; i < n - 1; i++) {
      int max_idx = i;
      for (int j = i + 1; j < n; j++) {
          if (arr[j] > arr[max_idx]) {
              max_idx = j;
          }
      }

      int temp = arr[max_idx];
      arr[max_idx] = arr[i];
      arr[i] = temp;
  }
  printf("Sorted array in Desending order: ");
  for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
  }
  }
   printf("\n");

  return 0;
}