#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convertToLinkedList(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* sortBy012(Node* head) {
    Node* zeroDummy = new Node(-1);
    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);
    Node* zero = zeroDummy;
    Node* one = oneDummy;
    Node* two = twoDummy;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    // Connect the three lists
    zero->next = oneDummy->next ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr;
    head = zeroDummy->next;
    // Free the dummy nodes
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> nums = {0,1,1,2,0,0,2,1,1};
    Node* head = convertToLinkedList(nums);
    head = sortBy012(head);
    printLinkedList(head);
}