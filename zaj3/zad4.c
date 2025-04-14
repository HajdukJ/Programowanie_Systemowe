#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        cpu_set_t set;
        CPU_ZERO(&set);
        CPU_SET(1, &set); //przypisane do rdzenia - pierwszego

        if (sched_setaffinity(0, sizeof(set), &set) == -1) {
            perror("sched_setaffinity");
            exit(1);
        }

        printf("Potomek: PID %d, PPID %d, CPU: %d\n", getpid(), getppid(), sched_getcpu());
        return 0;
    }

    printf("Rodzic: PID %d, PPID %d, CPU: %d\n", getpid(), getppid(), sched_getcpu());

    int status;
    wait(&status);
    return 0;
}
