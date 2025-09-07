#include<stdio.h>
void minmax(int*,int*,int*,int*);
int main(){
    int c,d;
    int max;
    int min;
    printf("Enter first number: ");
    scanf("%d",&c);
    printf("Enter second number: ");
    scanf("%d",&d);
    minmax(&c,&d,&max,&min);
    
}



void minmax(int *a,int *b,int *max,int *min ){

    if(*a>*b){
      
        *max=*a;
        *min=*b;
    }
    else{
        *max=*b;
        *min=*a;
    }
    printf("max value is %d,min value is %d",*max,*min);
}


