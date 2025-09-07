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
bool searchElement(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return true; 
        temp = temp->next;
    }
    return false;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    Node* head = convertToLinkedList(nums);
    if(searchElement(head, 2)) cout << "Is inside the LL";
    else cout << "Doesnt exist";
}