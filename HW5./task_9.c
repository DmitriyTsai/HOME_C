#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    if (num < 0) {
        num = -num;
    }
   
    if (num == 0) {
        printf("YES\n");
        return 0;
    }
    
    while (num > 0) {
        int digit = num % 10; 
        if (digit % 2 != 0) { 
            printf("NO\n");
            return 0; 
        }
        num /= 10;
    }
    
    printf("YES\n");
    return 0;
}
