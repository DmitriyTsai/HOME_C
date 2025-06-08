#include <stdio.h>

int power(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    int N, P;
    
    scanf("%d %d", &N, &P);
    
    if (P < 0) {
        return 1;
    }
    
    if (N > 1000 || N < -1000) {
        return 1;
    }
    
    int res = power(N, P);
    printf("%d\n", res);
    
    return 0;
}
