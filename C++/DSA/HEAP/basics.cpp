#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size = 0;

        void insert(int val) {
            size++;
            int index = size;
            arr[index] = val;

            while (index > 1) {
                int parent = index / 2;
                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;  // Move up the tree
                }
                else break;  // Heap property satisfied
            }
        }

        void deletes() {
            if (size == 0) {
                cout << "Nothing to delete";
                return;
            }
            arr[1] = arr[size];
            size--;

            // Heapify down
            int index = 1;
            while (index <= size) {
                int left = 2 * index;
                int right = 2 * index + 1;
                int largest = index;

                if (left <= size && arr[largest] < arr[left]) {
                    largest = left;
                }
                if (right <= size && arr[largest] < arr[right]) {
                    largest = right;
                }
                if (largest != index) {
                    swap(arr[largest], arr[index]);
                    index = largest;  // Move down the tree
                }
                else break;  // Heap property satisfied
            }

        }

        void print() {
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Heap h;
    for (int i = 0; i < 6; i++) {
        cout << "Enter element:";
        int num;
        cin >> num;
        h.insert(num);
    }
    
    h.print();
    h.deletes();
    h.print();
    return 0;
}