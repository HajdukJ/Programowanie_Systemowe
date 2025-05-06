#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Podaj plik i tekst: ");
        return 1;
    }
    int deskrpytor = open(argv[1], O_WRONLY | O_APPEND);
    write(deskrpytor, argv[2], strlen(argv[2]));
    close(deskrpytor);
    printf("Tekst zostal dopisany do.");
    return 0;
}
