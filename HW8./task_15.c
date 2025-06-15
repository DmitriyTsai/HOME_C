#include <stdio.h>

int main() {
    int positive[10], negative[10];
    int pos_count = 0, neg_count = 0;
    
    for (int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        
        if (num < -500 || num > 500) {
            continue;
        }
        
        if (num > 0) {
            positive[pos_count++] = num;
        } else if (num < 0) {
            negative[neg_count++] = num;
        }
    }
    
    for (int i = 0; i < pos_count; i++) {
        printf("%d ", positive[i]);
    }
    
    for (int i = 0; i < neg_count; i++) {
        printf("%d ", negative[i]);
    }
    
    return 0;
}
