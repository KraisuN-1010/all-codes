#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,3,2,5,10,9,12,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}