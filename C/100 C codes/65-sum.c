#include<stdio.h>
int main(){
    
    int arr[4]={1,2,3,4};
    int sum=0,i;
    for(int i=0;i<4;i++){
        sum+=arr[i];
    }
    printf("sum is %d\n",sum);
    printf("avg is %d",sum/4);
}