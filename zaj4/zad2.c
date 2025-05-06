#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *msg = "DZIEN DOBRY";

int main() {
    int ilosc = 20;
    char buf[ilosc];
    int fd[2];
    if (pipe(fd) == -1) {
        perror("BLAD TWORZENIA POTOKU !");
    }
    if (fork() == 0) {
        close(fd[1]);
        read(fd[0], buf, ilosc);
        printf("%s\n", buf);
    } else {
        close(fd[0]);
        write(fd[1], msg, ilosc);
    }
    return 0;
}
