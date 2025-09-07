#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9,10};
    int target=10;
    int index=binarySearch(nums,6);
    cout<<"Element is at index:"<<index;
}