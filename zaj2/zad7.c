#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigusr1(int sig) {
    system("python3 trojkat_prostokatny.py");
}
void handle_sigusr2(int sig) {
    system("python3 trojkat_rownoboczny.py");
}
int main() {
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    while (1) {
        pause();
    }
    return 0;
}
