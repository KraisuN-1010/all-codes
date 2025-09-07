#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber (vector<int> &nums) {
    int counter = 0;

    for (int i = 0; i < nums.size(); i++) {
        counter ^= nums[i];
    }

    return {counter, 0};
}

int main(){
    vector<int> nums = {-1, 0};
    vector<int> sinlgleNumbers = singleNumber(nums);
    for (auto ans : sinlgleNumbers) cout << ans << " ";
}