#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findkthElement(vector<int>& nums1, vector<int>& nums2, int target) {
        int i = 0, j = 0, count = 0;
        while (i < nums1.size() && j < nums2.size()) {
            int val;
            if (nums1[i] < nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            if (count == target) return val;
            count++;
        }

        while (i < nums1.size()) {
            if (count == target) return nums1[i];
            i++;
            count++;
        }

        while (j < nums2.size()) {
            if (count == target) return nums2[j];
            j++;
            count++;
        }

    }
};
int main(){
    Solution sol;
    vector<int> nums1={2,3,6,7,9};
    vector<int> nums2={1,4,8,10};
    cout<<sol.findkthElement(nums1,nums2,5);
}