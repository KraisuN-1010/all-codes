#include<stdio.h>
int primeint(int,int);
int main(){ 
    int num3,num4;
    printf("Enter first number:");
    scanf("%d",&num3);
    printf("Enter second number:");
    scanf("%d",&num4);
    primeint(num3,num4);
}
int primeint(int num1,int num2){
    int x;
    
     int y = 2;
        while (y < num1)
        {
            if (num1 % y == 0)
            {
                
                x=0;
                break;
            }

            else
            {
                x = 1;
            }
            y++;
        }
        if(num1==2){
            printf("%d ",num1);
        }
        if (x == 1 || num1==2){
            printf("%d ", num1);
        }
        if(num1<num2){
            return primeint(num1+1,num2);
        }
    
}
