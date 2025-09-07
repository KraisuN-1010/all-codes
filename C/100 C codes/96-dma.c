#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr=(int*)calloc(5,sizeof(int));
    for(int i=0;i<5;i++){
        printf("Enter a number:");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    int *new_arr=(int *)realloc(arr,2*sizeof(int));
    // arr=new_arr;
    printf("\n");
    for(int i=0;i<2;i++){
        printf("%d ",new_arr[i]);
    }
}
