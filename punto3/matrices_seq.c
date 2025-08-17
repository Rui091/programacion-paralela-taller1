#include <stdio.h>
#include <stdlib.h>

#define N 40
int A[N][N], B[N][N];
int SUM[N][N], DIFF[N][N], MULT[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 2;
            B[i][j] = rand() % 2;
        }
    }

    // Calcular suma
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            SUM[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DIFF[i][j] = A[i][j] - B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            MULT[i][j] = SUM[i][j] * DIFF[i][j];
        }
    }

    printf("Calculo secuencial completado\n");
    return 0;
}