#include<stdio.h>
int main(){
    int arr[2][3]={{1,2,4},{3,4,5}};
    int i,j=0,sum=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
            
        }
    }
    
    printf("The sum is:%d",sum);
}