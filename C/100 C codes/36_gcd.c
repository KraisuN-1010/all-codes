#include<stdio.h>
int main()
{
    int num1,num2,max,rem,gcd;
    printf("Enter the first number\n");
    scanf("%d",&num1);
    printf("Enter the seconf number\n");
    scanf("%d",&num2);
    max=(num1>num2)?num1:num2;
    while(1){
        if(max==num1){
            max%=num2;
            num2%=max;
            max%=num2;
            if(max==0){
                gcd=num2;
                break;
            }
            
        }
        else{
            max%=num1;
            num1%=max;
            max%=num1;
            if(max==0){
                gcd=num1;
                break;
            }
        }

    }
    printf("%d",gcd);
}