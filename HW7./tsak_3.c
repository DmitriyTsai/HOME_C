#include <stdio.h>

void digits_reverse(int n) {
    if (n < 10) {
        printf("%d", n);
    } else {
        printf("%d ", n % 10);
        digits_reverse(n / 10);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 0) {
        return 1;
    }
    
    if (n == 0) {
        printf("0");
    } else {
        digits_reverse(n);
    }
    
    printf("\n");
    
    return 0;
}
