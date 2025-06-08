#include <stdio.h>

int grow_up(int n) {
    if (n < 10) {
        return 1;
    }
    
    int prev_digit = n % 10;
    n /= 10;
    
    while (n > 0) {
        int current_digit = n % 10;
        if (current_digit >= prev_digit) {
            return 0;
        }
        prev_digit = current_digit;
        n /= 10;
    }
    
    return 1;
}

int main() {
    int number;
    scanf("%d", &number);
    
    if (grow_up(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
