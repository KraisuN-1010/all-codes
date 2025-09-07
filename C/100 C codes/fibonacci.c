#include<stdio.h>
int main(){
    int n,a=0,b=1,c=1,i;
    printf("Enter number:");
    scanf("%d",&n);
    if(n>0){
        i=2;
        printf("%d",b);
        while(i<=n){
            c=a+b;
            printf("%d",c);
            a=b;
            b=c;
            i++;
        }
    }
    else{
        printf("Invalid input");
    }
}