#include <stdio.h>

int Akkerman(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return Akkerman(m - 1, 1);
    }
    return Akkerman(m - 1, Akkerman(m, n - 1));
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    printf("%d\n", Akkerman(m, n));
    
    return 0;
}
