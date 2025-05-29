#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    
   
    if (number < 0) {
        number = -number;
    }
    
    int prev_digit = -1;  
    int current_digit;
    int has_duplicates = 0; 
    
    while (number > 0) {
        current_digit = number % 10; 
        
        if (current_digit == prev_digit) {
            has_duplicates = 1;
            break;
        }
        
        prev_digit = current_digit;
        number /= 10;  
    }
    
    printf(has_duplicates ? "YES\n" : "NO\n");
    
    return 0;
}
