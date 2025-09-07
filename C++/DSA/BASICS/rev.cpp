#include <bits/stdc++.h>
using namespace std;

void rev(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    swap(arr[start], arr[end]);
    rev(arr, start + 1, end - 1);
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    int arr[n];
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    
    int x=true;
    rev(arr, 0, n - 1);  
    for (int i=0;i<n;i++){
        if(arr[i]!=arr1[i]){
            x=false;
            break;
        }
    }
    if(x){
        cout<<"Is a palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }

    return 0;
}
