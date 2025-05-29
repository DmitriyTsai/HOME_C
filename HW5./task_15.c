#include <stdio.h>

int main() {
    int num;
    int count = 0;
    
    
    do {
        scanf("%d", &num);
        if ((num > 0) && (num %2 == 0)) {
            count++;
        }
    } while (num != 0);
    
    printf("%d\n", count);
    return 0;
}
