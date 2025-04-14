#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj plik: \n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    int linie = 0;
    char x;
    while ((x = fgetc(file)) != EOF) {
        if (x == '\n') linie++;
    }
    printf("Liczba wierszy wynosi: %d\n", linie);
    fclose(file);
    return 0;
}
