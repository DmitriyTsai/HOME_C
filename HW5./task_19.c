#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    if (number <= 0) {
        printf("NO\n");
        return 0;
    }

    int sum = 0;
    int temp = number;

    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (sum == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
