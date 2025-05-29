#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 10) {
        return 1;
    }

    for (int num = 10; num <= n; num++) {
        int temp = num;
        int sum = 0;
        int product = 1;
        int digit;

        while (temp > 0) {
            digit = temp % 10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }

        if (sum == product && product != 0) {
            printf("%d ", num);
        }
    }

    return 0;
}
