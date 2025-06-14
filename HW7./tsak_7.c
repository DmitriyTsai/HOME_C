#include <stdio.h>

void print_numbers(int n) {
    if (n < 1) { 
        return;
    }
    printf("%d ", n);
    print_numbers(n - 1); 
}

int main() {
    int N;
    scanf("%d", &N);
    
    print_numbers(N);
    printf("\n");
    
    return 0;
}
