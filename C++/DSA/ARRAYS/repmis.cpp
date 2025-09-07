#include<bits/stdc++.h>
using namespace std;

//Not optimal uses O(N) space complexity

vector<int> repMis(vector<int> &nums){
    int n=nums.size();
    int sum1=n*(n+1)/2;
    int sum2=0;
    vector<int> repmis;
    unordered_map<int,int> repeat;
    for(auto num:nums){
        sum2+=num;
        repeat[num]++;
        if(repeat[num]>1){
            repmis.push_back(num);
        }
    }
    int missing=sum1-(sum2-repmis[0]);
    repmis.push_back(missing);
    return repmis;
}

//Optimal as it uses O(1) Space complexity

vector<int> repMiss(vector<int>& nums) {
    long long n = nums.size();
    long long sum = n * (n + 1) / 2;
    long long sumSq = n * (n + 1) * (2 * n + 1) / 6;
    
    long long actualSum = 0, actualSumSq = 0;
    for (int num : nums) {
        actualSum += num;
        actualSumSq += (long long)num * num;
    }
    
    long long diff = actualSum - sum; // x - y
    long long sqDiff = actualSumSq - sumSq; // x^2 - y^2 = (x - y)(x + y)
    
    long long sumXY = sqDiff / diff; // x + y

    int x = (diff + sumXY) / 2;
    int y = x - diff;

    return {x, y}; // x is repeating, y is missing
}

int main(){
    vector<int> nums={1,2,3,6,7,5,7};
    vector<int> ans=repMiss(nums);
    for(auto num:ans) cout<<num<<endl;
}