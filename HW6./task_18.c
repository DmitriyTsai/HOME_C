#include <stdio.h>

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char c;
    int count = 0;
    
    do {
        scanf("%c", &c);
        if (is_digit(c)) {
            count++;
        }
    } while (c != '.');
    
    printf("%d\n", count);
    
    return 0;
}
