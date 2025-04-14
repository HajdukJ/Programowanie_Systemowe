#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Funkcja obsługi sygnału SIGINT
void handle_sigint(int sig) {
    printf("Otrzymano sygnał SIGINT!\n");
}

int main() {
    // Zarejestrowanie funkcji obsługi sygnału SIGINT
    signal(SIGINT, handle_sigint);

    printf("Wysylam SIGINT do samego siebie\n");
    kill(getpid(), SIGINT);  // Wysłanie sygnału SIGINT do samego siebie

    // Program może wykonać inne operacje przed zakończeniem
    sleep(2);  // Czekaj 2 sekundy, aby zobaczyć efekt

    return 0;
}
