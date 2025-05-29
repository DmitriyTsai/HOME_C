#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num <= 0) {
        return 1;
    }

    int minDigit = 9;
    int maxDigit = 0;

    while (num > 0) {
        int currentDigit = num % 10;
        num /= 10;

        if (currentDigit < minDigit) {
            minDigit = currentDigit;
        }

        if (currentDigit > maxDigit) {
            maxDigit = currentDigit;
        }
    }

    printf("%d %d\n", minDigit, maxDigit);
    return 0;
}
