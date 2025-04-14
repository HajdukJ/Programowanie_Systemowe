#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void uruchom_potomka(void) {
    printf("Potomek: PID %d, PPID %d\n", getpid(), getppid());
    execl("./SIGTERM", "SIGTERM", NULL);
    perror("execl");
    exit(1);
}

void sprawdz_status(pid_t pid, int status) {
    if (WIFEXITED(status))
        printf("Potomek %d zakończył się kodem %d\n", pid, WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("Potomek %d zakończony sygnałem %d%s\n", pid, WTERMSIG(status),
               WCOREDUMP(status) ? " (zrzut)" : "");
}

int main(void) {
    printf("Rodzic: PID %d, PPID %d\n", getpid(), getppid());

    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            uruchom_potomka();
        }

        int status;
        pid_t zakonczony = wait(&status);
        sprawdz_status(zakonczony, status);
    }

    return 0;
}
