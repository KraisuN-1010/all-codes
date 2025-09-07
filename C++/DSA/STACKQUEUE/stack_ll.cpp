#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value, Node* nextNode) : data(value), next(nextNode) {}
    Node(int value) : data(value), next(nullptr) {}
};

class StackImpl {
private:
    Node* top;
    int stackSize = 0;
    
public:
    StackImpl() : top(nullptr), stackSize(0) {}
    
    void push(int num) {
        Node* newNode = new Node(num, top);
        top = newNode;
        stackSize++;
        cout << "Pushed: " << num << endl;
    }
    
    int top_element() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        stackSize--;
        cout << "Popped: " << poppedValue << endl;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    int size() {
        return stackSize;
    }
};