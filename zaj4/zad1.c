#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *msg1 = "DZIEN DOBRY";
char *msg2 = "WIADOMOSC 2";
char *msg3 = "WIADOMOSC 3";

int main() {
    int ilosc = 20;
    char buf[ilosc];
    int fd[2];
    if (pipe(fd) == -1) {
        perror("BLAD TWORZENIA POTOKU !");
    }
    write(fd[1], msg1, ilosc);
    read(fd[0], buf, ilosc);
    printf("%s\n", buf);

    write(fd[1], msg2, ilosc);
    read(fd[0], buf, ilosc);
    printf("%s\n", buf);
    
    write(fd[1], msg3, ilosc);
    read(fd[0], buf, ilosc);
    printf("%s\n", buf);
    exit(0);
}
