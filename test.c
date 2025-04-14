#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main (int argc, char * argv[]) {
    int deskrpytor;
    int kod_bledu;
    errno=0;
    deskrpytor = open(argv[1], O_RDWR);
    kod_bledu = errno;
    if (deskrpytor < 0) {
        switch (kod_bledu) {
            case EACCES: perror("BLAD: PROBLEM Z PRAWAMI DOSTEPU\n");
        }
        return 5;
    } else {
        printf("Jest OK\n");
    }
    close(deskrpytor);
    return 0;
}
