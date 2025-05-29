#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    int prevDigit = 10;
    int currentDigit;

    while (num > 0) {
        currentDigit = num % 10; 
        if (currentDigit >= prevDigit) {
            printf("NO\n");
            return 0;
        }
        prevDigit = currentDigit;
        num /= 10;
    }
        printf("YES\n");
        
    return 0;
}
