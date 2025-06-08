#include <stdio.h>

// Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.

void convertToBase(int n, int p) {
    if (n == 0) {
        return;
    }
    convertToBase(n / p, p);
    printf("%d", n % p);
}

int main() {
    int N, P;
    
    scanf("%d %d", &N, &P);

    if (N < 0) {
        return 1;
    }
    if (P < 2 || P > 9) {
        return 1;
    }
    
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    
    convertToBase(N, P);
    
    return 0;
}
