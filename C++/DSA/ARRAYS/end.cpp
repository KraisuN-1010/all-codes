#include<bits/stdc++.h>
using namespace std;
void end(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            arr.push_back(arr[i]);
            arr.erase(arr.begin()+i);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<arr.size();i++) cin>>arr[i];
    end(arr);
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<endl;
}