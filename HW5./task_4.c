#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);

    if (number < 100 || number > 999) {
        printf("NO\n"); 
    }
    
    if (number >= 100 && number <= 999) {
        printf("YES\n"); 
    }
    
    return 0;
}
