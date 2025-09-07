#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    // Constructor with data and next pointer
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};
Node* createDll(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 0; i < nums.size(); i++) {
        Node* temp = new Node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;  
    }
    return head;
}
Node* removeDuplicates(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != nullptr)
                toDelete->next->back = temp;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> nums = {1,1,2,3,3,4,5};
    Node* head = createDll(nums);
    head = removeDuplicates(head);
    printLinkedList(head);
}