#include <stdio.h>

int main() {
    int number;
    int sum = 0;
   
    scanf("%d", &number);

    while (number > 0) {
        sum += number % 10;  
        number /= 10;       
    }
    
    printf("%d\n", sum);
    
    return 0;
}
