
#include <stdio.h>

int main() {
    int num1, num2, num3;
    int sum;
   
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    sum = num1 + num2 + num3;  
	
    printf("%d+%d+%d=%d\n", num1, num2, num3, sum);
    return 0;
}
