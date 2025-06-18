#include <stdio.h>

int compression(int a[], int b[], int N) {
    if (N == 0) return 0;
    
    int count = 0;
    int current = a[0];
    int length = 1;
    
    if (current == 1) {
        b[count++] = 0;
    }
    
    for (int i = 1; i < N; i++) {
        if (a[i] == current) {
            length++;
        } else {
            b[count++] = length;
            current = a[i];
            length = 1;
        }
    }
    
    b[count++] = length;
    return count;
}

int main() {
    int N;
    printf("Введите размер массива (N > 0): ");
    scanf("%d", &N);
    
    if (N <= 0) {
        printf("Неверный размер массива!\n");
        return 1;
    }
    
    int a[N], b[N];
    
    printf("Введите %d элементов массива (0 или 1): ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    
        if (a[i] != 0 && a[i] != 1) {
            printf("Ошибка: элементы должны быть 0 или 1! А вы ввели %d \n", a[i]);
            return 1;
        }
    }
    
    int compressed_size = compression(a, b, N);
    
    printf("Сжатый массив: [");
    for (int i = 0; i < compressed_size; i++) {
        printf("%d", b[i]);
        if (i < compressed_size - 1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}
