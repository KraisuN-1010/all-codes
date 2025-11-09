#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        vector<int> arr;

        void insert(int val) {
            arr.push_back(val);
            int index = arr.size() - 1;

            while (index > 0) {
                int parent = (index - 1) / 2;
                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else break;
            }
        }

        void deletes() {
            if (arr.empty()) {
                cout << "Nothing to delete" << endl;
                return;
            }
            arr[0] = arr.back();
            arr.pop_back();

            // Heapify down
            int index = 0;
            int size = arr.size();
            while (index < size) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;

                if (left < size && arr[largest] < arr[left]) {
                    largest = left;
                }
                if (right < size && arr[largest] < arr[right]) {
                    largest = right;
                }
                if (largest != index) {
                    swap(arr[largest], arr[index]);
                    index = largest;
                }
                else break;
            }
        }

        void heapify(int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(n, largest);
            }
        }

        void heapSort() {
            int n = arr.size();
            
            // Perform heap sort
            for (int i = n - 1; i > 0; i--) {
                // Swap root with last element
                swap(arr[0], arr[i]);
                
                // Heapify the reduced heap
                int index = 0;
                while (index < i) {
                    int left = 2 * index + 1;
                    int right = 2 * index + 2;
                    int largest = index;

                    if (left < i && arr[largest] < arr[left]) {
                        largest = left;
                    }
                    if (right < i && arr[largest] < arr[right]) {
                        largest = right;
                    }
                    if (largest != index) {
                        swap(arr[largest], arr[index]);
                        index = largest;
                    }
                    else break;
                }
            }
        }

        void print() {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Heap h;
    for (int i = 0; i < 6; i++) {
        cout << "Enter element: ";
        int num;
        cin >> num;
        h.insert(num);
    }
    
    cout << "Original Heap: ";
    h.print();
    
    cout << "After deleting root: ";
    h.deletes();
    h.print();
    
    // Rebuild heap for sorting demo
    cout << "\nRebuilding heap for sorting..." << endl;
    Heap h2;
    int elements[] = {50, 30, 70, 10, 20, 60};
    for (int i = 0; i < 6; i++) {
        h2.insert(elements[i]);
    }
    
    cout << "Before HeapSort: ";
    h2.print();
    
    h2.heapSort();
    
    cout << "After HeapSort (ascending): ";
    h2.print();
    
    return 0;
}