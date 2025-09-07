#include <iostream>
#include <vector>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Converts a vector of integers to a singly linked list
Node* convertToLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* mover = head;

    for (int i = 1; i < nums.size(); i++) {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Inserts a new node at the head of the linked list
Node* headInsert(Node* head, int element) {
    Node* temp = new Node(element, head);
    return temp;
}

// Inserts a new node at the end (tail) of the linked list
Node* tailInsert(Node* head, int element) {
    if (head == nullptr) return new Node(element);
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node(element);
    return head;
}

// Inserts a new node at the k-th position (1-based index)
Node* insertAtK(Node* head, int element, int position) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return head;
    }

    if (position == 1) {
        return new Node(element, head);
    }

    Node* temp = head;
    int counter = 1;

    while (temp != nullptr && counter < position - 1) {
        temp = temp->next;
        counter++;
    }

    if (temp == nullptr) {
        cout << "Position " << position << " is out of bounds.\n";
        return head;
    }

    Node* new_node = new Node(element, temp->next);
    temp->next = new_node;
    return head;
}

// Inserts a new node before the first occurrence of a node with a specific value
Node* insertAtValue(Node* head, int element, int value) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->data == value) {
            Node* new_node = new Node(element, temp->next);
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
    }

    cout << "Value " << value << " not found in list.\n";
    return head;
}

// Utility function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the linked list operations
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // Create initial linked list
    Node* head = convertToLinkedList(nums);
    cout << "Initial Linked List: ";
    printLinkedList(head);

    // Insert at head
    head = headInsert(head, 100);
    cout << "After inserting 100 at head: ";
    printLinkedList(head);

    // Insert at tail
    head = tailInsert(head, 200);
    cout << "After inserting 200 at tail: ";
    printLinkedList(head);

    // Insert at position 3
    head = insertAtK(head, 300, 3);
    cout << "After inserting 300 at position 3: ";
    printLinkedList(head);

    // Insert before first occurrence of 4
    head = insertAtValue(head, 400, 4);
    cout << "After inserting 400 before value 4: ";
    printLinkedList(head);

    return 0;
}
