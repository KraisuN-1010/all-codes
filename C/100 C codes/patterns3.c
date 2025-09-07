#include<stdio.h>
int main(){
    int rows;
    printf("How many rows: ");
    scanf("%d",&rows);
    int n;
    int n2;
    int n3;
    int n4;
    int n5;    
    for(int k=0;k<2;k++){
        if(k==0){
            n5=rows;
            n2=rows;
            n3=1;
            n4=rows;
        }
        else{
            n2=rows;
            n5=rows-1;
            n3=rows-2;
            n4=1;
        }
        for(int i=n5;i>0;i--){
            n=rows;
            for(int j=0;j<rows*2-1;j++){
                if(i==n4){
                    printf("%d ",n);
                }
                else{
                    if(j<rows-(n2-n3)){
                        printf("%d ",n); 
                        n--;
                    }
                    else if(j>=(2*n2)-n3-1){
                        n++;
                        printf("%d ",n);
                    }
                    else{
                        printf("%d ",n); 
                    }
                }
            } 
             if(i<rows){
                if(k==0){
                    n3++;
                }
                else{
                    n3--;
                }
             }
            printf("\n");
        }
    }    
}