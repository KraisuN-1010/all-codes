#include<stdio.h>
int square(int);

int main(){
    int b;
    printf("Eneter the numbera:");
    scanf("%d",&b);
    int a=square(b);
    printf("square is %d",a);
    
}
int square(int num){
   
    num*=num;
    return num;
}