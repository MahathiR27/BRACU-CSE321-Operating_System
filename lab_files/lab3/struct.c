#include <stdio.h>
#include <string.h>
struct Player{
 char name[20];
 int score;
};

int main(){
 struct Player p1 = {"Unga", 10}; // Has to be in proper order to pass the variables
 struct Player p2;
 strcpy(p2.name, "Bunga");
 p2.score = 5;

 printf("%s's Score: %d\n", p1.name, p1.score);
 printf("%s's Score: %d\n", p2.name, p2.score);

return 0;
}
