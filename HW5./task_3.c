#include <stdio.h>

int main() {
    int a, b;
    int sum = 0;  

    scanf("%d %d", &a, &b);
    
    if (a > b) {
        return 1;
    }
    
    for (int i = a; i <= b; i++) {
        sum += i * i; 
    }
    
    printf("%d\n", sum);
    
    return 0;
}
