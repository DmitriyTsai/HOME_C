
#include <stdio.h>

int main() {
    float num1, num2, num3;
    float arithmeticMean;
   
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    arithmeticMean = (num1 + num2 + num3)/3;  
	
    printf("%.2f", arithmeticMean);
    return 0;
}
