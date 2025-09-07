#include<stdio.h>
int add(int,int,int,int);
int main(){
    int a,b,c,d,sum;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Enter the third number: ");
    scanf("%d",&c);
    printf("Enter the fourth number: ");
    scanf("%d",&d);
    sum= add(a,b,c,d);
    printf("%d",sum);
}
int add(int a,int b,int c,int d){
    return (a+b+c+d);
}