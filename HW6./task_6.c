#include <stdio.h>
#include <stdint.h> 

uint64_t rice_on_square(int n) {
    if (n < 1 || n > 64) {
        return 0;
    }
    
    uint64_t grains = 1;
    
    for (int i = 1; i < n; i++) {
        grains *= 2;
    }
    
    return grains;
}

int main() {
    int cell_number;
    
    scanf("%d", &cell_number);
    
    uint64_t grains = rice_on_square(cell_number);
    
        printf("%llu\n", grains);
    
    return 0;
}
