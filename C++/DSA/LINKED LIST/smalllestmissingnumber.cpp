#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace negative numbers and zeros with n + 1
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0){
                nums[i] = n + 1;
            }
        }

        // Step 2: Use index marking to record presence of numbers in [1, n]
        for(int i = 0; i < n; i++){
            int val = abs(nums[i]);
            if(val >= 1 && val <= n){
                if(nums[val - 1] > 0){
                    nums[val - 1] *= -1;
                }
            }
        }

        // Step 3: Find the first positive index
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums= {0,1,3,9,-2,1};
    int smallestMissing = sol.firstMissingPositive(nums);
    cout << "smallest missing positive integar is : " << smallestMissing;
}