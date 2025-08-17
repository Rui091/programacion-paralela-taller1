#include <iostream>
#include <string>
#include <cstdlib>

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
    return (char)c; // otros caracteres se dejan igual
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <rotacion> \"texto\"\n";
        return 1;
    }

    int shift = std::atoi(argv[1]);
    std::string text = argv[2];

    for (size_t i = 0; i < text.size(); i++) {
        text[i] = decrypt_char((unsigned char)text[i], shift);
    }

    std::cout << text << std::endl;
    return 0;
}
