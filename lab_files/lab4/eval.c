#include <stdio.h>

int main(){
int arr[5]={40,70,30,20,10};
int min = arr[0];
int i, sum;
float avg;
sum =0;
for (i=0; i<5; i++){
	if (arr[i] < min){
	min = arr[i];}
sum = sum+arr[i];}

avg = sum/5;
printf("%d\n",min);
printf("%f\n",avg);
return 0;
}
