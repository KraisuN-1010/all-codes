#include<bits/stdc++.h>
using namespace std;
vector<int> binarySearch(vector<int> &nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans1;
    int ans2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target) {
            ans1=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    low=0;
    high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=target) {
            ans2=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    vector<int> floorceil={nums[ans1],nums[ans2]};
    return floorceil;
    
}
int main(){
    vector<int> nums={3, 4, 4, 7, 8, 10};
    int target=8;
    vector<int> floorceil=binarySearch(nums,target);
    cout<<"["<<floorceil[0]<<","<<floorceil[1]<<"]";
}