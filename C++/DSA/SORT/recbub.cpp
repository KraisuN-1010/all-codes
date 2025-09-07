#include<bits/stdc++.h>
using namespace std;
void rec(int arr[],int low,int high){
    if(low==high) return;
    if(arr[low]>arr[low+1]) {
        swap(arr[low],arr[low+1]);
    }
    rec(arr,low+1,high);
}
void recbub(int arr[],int low,int high){
    if(low==high) {
        return;
    }
    rec(arr,0,high);
    recbub(arr,low,high-1);
}
int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Sorted array:\n";
    recbub(arr,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}