#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 1;
    }

    long long a = 0, b = 1, c;
    
    if (n >= 1) printf("1");
    
    for (int i =2; i <= n; i++) {
        c = a + b;
        printf(" %lld", c);
        a = b;
        b = c;
    }
    
    printf("\n");
    return 0;
}
