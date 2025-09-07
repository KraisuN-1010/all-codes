#include<stdio.h>
int main()
{
    int num1,num2,lcm;
    printf("Enter the first number\n");
    scanf("%d",&num1);
    printf("Enter the seconf number\n");
    scanf("%d",&num2);
    lcm=(num1>num2)?num1:num2;
    while(1){
        if(lcm%num1==0 && lcm%num2==0){
            break;
        }
        lcm++;
    }
    printf("The LCM of %d and %d is %d",num1,num2,lcm);

    return 0;
}