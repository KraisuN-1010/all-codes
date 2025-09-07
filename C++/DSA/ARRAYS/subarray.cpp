#include<bits/stdc++.h>
using namespace std;
int leng(vector<int> &nums, int k) {
    int i = 0, j = 0, sum = 0, max_len = 0;

    for(int j=0;j < nums.size();j++) {
        sum += nums[j];
        while (sum > k && i <= j) {
            sum -= nums[i];
            i++;
        }
        if (sum == k) {
            max_len = max(max_len, j - i + 1);
        }
    }

    return max_len;
}

int main(){
    vector<int> nums={1,2,3};
    int max=leng(nums,3);
    cout<<"Largest subarray is of length:"<<max;
}