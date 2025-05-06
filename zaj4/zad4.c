#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

char *msg = "DZIEN DOBRY";

int main() {
    int ilosc = 20;
    char buf[ilosc];
    int p2c[2];
    int c2p[2];

    pipe(p2c);
    pipe(c2p);
    if (fork() == 0) {
        close(p2c[1]);
        close(c2p[0]);
        read(p2c[0], buf, ilosc);
        for (int i = 0; i < ilosc && buf[i]; i++) {
            buf[i] = tolower(buf[i]);
        }
        write(c2p[1], buf, ilosc);
    } else {
        close(p2c[0]);
        close(c2p[1]);
        write(p2c[1], msg, ilosc);
        read(c2p[0], buf, ilosc);
        printf("Rodzic otrzymal: %s\n", buf);
    }
    return 0;
}
