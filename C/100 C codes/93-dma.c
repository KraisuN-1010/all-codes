#include<stdio.h>
#include<stdlib.h>
int main(){
    int size;
    printf("Enter the size:");
    scanf("%d",&size);
    // int arr[size];
    int *arr=malloc(2*size);    
    for(int i=0;i<size;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<size;j++){
        
        printf("%d ",arr[j]);
    }

}