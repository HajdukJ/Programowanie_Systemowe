#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int fork_status = fork();
    if (fork_status == -1) {
        perror("fork blad");
        return 1;
    }

    if (fork_status == 0) {
        printf("Potomek: PID %d, PPID %d\n", getpid(), getppid());
        return 0;
    }

    int status;
    pid_t pid = wait(&status);
    if (pid == -1) {
        perror("wait blad");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Potomek %d zakończony kodem %d\n", pid, WEXITSTATUS(status));
    }

    return 0;
}
