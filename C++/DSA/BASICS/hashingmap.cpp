#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size:";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]+=1;
    }
    int num;
    while(true){
        cout<<"Which element's frequency do you want:";
    cin>>num;
    cout<<mp[num]<<endl;
    }
    
}