#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Podaj nazwę pliku i prawa dostępu.\n");
        return 1;
    }
    int prawa = strtol(argv[2], NULL, 8);
    int deskrpytor = open(argv[1], O_CREAT | O_EXCL, prawa);
    close(deskrpytor);
    printf("Plik utworzony z prawami: %s\n", argv[2]);
    return 0;
}
