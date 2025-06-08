#include <stdio.h>

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

char to_uppercase(char c) {
    if (is_lowercase(c)) {
        return c - 32;
    }
    return c;
}

int main() {
    char c;
    
    while ((c = getchar()) != '.') {
        putchar(to_uppercase(c));
    }
    putchar('\n');
    
    return 0;
}
