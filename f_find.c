#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Podaj plik i wzorzec.\n");
        return 1;
    }
    FILE *plik = fopen(argv[1], "r");
    char linia[1024];
    while (fgets(linia, sizeof(linia), plik)) {
        if (strstr(linia, argv[2])) {
            printf("Wzorzec znaleziony: %s", linia);
            fclose(plik);
            return 0;  
        }
    }
    fclose(plik);
    return 0;
}
