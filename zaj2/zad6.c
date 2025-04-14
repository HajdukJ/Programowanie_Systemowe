#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uzycie: %s <PID> <SIGINT/SIGTERM>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    int sig = (strcmp(argv[2], "SIGINT") == 0) ? SIGINT : SIGTERM;
    
    kill(pid, sig);
    return 0;
}
