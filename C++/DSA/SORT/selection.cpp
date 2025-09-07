#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,6,7,4,8,0,24};
    int min=arr[0];
    int index;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-2;i++){
        for(int j=i;j<size-1;j++){
            if(min>arr[j]){
                min=arr[j];
                index=j;
            }
        }
        swap(arr[i],arr[index]);
        min=arr[i+1];
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}