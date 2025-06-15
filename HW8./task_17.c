#include <stdio.h>

int main() {
    int arr[10];
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        int is_unique = 1;
        
        for (int j = 0; j < 10; j++) {
            if (i != j && arr[i] == arr[j]) {
                is_unique = 0;
                break;
            }
        }
        
        if (is_unique) {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}
