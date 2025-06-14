#include <stdio.h>

int sum_digits(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + sum_digits(n / 10);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int sum = sum_digits(N);
    printf("%d\n", sum);
    
    return 0;
}
