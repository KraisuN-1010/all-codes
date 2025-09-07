#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums,int target,int low,int high){
    if(low>high) return -1;
    int mid=(high+low)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target) return binarySearch(nums,target,low,mid-1);
    return binarySearch(nums,target,mid+1,high);
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9,10};
    int target=10;
    int index=binarySearch(nums,target,0,nums.size()-1);
    cout<<"Element is at index:"<<index;
}