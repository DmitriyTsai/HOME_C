#include <stdio.h>

int main() {
    int number;
    int digit1, digit2, digit3;
    int multiplyingNumbers;
    
    scanf("%d", &number);

    // Проверка, что число действительно трехзначное
    if (number < 100 || number > 999) {
        printf("Ошибка: число должно быть трехзначным!\n");
        return 1; 
    }
    
    digit1 = number / 100;        
    digit2 = (number / 10) % 10;  
    digit3 = number % 10;         
    multiplyingNumbers = digit1 * digit2 * digit3;
    printf("%d\n", multiplyingNumbers);

    return 0;
}
