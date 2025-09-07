#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value, Node* nextNode) : data(value), next(nextNode) {}
    Node(int value) : data(value), next(nullptr) {}
};

class QueueImpl {
private:
    Node* front;
    Node* rear;
    int queueSize;
    
public:
    QueueImpl() : front(nullptr), rear(nullptr), queueSize(0) {}
    
    void enqueue(int num) {
        Node* newNode = new Node(num);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        queueSize++;
    }
    
    int front_element() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        queueSize--;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    int size() {
        return queueSize;
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
    cout << "Queue size: " << myQueue.size() << endl;                     // 2
    
    return 0;
}