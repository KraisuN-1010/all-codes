#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr, int rot, int n) {
    int n=arr.size();
    vector<int>temp(n);
    for(int i = 0; i < arr.size(); i++) {
        temp[i] = arr[(i + rot+1) % arr.size()];  // left rotation
    }
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = temp[i];
    }
    }

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int rot;
    cout<<"How many places?:";
    cin>>rot;
    rotate(arr,rot,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}