#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char encrypt_char(unsigned char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return (char)(((c - 'a' + shift) % 26) + 'a');
    } else if (c >= 'A' && c <= 'Z') {
        return (char)(((c - 'A' + shift) % 26) + 'A');
    }
    // cualquier otro carácter (espacios, tildes, ñ, signos) queda igual
    return (char)c;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <rotacion> \"texto\"\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[1]);
    char *text = argv[2];
    
    // Crear una copia del texto para no modificar el original
    size_t len = strlen(text);
    char *encrypted = malloc(len + 1);
    strcpy(encrypted, text);

    for (size_t i = 0; i < len; i++) {
        encrypted[i] = encrypt_char((unsigned char)encrypted[i], shift);
    }

    printf("%s\n", encrypted);
    free(encrypted);
    return 0;
}