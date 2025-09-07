#include<bits/stdc++.h>
using namespace std;

class QueueImpl {
private:
    static const int MAX_SIZE = 10;
    int front, rear;
    int queue[MAX_SIZE];
    
public:
    QueueImpl() : front(0), rear(-1) {}
    
    void enqueue(int num) {
        if (rear >= MAX_SIZE - 1) {
            cout << "Queue overflow!" << endl;
            return;
        }
        queue[++rear] = num;
    }
    
    int front_element() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        front++;
    }
    
    bool isEmpty() {
        return front > rear;
    }
    
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    QueueImpl myQueue;
    
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    
    cout << "Front element: " << myQueue.front_element() << endl;  // 10
    cout << "Queue size: " << myQueue.size() << endl;             // 3
    
    myQueue.dequeue();
    cout << "After dequeue, front: " << myQueue.front_element() << endl;  // 20
    
    return 0;
}