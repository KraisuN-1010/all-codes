#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return k + high + 1;
        }
    };
int main(){
    vector<int> nums={2,3,4,7,11};
    int k=5;
    Solution sol;
    int kth_missing_number=sol.findKthPositive(nums,k);
    cout<<k<<"th missing number is: "<<kth_missing_number;
}