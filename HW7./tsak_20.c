#include <stdio.h>

int recurs_power(int n, int p) {
    // Базовые случаи
    if (p == 0) return 1;
    if (p == 1) return n;
    
    return n * recurs_power(n, p - 1);
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    if (p < 0) {
        return 1;
    }
    
    printf("%d\n", recurs_power(n, p));
    
    return 0;
}
