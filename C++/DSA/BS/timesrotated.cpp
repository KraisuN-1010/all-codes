#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findMin(vector<int>& nums) {
            if(nums.size()==1) return nums[0];
            int low=0;
            int high=nums.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(mid<nums.size()-1){
                    if(nums[mid]>nums[mid+1]) return mid+1;
                    if(nums[mid]>nums[high]){
                        low=mid+1;
                    }
                    else{
                        high--;
                    }
                }
            }
            return 0;
        }
    };
    int main(){
        Solution sol;
        vector<int> nums={3, 4, 5, 1, 2};
        int times_rotated=sol.findMin(nums);
        cout<<times_rotated;
    }