#include <stdio.h>

int main(){
float a, b, d;
int c;

a = 3.1416;
c = a;
a = 10;
b = 3;
d = double(a)/double(b);

printf("%d\n",c);
printf("%f\n",d);
return 0;
}
