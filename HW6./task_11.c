#include <stdio.h>

int nod(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    if (num1 <= 0 || num2 <= 0) {
        return 1;
    }
    
    int result = nod(num1, num2);
    printf("%d\n", result);
    
    return 0;
}
