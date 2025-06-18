#include <stdio.h>

void print_digit(char s[]) {
    int counts[10] = {0};

    // Подсчет цифр в строке
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            counts[digit]++;
        }
    }

    for (int d = 0; d < 10; d++) {
        if (counts[d] > 0) {
            printf("%d %d\n", d, counts[d]);
        }
    }
}
 /*
int main() {
    char test1[1001] = {0};
    scanf("%1000s", test1);

    print_digit(test1);

    return 0;
}
*/
