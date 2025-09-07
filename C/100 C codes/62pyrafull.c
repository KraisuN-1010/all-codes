#include<stdio.h>
int main(){
    int rows,i=1,j,s;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    
    while(rows>0){
        s=rows-1;
        while(s>0){
            printf(" ");
            s--;
        }
        j=1;
        while(j<=i){
            printf("* ");
            j++;
        }
        printf("\n");
        i++;
        rows--;
    }
}