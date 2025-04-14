#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void sigint_handler(int sig) {
    printf("Przechwycono SIGINT\n");
}
void sigterm_handler(int sig) {
    printf("Przechwycono SIGTERM\n");
}
int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);
    while (1) {
        pause();
    }
    return 0;
}
