#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj plik: \n", argv[0]);
        return 1;
    }
    FILE *zrodlo = fopen(argv[1], "r");
    FILE *kopia = fopen("kopia.txt", "w");
    char x;
    while ((x = fgetc(zrodlo)) != EOF) {
        fputc(x, kopia);
    }
    printf("Plik zostal skopiowany(kopia.txt).\n");
    fclose(zrodlo);
    fclose(kopia);
    return 0;
}
