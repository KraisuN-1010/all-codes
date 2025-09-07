#include<stdio.h>
int fact=1;
int factorial(int n){
    if(n==0){
        return fact;
    }
    fact*=n;
    return factorial(n-1);
}
int main(){
    printf("%d",factorial(5));
}
