#include<stdio.h>
int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={6,7,8,9,10};
    int merge[11];
    for(int i=0;i<5;i++){
        merge[i]=arr1[i];
    }
    for(int i=0;i<5;i++){
        merge[i+5]=arr2[i];
    }
    for(int i=0;i<10;i++){
        printf("%d ",merge[i]);
    }
}