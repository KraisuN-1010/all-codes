#include<bits/stdc++.h>
using namespace std;
vector<int> leaders(vector<int>& nums) {
    vector<int> lead;
    int n=nums.size();
    int max=nums[n-1];
    lead.push_back(nums[n-1]);
    for(int i=n-1;i>=0;i--){
        if(nums[i]>max){
            max=nums[i];
            lead.push_back(max);
        }
    }
    reverse(lead.begin(),lead.end());
    return lead;
}
int main(){
    vector<int> nums={-3,4,5,1,-4,-5};
    vector<int> leader=leaders(nums);
    for(int num:leader) cout<<num<<endl;
}