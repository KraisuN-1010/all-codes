#include <bits/stdc++.h>
using namespace std;

// Class representing a Node in a doubly linked list
class Node {
public:
    int data;       // Data value
    Node* next;     // Pointer to the next node
    Node* back;     // Pointer to the previous node

    // Constructor with optional next and back pointers
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to create a doubly linked list from a vector of integers
Node* createDll(vector<int> &nums) {
    if (nums.empty()) return nullptr;

    Node* head = new Node(nums[0]);  // First node as head
    Node* prev = head;

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

// Function to insert a new node at the head of the list
Node* insertAtHead(Node* head, int val) {
    Node* new_head = new Node(val, head, nullptr);
    if (head != nullptr)
        head->back = new_head;
    return new_head;
}

// Function to insert a new node at a specific position (1-based index)
Node* insertAtPosition(Node* head, int position, int element) {
    if (position <= 0) return head;                 // Invalid position
    if (position == 1) return insertAtHead(head, element); // Insert at head

    int counter = 1;
    Node* temp = head;

    // Traverse to the (position - 1)th node
    while (temp != nullptr && counter < position - 1) {
        temp = temp->next;
        counter++;
    }

    // If position is out of bounds
    if (temp == nullptr) return head;

    Node* nextNode = temp->next;
    Node* new_node = new Node(element, nextNode, temp);
    temp->next = new_node;
    if (nextNode != nullptr)
        nextNode->back = new_node;

    return head;
}

// Function to insert before the first occurrence of a node with a given value
Node* insertAtValue(Node* head, int value, int element) {
    bool element_found = false;
    Node* temp = head;

    // Traverse to find the node before the one with target value
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->next->data == value) {
            element_found = true;
            Node* new_node = new Node(element, temp->next, temp);
            temp->next->back = new_node;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }

    if (!element_found) {
        cout << "Element " << value << " not in linked list" << endl;
    }

    return head;
}

// ✅ Function to insert a new node at the tail of the list
Node* insertAtTail(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);  // If list is empty
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* new_node = new Node(val, nullptr, temp);
    temp->next = new_node;

    return head;
}

// Driver code
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    Node* head = createDll(nums);
    printLinkedList(head);  // Output: 1 2 3 4 5

    head = insertAtHead(head, 100);
    printLinkedList(head);  // Output: 100 1 2 3 4 5

    head = insertAtPosition(head, 5, 100);
    printLinkedList(head);  // Output: 100 1 2 3 100 4 5

    head = insertAtValue(head, 3, 67);
    printLinkedList(head);  // Output: 100 1 2 67 3 100 4 5

    head = insertAtTail(head, 999);
    printLinkedList(head);  // Output: 100 1 2 67 3 100 4 5 999

    return 0;
}
