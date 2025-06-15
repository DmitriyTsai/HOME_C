#include <stdio.h>

int last_digit(int num) {
    return (num % 10 + 10) % 10;
}

int main() {
    int arr[10];
    
    // Ввод массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (last_digit(arr[j]) > last_digit(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
