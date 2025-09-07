#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int l = low + 1;
    int r = high;

    while (l <= r) {
        while (l <= high && arr[l] <= pivot) l++;
        while (r >= low && arr[r] > pivot) r--;
        if (l < r)
            swap(arr[l], arr[r]);
    }
    swap(arr[low], arr[r]);
    return r;
}

void qS(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        qS(arr, low, part - 1);
        qS(arr, part + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    qS(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
