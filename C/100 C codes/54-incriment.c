#include<stdio.h>
int incriment(int);
int main(){
    int i=1;
    printf("%d",i);
    incriment(i);
}
int incriment(int i){
    i++;
    printf("%d",i) ;
}