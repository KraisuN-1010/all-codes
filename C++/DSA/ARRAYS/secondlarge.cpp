#include<bits/stdc++.h>
using namespace std;
int second(int arr[],int n){
    int largest=INT_MIN;
    int s_large=INT_MIN;
    for(int i=0;i<n;i++){
        if(largest<arr[i]){
            s_large=largest;
            largest=arr[i];
        }
        else if(arr[i]>s_large && arr[i]!=largest){
            s_large=arr[i];
        }
    }
    return s_large;
}
int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++) cin>>arr[i];
    int s_large=second(arr,n);
    cout<<"Second largest element is:"<<s_large;
}