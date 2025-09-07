#include<stdio.h>
int main(){
    int i=3;
    int *ptr=&i;
    printf("Value of i:%d",*ptr);
    *ptr=4;
    printf("\nValue of i:%d",i);
}