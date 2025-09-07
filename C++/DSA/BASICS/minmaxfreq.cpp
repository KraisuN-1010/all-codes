#include<bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cout << "Enter the size: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }
    int maxx = INT_MIN, minn = INT_MAX;
    int num1 = -1, num2 = -1;
    for(auto it : mp) {
        if(it.second > maxx) {
            maxx = it.second;
            num1 = it.first;
        }
        if(it.second < minn) {
            minn = it.second;
            num2 = it.first;
        }
    }
    cout << "Max frequency is: " << maxx << " Of: " << num1 << endl;
    cout << "Min frequency is: " << minn << " Of: " << num2 << endl;
    return 0;
}
