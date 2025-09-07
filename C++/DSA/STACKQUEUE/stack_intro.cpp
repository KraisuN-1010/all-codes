#include<bits/stdc++.h>
using namespace std;

class StackImpl {
private:
    static const int MAX_SIZE = 10;
    int top;
    int st[MAX_SIZE];
    
public:
    StackImpl() : top(-1) {}
    
    void push(int num) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        st[++top] = num;
    }
    
    int top_element() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return st[top];
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        top--;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int size() {
        return top + 1;
    }
};

int main() {
    StackImpl stack;
    
    // Basic operations
    stack.push(5);
    stack.push(15);
    stack.push(25);
    
    cout << "Current stack size: " << stack.size() << endl;
    cout << "Top element: " << stack.top_element() << endl;
    
    stack.pop();
    cout << "After pop, top element: " << stack.top_element() << endl;
    
    return 0;
}