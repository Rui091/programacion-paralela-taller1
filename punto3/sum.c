#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    pid_t pid;
    int start = 2, end = 10; 
    pipe(fd);

    if ((pid = fork()) == 0) {
        // Proceso hijo
        close(fd[0]); // Cierra lectura
        int sum = 0;
        for (int i = start; i <= end; i++) sum += i;
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        exit(0);
    } else {
        // Proceso padre
        close(fd[1]); // Cierra escritura
        int result;
        wait(NULL);
        read(fd[0], &result, sizeof(result));
        close(fd[0]);
        printf("La suma es: %d\n", result);
    }
    return 0;
}