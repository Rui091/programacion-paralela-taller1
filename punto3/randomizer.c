#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 1; i++) {
        int num = rand() % 100;
        printf("%d\n", num);
    }
    return 0;
}