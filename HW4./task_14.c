#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);

    int digit1 = number / 100;        
    int digit2 = (number / 10) % 10; 
    int digit3 = number % 10;         
    
    int max = digit1;
    if (digit2 > max) max = digit2;
    if (digit3 > max) max = digit3;
    
    printf("%d\n", max);
    
    return 0;
}
