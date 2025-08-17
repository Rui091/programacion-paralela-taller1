#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 40
int A[N][N], B[N][N];
int SUM[N][N], DIFF[N][N], MULT[N][N];

void *sum_thread(void *arg) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            SUM[i][j] = A[i][j] + B[i][j];
    return NULL;
}

void *diff_thread(void *arg) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            DIFF[i][j] = A[i][j] - B[i][j];
    return NULL;
}

int main() {
    // Inicializar matrices con 0 y 1
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            A[i][j] = rand() % 2;
            B[i][j] = rand() % 2;
        }

    pthread_t t1, t2;
    pthread_create(&t1, NULL, sum_thread, NULL);
    pthread_create(&t2, NULL, diff_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            MULT[i][j] = SUM[i][j] * DIFF[i][j];
        }

    printf("Calculo completado\n");
    return 0;
}