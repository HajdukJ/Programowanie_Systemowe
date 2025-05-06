#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Podaj plik i liczbe znakow(do odczytu).\n");
        return 1;
    }
    int liczba_znakow = atoi(argv[2]);
    int deskrpytor = open(argv[1], O_RDONLY);
    char bufor[liczba_znakow];
    int przeczytano = read(deskrpytor, bufor, liczba_znakow);
    write(STDOUT_FILENO, bufor, przeczytano);
    close(deskrpytor);
    return 0;
}
