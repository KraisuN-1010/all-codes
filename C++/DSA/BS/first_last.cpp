#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> binarySearch(vector<int> &nums,int target){
    if(nums.empty()) return {-1,-1};
    int low=0;
    int high=nums.size()-1;
    vector<int> occurences;
    int first=-1;
    int last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            first=mid;
            high=mid-1;
        } 
        else if(nums[mid]>=target) high=mid-1;
        else low=mid+1;
    }
    low=0;
    high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            last=mid;
            low=mid+1;
        } 
        else if(nums[mid]>=target) high=mid-1;
        else low=mid+1;
    }
    occurences.push_back(first);
    occurences.push_back(last);
    return occurences;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> occurences=binarySearch(nums,target);
        return occurences;
    }
};
int main(){
    
}