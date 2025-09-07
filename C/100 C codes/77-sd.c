#include<stdio.h>
int main(){
    int arr[]={24,6,5,9,10,4};
    
    int size=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<size;j++){
    //         if(arr[j]>arr[j+1]){
    //             int c;
    //             c=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=c;
    //         }
            
    //     }
    // }
        int arr2[6];
        for(int i=0;i<size;i++){
            if(i<size-1){
                arr2[i]=arr[i+1]-arr[i];
            }
            else if(i==size-1){
                arr2[i]=arr[i];
            }
        }
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=arr2[i];
        }
        printf("\nStandard deviation is:%d",sum/6);
}
  
