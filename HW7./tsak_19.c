#include <stdio.h>

int acounter(void) {
    char c;
    scanf("%c", &c);
    
    if (c == '.') {
        return 0;
    }
    
    return (c == 'a') + acounter();
}

int main() {
    int count = acounter();
    printf("%d\n", count);
    
    return 0;
}
