#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int fork_status = fork();
    if (fork_status == -1) {
        perror("fork");
        return 1;
    }

    if (fork_status == 0) {
        printf("Potomek: PID %d, PPID %d\n", getpid(), getppid());
        execl("./SIGTERM", "SIGTERM", NULL);
        perror("execl");
        return 1;
    }

    printf("Rodzic: PID %d, PPID %d\n", getpid(), getppid());

    int status;
    pid_t pid = wait(&status);
    if (pid == -1) {
        perror("wait");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Potomek %d zakończył się kodem %d\n", pid, WEXITSTATUS(status));
    }

    if (WIFSIGNALED(status)) {
        printf("Potomek %d zakończony sygnałem %d%s\n", pid, WTERMSIG(status),
            WCOREDUMP(status) ? " (zrzut)" : "");
    }

    return 0;
}
