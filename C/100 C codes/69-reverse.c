#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int rev_arr[size];
    int j=0;
    for(int i=size-1;i>=0;i--){
        
        rev_arr[j]=arr[i];
        j++;
    }
    for(int i=0;i<size;i++){
        printf("%d",rev_arr[i]);
    }
}