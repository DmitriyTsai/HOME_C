#include <stdio.h>

int sum_numbers(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum_numbers(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 1) {
        return 1;
    }
    
    int result = sum_numbers(n);
    printf("%d\n", result);
    
    return 0;
}
