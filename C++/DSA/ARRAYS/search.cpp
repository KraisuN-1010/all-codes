#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int linearSearch(vector<int>& nums, int target) {
    int ind=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=target){
            ind++;
        }
    }
    return ind;
}
};

int main(){
    Solution sol;
    vector<int> nums={2,3,4,5,6,7,8,9};
    int index = sol.linearSearch(nums, 8);
}