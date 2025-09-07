#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1,1,1,1,1,2,3,4,3,2,5};
    sort(nums.begin(),nums.end());
    int k=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nums[k]=nums[i];
            k++;
        }
    }
    for(int i=0;i<k;i++) cout<<nums[i]<<endl;
}