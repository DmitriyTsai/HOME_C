#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int number;
    scanf("%d", &number);
    
    if (is_prime(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
