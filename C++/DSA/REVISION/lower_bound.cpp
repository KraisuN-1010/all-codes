#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums,int target){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    vector<int> nums={1,2,2,3};
    int target=2;
    int answer=lowerBound(nums,target);
    cout<<"Lower bound of "<<target<<" is at index = "<<answer;
}