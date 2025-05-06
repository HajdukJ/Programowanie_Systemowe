#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *msg = "DZIEN DOBRY";

int main() {
    int ilosc = 20;
    char buf[ilosc];
    int p2c[2];
    int c2p[2];
    char *msg2 = "witaj rodzicu";
    pipe(p2c);
    pipe(c2p);
    
    if (fork() == 0) {
        close(p2c[1]);
        close(c2p[0]);
        read(p2c[0], buf, ilosc);
        printf("Dziecko otrzymalo: %s\n", buf);
        write(c2p[1], msg2, strlen(msg2));
    } else {
        close(p2c[0]);
        close(c2p[1]);
        write(p2c[1], msg, ilosc);
        read(c2p[0], buf, ilosc);
        printf("Rodzic otrzymal: %s\n", buf);
    }
    return 0;
}
