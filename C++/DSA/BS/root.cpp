#include <bits/stdc++.h>
using namespace std;

int nthRoot(int num, int roots) {
    int low = 1, high = num;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long midPower = pow(mid, roots);
        if (midPower == num) return mid;
        else if (midPower < num) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  
}

int main() {
    int num, roots;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter order of root: ";
    cin >> roots;
    int root = nthRoot(num, roots);
    if (root == -1)
        cout << "No integer " << roots << "th root found for " << num << endl;
    else
        cout << "The " << roots << "th root of " << num << " is: " << root << endl;
}
