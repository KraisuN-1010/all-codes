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
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* addOneToLL(Node* head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    if(temp->data < 9) temp->data += 1;
    else{
        temp = head;
    }
    return head;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    Node* head = convertToLinkedList(nums);
    head = addOneToLL(head);
    printLinkedList(head);
}