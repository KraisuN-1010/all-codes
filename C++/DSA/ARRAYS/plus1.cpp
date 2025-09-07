#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={9};
    int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum*10+nums[i];
        }
        sum+=1;
        int digs=0;
        int sum2=sum;
        while(sum2>0){
            sum2/=10;
            digs++;
        }
        for(int i=digs-1;i>=0;i--){
            nums[i]=sum%10;
            sum/=10;
        }
        for(int i=0;i<nums.size();i++) cout<<nums[i];
    }