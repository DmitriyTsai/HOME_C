#include <stdio.h>

int calculate_f(int x) {
    if (x < -2) {
        return 4;
    } else if (x >= -2 && x < 2) {
        return x * x;
    } else { // x >= 2
        return x * x + 4 * x + 5;
    }
}

int main() {
    int x;
    int max_value = -2147483647;
    
    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            break;
        }
        
        int current = calculate_f(x);
        if (current > max_value) {
            max_value = current;
        }
    }
    
    printf("%d\n", max_value);
    
    return 0;
}
