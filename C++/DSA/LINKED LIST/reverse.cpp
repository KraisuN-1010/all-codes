#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
   ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;              
            prev = curr;                     
            curr = nextTemp;                 
        }
        return prev; 
    }
    ListNode* recursiveReverse(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = recursiveReverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
ListNode* convertToLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
   ListNode* head = new ListNode(nums[0]);
   ListNode* mover = head;

    for (int i = 1; i < nums.size(); i++) {
       ListNode* temp = new ListNode(nums[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> LL = {1,2,3,4,5};
    ListNode* head = convertToLinkedList(LL);
    Solution sol;
    printLinkedList(head);
    head = sol.reverseList(head);
    printLinkedList(head);
    head = sol.recursiveReverse(head);
    printLinkedList(head);
}