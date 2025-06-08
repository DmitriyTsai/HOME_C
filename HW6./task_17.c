#include <stdio.h>

int is_happy_number(int n) {
    if (n == 0) {
        return 0;
    }
    
    int sum = 0;
    int product = 1;
    int digit;
    
    while (n > 0) {
        digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    
    return (sum == product);
}

int main() {
    int number;
    scanf("%d", &number);
    
    if (is_happy_number(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
