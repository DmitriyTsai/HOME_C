#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int even = 0;
    int odd = 0;

    if (num == 0) {
        even = 1;
    }

    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        num /= 10;
    }

    printf("%d %d\n", even, odd);
    return 0;
}
