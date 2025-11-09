#include <bits/stdc++.h>
using namespace std;

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size(); 

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

     for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Heapified array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}