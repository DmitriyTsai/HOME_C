#include <stdio.h>

void print_simple(int n) {
    if (n == 1) {
        printf("1");
        return;
    }

    while (n % 2 == 0) {
        printf("2 ");
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    if (n > 2) {
        printf("%d ", n);
    }
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    if (number <= 0) {
        return 1;
    }
    
    print_simple(number);
    
    return 0;
}
