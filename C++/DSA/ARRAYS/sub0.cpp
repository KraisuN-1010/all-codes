#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int leng(vector<int> &nums, int k) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0, max_len = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) {
                max_len = i + 1;
            }
            if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
                max_len = max(max_len, i - prefixSumMap[sum - k]);
            }
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }
        
        return max_len;
    }
    
    };
int main(){
    Solution sol;
    vector<int> arr={-1,1,5,-2,3};
    int result=sol.leng(arr,3);
    cout<<result;
}
     