#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

int semid;

void opusc(int s_n) {
    struct sembuf sops = {s_n, -1, 0};
    if (semop(semid, &sops, 1) == -1) {
        perror("Błąd przy opuszczaniu semafora");
        exit(1);
    }
}

void podnies_sem(int s_n) {
    struct sembuf sops = {s_n, 1, 0};
    if (semop(semid, &sops, 1) == -1) {
        perror("Błąd przy podnoszeniu semafora");
        exit(1);
    }
}

void child() {
    for (int i = 0; i <= 20; i += 2) {
        opusc(0); // dziecko czeka na semafor 0
        printf("Dziecko (parzysta): %d\n", i);
        podnies_sem(1); // daje znak rodzicowi
	sleep(1);
    }
}

void parent() {
    for (int i = 1; i < 20; i += 2) {
        opusc(1); // rodzic czeka na semafor 1
        printf("Rodzic (nieparzysta): %d\n", i);
        podnies_sem(0); // daje znak dziecku
	sleep(1);
    }
}

int main() {
    semid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("Błąd semget");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1 ||
        semctl(semid, 1, SETVAL, 0) == -1) {
        perror("Błąd semctl przy ustawianiu semaforów");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Błąd fork");
        exit(1);
    } else if (pid == 0) {
        // proces potomny
        child();
        exit(0);
    } else {
        // proces rodzica
        parent();

        int status;
        waitpid(pid, &status, 0);

        if (semctl(semid, 0, IPC_RMID) == -1) {
            perror("Błąd przy usuwaniu semaforów");
        } else {
            printf("Semafory zostały usunięte.\n");
        }
    }

    return 0;
}
