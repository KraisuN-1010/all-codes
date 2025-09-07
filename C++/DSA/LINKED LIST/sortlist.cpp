#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // Find the middle node
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = list1 ? list1 : list2;
        return dummy->next;
    }

public:
    // Sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return mergeTwoSortedLinkedLists(left, right);
    }
};

// Print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the sorting
int main() {
    // Example list: 4 -> 2 -> 1 -> 3
    ListNode* node4 = new ListNode(3);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(4, node2);

    Solution sol;
    ListNode* sortedHead = sol.sortList(node1);

    printList(sortedHead);  // Expected output: 1 2 3 4
    return 0;
}
