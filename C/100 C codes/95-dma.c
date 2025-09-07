#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x_cords;
    int y_cords;
}cords;
int main(){
   
    cords *arr=(cords*)malloc(3*sizeof(cords));
    cords cord[]={
        {2,3},
        {4,5}
    };
    
    for(int i=0;i<2;i++){
        arr[i]=cord[i];
    }
    for(int i=0;i<2;i++){
        printf("%d,%d\n",arr[i].x_cords,arr[i].y_cords);
    }
    printf("%p\n",arr);
    free(arr);
    arr=NULL;
    printf("%p\n",arr);
    
}