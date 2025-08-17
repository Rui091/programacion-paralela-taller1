#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define n 1
int main() {
    int *nums = malloc(n * sizeof(int));
    if (!nums) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int chunk = n / 3; 
    int pipefd[3][2];
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        pids[i] = fork();
        if (pids[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0) {
            close(pipefd[i][0]); 

            int start = i * chunk;
            int end = (i == 2) ? n : start + chunk; 
            int suma = 0;
            for (int j = start; j < end; j++)
                suma += nums[j];

            write(pipefd[i][1], &suma, sizeof(suma));
            close(pipefd[i][1]);
            free(nums);
            exit(EXIT_SUCCESS);
        }
        close(pipefd[i][1]); 
    }

    int total = 0, parcial;
    for (int i = 0; i < 3; i++) {
        read(pipefd[i][0], &parcial, sizeof(parcial));
        total += parcial;
        close(pipefd[i][0]);
        waitpid(pids[i], NULL, 0);
    }

    printf("%d\n", total);
    free(nums);
    return 0;
}