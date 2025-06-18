#include <stdio.h>

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return 1;
            }
        }
    }
    return 0;
}
/*
int main() {
    int size;
    scanf("%d", &size);
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (is_two_same(size, arr)){
    printf("yes");
    }
    else {
    printf("no");
    }
    
    return 0;
    }
*/
