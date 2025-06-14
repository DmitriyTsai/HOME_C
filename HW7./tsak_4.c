#include <stdio.h>

void print_num(int num) {
    if (num < 10) {
        printf("%d", num);
        return;
    }
    
    print_num(num / 10);
    
    printf(" %d", num % 10);
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
        print_num(n);
    }
    
    printf("\n");
    
    return 0;
}
