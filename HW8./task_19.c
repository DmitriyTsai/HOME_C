#include <stdio.h>
#include <string.h>

int main() {
    char number[20];
    scanf("%s", number);
    
    int length = strlen(number);
    
    for (int i = 0; i < length; i++) {
        printf("%c", number[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
    
    return 0;
}
