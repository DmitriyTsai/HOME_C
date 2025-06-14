#include <stdio.h>

void reverse_string() {
    char c;

    if (scanf("%c", &c) != 1) {
        return; 
    }
    if (c == '.') {
        return; 
    }
    reverse_string();
    printf("%c", c);
}

int main() {
    reverse_string();
    printf("\n");
    return 0;
}
