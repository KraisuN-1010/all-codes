#include<bits/stdc++.h>
using namespace std;
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;
        if (nums[n - 1] > nums[0])
            count++;
        return count <= 1;
    }
int main(){
    vector<int> nums={3,4,5,1,2};
    int size=sizeof(nums)/sizeof(nums[0]);
    bool rotated=check(nums);
    if(rotated) cout<<"true";
    else cout<<"false";
}