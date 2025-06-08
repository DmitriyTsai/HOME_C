#include <stdio.h>

int sum_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
int main() {
    int N;
    
    scanf("%d", &N);
    
    if (N <= 0) {
        return 1;
    }
    
    int result = sum_to_n(N);
    
    printf("%d\n", result);
    
    return 0;
}
