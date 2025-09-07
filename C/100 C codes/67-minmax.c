#include<stdio.h>
int main(){
    int i,j,max,min;
    int arr[]={3,5,8,2,145};
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr[j]>arr[j+1]){
                int c;
                c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=c;
            }
            
        }
    }
    for(i=0;i<5;i++){
        if(arr[i]>arr[i+1]){
            max=arr[i];
        }
        else{
            max=arr[i+1];
        }
    }
    printf("Max is %d\n",max);
    for(i=5;i>0;i--){
        if(arr[i]<arr[i-1]){
            min=arr[i];
        }
        else{
            min=arr[i-1];
        }
    }
    printf("Min is %d",min);
}