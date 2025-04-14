#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
static void procedura_SIGINT(int sig_number) {
    printf("Przechwycono SIGINT!!!!\n");
    exit(EXIT_SUCCESS);
}
int main(void) {
    if (signal(SIGINT, procedura_SIGINT) == SIG_ERR) {
        fprintf(stderr, "NIE MOGE PRZECHWYCIC SYGNALU SIGINT!\n");
        exit(EXIT_FAILURE);
    }
    for (;;) {
        pause();
    }
    return 0;
}
