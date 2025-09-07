#include<stdio.h>
#include<stdlib.h>
int main(){
    
    char *arr=(char *)calloc(20,sizeof(char));
    arr="Hello my name is uday";
    printf("%s",arr);
    // printf("%s",printf("%d",1234));
}