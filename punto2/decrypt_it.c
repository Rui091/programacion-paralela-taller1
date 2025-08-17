#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char decrypt_char(unsigned char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        int result = (c - 'a' - shift) % 26;
        if (result < 0) result += 26;
        return (char)(result + 'a');
    } else if (c >= 'A' && c <= 'Z') {
        int result = (c - 'A' - shift) % 26;
        if (result < 0) result += 26;
        return (char)(result + 'A');
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
    char *decrypted = malloc(len + 1);
    strcpy(decrypted, text);

    for (size_t i = 0; i < len; i++) {
        decrypted[i] = decrypt_char((unsigned char)decrypted[i], shift);
    }

    printf("%s\n", decrypted);
    free(decrypted);
    return 0;
}