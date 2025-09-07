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
    int hasharr[15]={0};
    for(int i=0;i<size;i++){
        hasharr[arr[i]]+=1;
    }
    int num;
    while(true){
        cout<<"Which element's frequency do you want:";
    cin>>num;
    cout<<hasharr[num]<<endl;
    }
    
}