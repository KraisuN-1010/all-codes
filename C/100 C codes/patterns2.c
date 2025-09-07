#include<stdio.h>
int main(){
    int rows,i=1,j,s;
    int c=1;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    
    while(rows>0){
        s=rows-1;
        while(s>0){
            printf(" ");
            s--;
        }
        j=0;
        c=1;
        while(j<i/2){
            printf("%d",c++);
            j++;
            
        }
       
        while (j>=i/2 && j<i)
        {
            printf("%d",c--);
            j++;
        }
        
        printf("\n");
        i+=2;
        rows--;
    }
}