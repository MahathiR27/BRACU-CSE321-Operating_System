#include <stdio.h>

int main(){
int arr[5] = {5,4,3,2,1};
int *ip;
ip = &arr[0];
printf("%p \n", ip);
printf("%p \n", ip+1);
printf("%p \n", ip-1);

return 0;
}
