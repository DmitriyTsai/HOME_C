#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    float k, b;
    
    k = (float)(y2 - y1) / (x2 - x1);  // Вычисляем угловой коэффициент k
    
    b = y1 - k * x1; // Вычисляем свободный член b
 
    printf("%.2f %.2f\n", k, b);
    
    return 0;
}
