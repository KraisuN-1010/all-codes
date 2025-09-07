#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subsets(vector<int>& nums, int target) {
        int sumCount = 0;
        vector<int> current;
        backtrack(nums, 0, current, target, sumCount);
        return sumCount;
    }
    void backtrack(vector<int>& nums, int index, vector<int>& current, int target, int& sumCount) {
        int sum = accumulate(current.begin(), current.end(), 0);
        if (sum == target) {
            sumCount++;
        }
        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, target, sumCount);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1, 1};
    int sumCount = sol.subsets(nums, 2);
    cout << "Sum count is: " << sumCount << endl;
}
