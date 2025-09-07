#include<stdio.h>
int main(){
    int i,n=0;
    int arr[5]={1,1,3,1,2};
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]==arr[j]){
                n++;
            }
        }
        
    }
    printf("number of occurences are:%d",n);
}