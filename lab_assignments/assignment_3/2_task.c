#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h> 
#include <sys/shm.h>

struct msg {
    long int type;
    char txt[100];
};

key_t key = 897;

void otp_generator(int msg_id);
void mail(int msg_id, char *buff);

int main() {
    printf("Please enter the workspace name:\n");
    char input[100];
    scanf("%s", input);

    if (strcmp(input, "cse321") != 0) {
        printf("Invalid workspace name\n");
        return 1;
    }

    int msg_id = msgget(key, 0666 | IPC_CREAT);
    
    struct msg s_data;
    s_data.type = 7;
    strcpy(s_data.txt, input);
    msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt), 0);
    printf("Workspace name sent to OTP generator from log in: %s\n", s_data.txt);

    pid_t otp = fork();
    int status;
    if (otp == 0) {
        otp_generator(msg_id);
        exit(0);
    } 
    else {
        wait(&status);
        msgrcv(msg_id, &s_data, sizeof(s_data), 8, 0); 
        printf("Log in received OTP from OTP generator: %s\n", s_data.txt);

        char r_otp[50];
        strcpy(r_otp, s_data.txt);

        msgrcv(msg_id, &s_data, sizeof(s_data), 9, 0);
        printf("Log in received OTP from mail: %s\n", s_data.txt);

        char r_mail[50];
        strcpy(r_mail, s_data.txt);

        if (strcmp(r_otp, r_mail) == 0) {
            printf("OTP Verified\n");
        } 
        else {
            printf("OTP Incorrect\n");
        }
        shmctl(msg_id, IPC_RMID, NULL);
    }

    return 0;
}

void otp_generator(int msg_id) {
    struct msg r_data;
    msgrcv(msg_id, (void *)&r_data, sizeof(r_data.txt), 7, 0);
    printf("OTP generator received workspace name from log in: %s\n", r_data.txt);

    char buff[50];
    sprintf(buff, "%d", getpid());

    struct msg s_data;
    s_data.type = 8; 
    strcpy(s_data.txt, buff);

    msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt), 0);
    printf("OTP sent to log in from OTP generator: %s\n", s_data.txt);

    s_data.type = 5;
    msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt), 0);
    printf("OTP sent to mail from OTP generator: %s\n", s_data.txt);

    pid_t otp;
    int status1;
    otp = fork();

    if (otp == 0) {
        mail(msg_id, buff);
        exit(0);
    } 
    else if (otp > 0) {
        wait(&status1);
    }
}

void mail(int msg_id, char *buff) {
    struct msg mail_data;

    msgrcv(msg_id, (void *)&mail_data, sizeof(mail_data.txt), 5, 0);
    printf("Mail received OTP from OTP generator: %s\n", mail_data.txt);

    struct msg s_data;
    s_data.type = 9;
    strcpy(s_data.txt, buff);

    msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt), 0);
    printf("OTP sent to log in from mail: %s\n", s_data.txt);
}