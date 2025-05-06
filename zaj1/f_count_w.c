#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj plik: ", argv[0]);
        return 1;
    }
    FILE *plik = fopen(argv[1], "r");
    int slowa = 0;
    char x, y = ' ';
    while ((x = fgetc(plik)) != EOF) {
        if (isspace(x) && !isspace(y)) slowa++;
        y = x;
    }

    printf("Liczba słów: %d\n", slowa);
    fclose(plik);
    return 0;
}
