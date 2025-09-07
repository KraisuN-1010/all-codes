#include<stdio.h>
int main(){
    int i=0;
    int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr3[3][3];
    for(int i=0;i<3;i++){
        int l=0;
        for(int k=0;k<3;k++){
            
                int x,new=0;
            
            for(int j=0;j<3;j++){
                x=arr1[i][j]*arr2[j][l];
                new+=x;
            }
            arr3[i][k]=new;
            l++;
            
            
        }
    }
    printf("new matrix is:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
}
}
