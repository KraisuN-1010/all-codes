#include<stdio.h>
int fibonacci(int);
int a=0,b=1,c=1;
int main(){
    int n;
    printf("enter the number of terms you want:");
    scanf("%d",&n);
    printf("%d",b);
    fibonacci(n);
    
}
int fibonacci(int n){
    if(n==0){
        return 1;
    }
   c=a+b;
   printf("%d",c);
   a=b;
   b=c;
    fibonacci(n-1);
}