#include<stdio.h>
int main(){
    int rows,i=1,j,s,n,Rows;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    Rows=rows;
    while(rows>0){
        s=rows;
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
    
    
    i=Rows;
    n=Rows+1;
    while(Rows>0){
        
        j=1;
        while(j<=i){
            printf("* ");
            j++;
        }
        s=n-Rows;
        
        printf("\n");
        while(s!=0){
            printf(" ");
            s--;
        }
        i--;
        Rows--;
}
}


  
