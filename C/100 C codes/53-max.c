#include<stdio.h>
float max(float,float);
int main(){
    float a,b,c;
    printf("Enter first number: ");
    scanf("%f",&a);
    printf("Enter second number: ");
    scanf("%f",&b);
    c = max(a,b);
    printf("max is %f",c);

}
float max(float a, float b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}