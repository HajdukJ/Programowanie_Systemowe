#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main() {
    printf("Wysylam SIGINT do samego siebie\n");
    kill(getpid(), SIGINT);
    return 0;
}
