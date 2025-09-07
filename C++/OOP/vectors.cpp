#include<bits/stdc++.h>
using namespace std;

class Vector{
public:
    int sizeNow;
    int capacity;
    int *arr;

    Vector(){
        sizeNow = 0;
        capacity = 0;
        arr = new int[1];
    }

    void addEle(int num) {
        if (sizeNow >= capacity) {
            capacity *= 2;
            int *arr1 = new int[capacity];
            for (int i = 0; i < sizeNow; i++) {
                arr1[i] = arr[i];
            }

            arr = arr1;
        }
        arr[sizeNow++] = num;
    }

    void print() {
        for (int i = 0; i < sizeNow; i++) cout << arr[i] << " ";
    }

    void pop() {
        if (sizeNow == 0) cout << "Not enough elements in the vector";
        sizeNow--;
    }
};

int main(){
    Vector v1 = Vector();
}