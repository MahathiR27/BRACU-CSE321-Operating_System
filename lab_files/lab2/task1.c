#include <stdio.h>

int main(){
printf("Hello World!\nWelcome to CSE21 lab\n");

int a,b,c;
float d;
a = 5;b = 10;
c = a+b;
d = 10.0/3.0; //The nums has to be float to get proper result
printf("The sum of a & b is: %d\n", c);
printf("The div of a & b is: %.3f\n", d);
return 0;
}
