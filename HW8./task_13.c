#include <stdio.h>

int main() {
    int input[10];
    int result[10];
    int count = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < 10; i++) {
        int num = input[i];
        if (num < 0) {
            num = -num;
        }
        
        int tens = (num / 10) % 10;
        if (tens == 0) {
            result[count++] = input[i];
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
