
#include<stdio.h>
int main(){
    int rows,i,j,s,n;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    i=rows;
    n=rows+1;
    while(rows>0){
        
        j=1;
        while(j<=i){
            printf("* ");
            j++;
        }
        s=n-rows;
        
        printf("\n");
        while(s!=0){
            printf(" ");
            s--;
        }
        i--;
        rows--;
    }
}