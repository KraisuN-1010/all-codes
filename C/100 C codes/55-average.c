#include<stdio.h>
int get_average(int,int,int,int,int);
int main(){
    int a,b,c,d,e;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("Enter third number: ");
    scanf("%d",&c);
    printf("Enter fourth number: ");
    scanf("%d",&d);
    printf("Enter fifth number: ");
    scanf("%d",&e);
    get_average(a,b,c,d,e);
}
int get_average(int a,int b,int c,int d,int e){
    printf("%d",(a+b+c+d+e)/5); 
}