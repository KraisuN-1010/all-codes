#include<stdio.h>
int main(){
    int fact=1,num,i=1;
    printf("Enter the number: ");
    scanf("%d",&num);
    
        while(i<=num){
            fact=fact*i;
            i++;
        }
        printf("The factorial of given number is %d",fact);
}