#include<bits/stdc++.h>
using namespace std;
void rec(int arr[],int j){
    if(j<=0) return;
    if(j>0 && arr[j-1]>arr[j]) {
        swap(arr[j-1],arr[j]);
        rec(arr,j-1);
    }
}
void recins(int arr[],int low,int high){
    if(low==high) return;
    rec(arr,low);
    recins(arr,low+1,high);
}
int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    recins(arr, 0, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
