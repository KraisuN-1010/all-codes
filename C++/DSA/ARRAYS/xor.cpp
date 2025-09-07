#include<bits/stdc++.h>
using namespace std;
int numSubs(vector<int> &nums,int target){
    unordered_map<int, int> freq;
    int count = 0, xorr = 0;
    for (int i = 0; i < nums.size(); i++) {
        xorr ^= nums[i];

        if (xorr == target)
            count++;

        if (freq.find(xorr ^ target) != freq.end())
            count += freq[xorr ^ target];

        freq[xorr]++;
    }
    return count;
}
int main(){
    vector<int> nums={4,2,2,6,4};
    int subarays=numSubs(nums,6);
    cout<<subarays;
}