#include <stdio.h>

int main() {
    char c;
    int balance = 0;
    int correct = 1;
    
    while ((c = getchar()) != '.') {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
            if (balance < 0) {
                correct = 0;
            }
        }
    }
    
    if (balance != 0) {
        correct = 0;
    }
    
    printf("%s\n", correct ? "YES" : "NO");
    
    return 0;
}
