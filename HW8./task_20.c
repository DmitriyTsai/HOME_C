#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    
    int digits[20] = {0};
    int count = 0;
    
    while (n > 0) {
        digits[count++] = n % 10;
        n /= 10;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (digits[j] < digits[j + 1]) {
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + digits[i];
    }
    
    printf("%lld\n", result);
    
    return 0;
}
