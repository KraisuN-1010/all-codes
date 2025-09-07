#include<bits/stdc++.h>
using namespace std;
vector <int> preSum(vector<int> &nums){
    int sum=0;
    vector<int> pref;
    pref.push_back(0);
    for(int i=1;i<nums.size()+1;i++){
        pref.push_back(pref[i-1]+nums[i-1]);
    }
    return pref;
}
int main(){
    vector<int> nums={1,2,3,4,5};
    vector<int> pref=preSum(nums);
    for(auto num:pref) cout<<num<<endl;
}