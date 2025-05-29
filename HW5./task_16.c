#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (a < 0 || b < 0) {
        return 1;
    }

    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    int gcd = a + b;
    
    printf("%d\n", gcd);

    return 0;
}
