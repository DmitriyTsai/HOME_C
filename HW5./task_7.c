#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number); 
  
    if (number < 0) number = -number;

    int found_duplicate = 0; 
    
    for (int outer = number; outer > 0 && !found_duplicate; outer /= 10) {
        int current_digit = outer % 10; 
        int count = 0; 
   
        for (int inner = number; inner > 0; inner /= 10) {
            if (inner % 10 == current_digit) {
                count++; 
                if (count >= 2) { 
                    found_duplicate = 1; 
                    break; 
                }
            }
        }
    }
    
    printf(found_duplicate ? "YES\n" : "NO\n");
    return 0;
}
