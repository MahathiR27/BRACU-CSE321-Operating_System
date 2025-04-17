#include <stdio.h>
int main(){
int var = 10;
int *ip;
ip = &var;

printf("%p \n", &var);
printf("%p \n", ip);
printf("%d \n", *ip);

}
