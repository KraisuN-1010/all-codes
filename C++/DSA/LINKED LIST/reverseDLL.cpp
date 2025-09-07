#include <bits/stdc++.h>
using namespace std;

// Class definition for a node in the doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* back;     // Pointer to the previous node

    // Constructor to initialize a node
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to create a doubly linked list from a vector of integers
Node* createDll(vector<int>& nums) {
    if (nums.empty()) return nullptr;  // Edge case: empty list

    Node* head = new Node(nums[0]);    // Create the first node
    Node* prev = head;

    // Loop starts at index 1 to avoid repeating the first element
    for (int i = 1; i < nums.size(); i++) {
        Node* temp = new Node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

// Function to print the doubly linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ✅ Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* temp = nullptr;
    Node* current = head;

    // Traverse and swap next and back pointers
    while (current != nullptr) {
        temp = current->back;
        current->back = current->next;
        current->next = temp;
        current = current->back;  // Move to what was previously next
    }

    // After loop, temp points to the second last node.
    // The new head is temp->back
    if (temp != nullptr) {
        head = temp->back;
    }

    return head;
}

// Driver code
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    // Create the doubly linked list
    Node* head = createDll(nums);

    cout << "Original DLL: ";
    printLinkedList(head);

    // Reverse the list
    head = reverseDLL(head);

    cout << "Reversed DLL: ";
    printLinkedList(head);

    return 0;
}
