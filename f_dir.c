#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj nazwe katalogu>\n", argv[0]);
        return 1;
    }
    mkdir(argv[1], 0755);
    printf("Katalog zostal utworzony z prawami 0755\n", argv[1]);
    return 0;
}
