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
vector<vector<int>> pairsSumTarget(Node* head, int target){
    vector<vector<int>> pairs;
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2->next != nullptr){
        temp2 = temp2->next;
    }
    while(temp1 != temp2){
        int sum = temp1->data + temp2->data;
        if(sum == target){
            pairs.push_back({temp1->data,temp2->data});
            temp1 = temp1->next;
            temp2 = temp2->back;
        }
        else if(sum > target) {
            temp2 = temp2->back;
        }
        else {
            temp1 = temp1->next;
        }
    }
    return pairs;
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    Node* head = createDll(nums);
    vector<vector<int>> pairsSum = pairsSumTarget(head, 5);
    
}