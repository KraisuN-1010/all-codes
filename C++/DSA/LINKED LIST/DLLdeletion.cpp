#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node class
class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor to initialize a node
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Creates a doubly linked list from a vector
Node* createDll(vector<int> &nums) {
    if (nums.empty()) return nullptr;

    Node* head = new Node(nums[0]); // First node (head)
    Node* prev = head;

    // Add remaining nodes
    for (int i = 1; i < nums.size(); i++) {
        Node* temp = new Node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

// Deletes the head node and returns new head
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;        // Empty list
    if (head->next == nullptr) {                // Single node
        delete head;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->back = nullptr;                       // Remove backward link
    temp->next = nullptr;                       // Disconnect node
    delete temp;                                // Free memory

    return head;
}

// Prints the doubly linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    Node* head = createDll(nums);   // Create list
    head = deleteHead(head);        // Delete head
    printLinkedList(head);          // Print updated
}