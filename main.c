#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo);
static void write_file();

static void sighandler(int signo){
    if (signo == SIGINT){
        printf("hahaha! I cannot be stopped!\n");
        write_file();
        exit(0);
    }
    else if (signo == SIGUSR1){
        printf("parent pid: %d\n", getppid());
    }
}

static void write_file(){
    int goo = open("./output", O_WRONLY | O_CREAT, 0003);
    int ugh = write(goo, "The program exited because of SIGINT.\n", 39);
}

int main(){
    signal(SIGINT, sighandler);
    // printf("pid: %d\n", getpid());
    // printf("ppid: %d\n", getppid());

    while (1){
        sleep(1);
        printf("pid: %d\n", getpid());
    }
}