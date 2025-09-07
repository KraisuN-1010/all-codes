#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,3,2,5,10,9,12,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}