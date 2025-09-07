#include<stdio.h>

int main() {
    int num1, num2, gcd;
    
    
    printf("Enter the first number\n");
    scanf("%d", &num1);
    printf("Enter the second number\n");
    scanf("%d", &num2);
    
    
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    
    gcd = num1;
    printf("GCD is: %d\n", gcd);
    
    return 0;
}
