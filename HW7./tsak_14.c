#include <stdio.h>

void print_odds() {
    int num;
    scanf("%d", &num);
    
    if (num == 0) {
        return;
    }
    
    if (num % 2 != 0) { 
        printf("%d ", num);
    }
    
    print_odds();
}

int main() {
    print_odds();
    printf("\n");
    return 0;
}
