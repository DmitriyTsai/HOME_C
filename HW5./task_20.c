#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("NO\n");
        return 0;
    }
    if (n == 2) {
        printf("YES\n");
        return 0;
    }
    if (n % 2 == 0) {
        printf("NO\n");
        return 0;
    }
    
    int is_prime = 1; 
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }

    printf(is_prime ? "YES\n" : "NO\n");
    return 0;
}
