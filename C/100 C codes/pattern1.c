#include<stdio.h>
int main(){
    int n,i=0,j=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(i<n){
        for(int j=0;j<n*2;j++){
            printf("*");
        }
        printf("\n");
        i++;
    }
}