#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }
        
    printf("%d\n", num);
    
    return 0;
}
