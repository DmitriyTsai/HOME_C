#include <stdio.h>
#include <string.h>

void count_digits(const char *number) {
    int counts[10] = {0};
    
    for (int i = 0; number[i] != '\0'; i++) {
        char c = number[i];
        if (c >= '0' && c <= '9') {
            counts[c - '0']++;
        }
    }
    
    for (int d = 0; d < 10; d++) {
        if (counts[d] > 0) {
            printf("%d %d\n", d, counts[d]);
        }
    }
}

int main() {
    char number[1001];
    scanf("%1000s", number);
    
    count_digits(number);
    
    return 0;
}
