#include <stdio.h>

int find_max_array(int size, int a[]) {
    int max = a[0];
    
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    return max;
}
/*
int main() {
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int max =  find_max_array(size, arr);
    printf("%d\n", max);
    return 0;
}
 */
