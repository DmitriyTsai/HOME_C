#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPSILON 0.001

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

float cosinus(float x_degrees) {
    float x = x_degrees * PI / 180.0;
    float result = 0;
    float term;
    int n = 0;
    int sign = 1;
    
    do {
        term = sign * powf(x, n) / factorial(n);
        result += term;
        sign *= -1;
        n += 2;
    } while (fabs(term) >= EPSILON);
    
    return result;
}

int main() {
    float angle;
    scanf("%f", &angle);
    
    if (angle < 0 || angle > 90) {
        return 1;
    }
    
    float cos_val = cosinus(angle);
    printf("%.3f\n", cos_val);
    
    return 0;
}
