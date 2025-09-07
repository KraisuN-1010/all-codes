#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> sums;
    int left=0;
    int right=nums.size()-1;
    while(left<nums.size()){
        if(nums[right]==target-nums[left]){
            sums.push_back(left);
            sums.push_back(right);
            break;
        }
            else if(nums[right]!=target-nums[left]){
                right--;
            }
            if(left==right){
                right=nums.size()-1;
                left++;
            }
    }
   return sums;
}
int main(){
    vector<int> sums={2,11,7,15};
    vector<int> two=twoSum(sums,9);
    for(int i=0;i<2;i++) cout<<two[i]<<endl;
}