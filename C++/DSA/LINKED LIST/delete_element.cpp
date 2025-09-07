#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert vector to linked list
Node* convertToLinkedList(vector<int>& nums) {
    if (nums.empty()) return NULL;

    Node* head = new Node(nums[0]);
    Node* mover = head;

    for (int i = 1; i < nums.size(); i++) {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Delete head node
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head->next;
    delete head;
    return temp;
}

// Delete tail node
Node* deleteTail(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

// Delete node at a given position (1-based index)
Node* deleteAtPosition(Node* head, int Position) {
    if (head == NULL) return NULL;

    // If deleting the head
    if (Position == 1) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* temp = head;

    // Traverse to the node just before the target
    for (int i = 1; temp != NULL && i < Position - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid or next node doesn't exist
    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    Node* delete_node = temp->next;
    temp->next = temp->next->next;
    delete delete_node;

    return head;
}

// Delete the first node with a specific value
Node* deleteElement(Node* head, int value) {
    if (head == NULL) return NULL;

    // If head needs to be deleted
    if (head->data == value) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* temp = head;

    // Traverse until just before the node with matching value
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    // If the value was not found
    if (temp->next == NULL) {
        return head;
    }

    Node* delete_node = temp->next;
    temp->next = temp->next->next;
    delete delete_node;

    return head;
}

// Print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertToLinkedList(nums);

    // Delete the node with value 2
    head = deleteElement(head, 2);

    // Print the modified list
    printLinkedList(head);

    return 0;
}
