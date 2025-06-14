#include <stdio.h>

int count_ones(int n) {
    if (n == 0) {
        return 0;
    }
    return (n & 1) + count_ones(n >> 1);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int ones = count_ones(N);
    printf("%d\n", ones);
    
    return 0;
}
