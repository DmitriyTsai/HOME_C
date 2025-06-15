#include <stdio.h>

int main() {
    int arr[10];
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int last = arr[9];
    
    for (int i = 9; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = last;
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
