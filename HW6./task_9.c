#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 0 || n > 20) {
        return 1;
    }
    
    long long result = factorial(n);
    printf("%lld\n", result);
    
    return 0;
}
