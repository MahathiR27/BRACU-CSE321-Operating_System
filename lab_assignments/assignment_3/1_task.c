#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared {
    char sel[100];
    int b;
};
void check_bal(struct shared *sm);
void add_money(struct shared *sm);
void withdraw(struct shared *sm);

int main(){
  key_t key = 987;
  int sm_id = shmget(key,sizeof(struct shared),0777 | IPC_CREAT);
  struct shared *sm = shmat(sm_id,NULL,0);

  sm->b = 1000;

  char input;
  printf("Provide Your Input From Given Options:\n1. Type a to Add Money\n2. Type w to Withdraw Money\n3. Type c to Check Balance\n");
  scanf("%c",&input);
  printf("Your Selection: %c\n", input);
  sm->sel[0] = input;
  sm->sel[1] = '\0';

  pid_t pid = fork();
  int status;
  int pipefd[2];
  pipe(pipefd);

  if(pid>0){
    close(pipefd[1]);
    wait(&status);
    char buffer[100];
    read(pipefd[0], buffer, 100);
    printf("dap");
    printf("%s\n",buffer);
  }
  else if(pid==0){
  char input = sm->sel[0];
  if(input=='a'){
    add_money(sm);
  }
  else if(input=='w'){
    withdraw(sm);
  }
  else if(input=='c'){
    check_bal(sm);
  }
  else{
    printf("Invalid selection");
  }
  close(pipefd[0]);
  char message[] = "Thank you for using";
  write(pipefd[1], message, strlen(message) + 1);
  exit(0);
  }

  return 0;
}

void check_bal(struct shared *sm){
  printf("Your current balance is:\n%d\n",sm->b);
}
void withdraw(struct shared *sm){
  int amount;
  printf("Enter amount to be withdrawn:\n");     
  scanf("%d", &amount);
  if(0<amount&&amount<=sm->b){
    sm->b -= amount;
    printf("Balance withdrawn successfully\nUpdated balance after withdrawal:\n%d\n", sm->b);
  }
  else{
    printf("Withdrawal failed, Invalid amount\n");
  }
}
void add_money(struct shared *sm){
  int amount;
  printf("Enter amount to be added:\n");     
  scanf("%d", &amount);
  if(amount>0){
    sm->b += amount;
    printf("Balance added successfully\nUpdated balance after addition:\n%d\n", sm->b);
  }
  else{
    printf("Adding failed, Invalid amount\n");
  }
}