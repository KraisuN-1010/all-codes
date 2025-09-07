#include<stdio.h>
int main(){
    int rows,i=1,j;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    int R=rows;
    while(rows>0){
        j=1;
        int sp=rows-1;
        while(sp>0){
            printf(" ");
            sp--;
        }
        if(rows==1){
            for(int k=0;k<R;k++){
                printf("* ");
            }
            rows--;
        }
        else if(rows!=1){
            while(j<=i*2){
                if(j==1 || j==i*2-1){
                    printf("*");
                    j++;
                }
                else{
                    printf(" ");
                    j++;
                }
            }
            i++;
            rows--;
            printf("\n");
        }
        }
        
}