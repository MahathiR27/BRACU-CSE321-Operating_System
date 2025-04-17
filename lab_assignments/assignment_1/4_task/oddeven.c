#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int args_count,char *args[]){
  int n = args_count-1;
  int arr[n];
  if(args_count<2){
    printf("Enter Numbers");
  }
  else{
    for(int i = 0; i<n; i++){
      arr[i] = atoi((args[i+1])); 
    }
    printf("Odd/Even:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d is Even\n", arr[i]);
        } else {
            printf("%d is Odd\n", arr[i]);
        }
    }
  }
  return 0;
}