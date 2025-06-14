#include <stdio.h>

void decimal_to_bin(int n) {
    if (n <= 1) {
        printf("%d", n);
        return;
    }
    
    decimal_to_bin(n / 2);
    
    printf("%d", n % 2);
}

int main() {
    int num;
    scanf("%d", &num);
    
    if (num < 0) {
        return 1;
    }
    
        decimal_to_bin(num);
    
    printf("\n");
    return 0;
}
