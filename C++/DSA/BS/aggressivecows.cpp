#include<bits/stdc++.h>
using namespace std;
class Solution{
    bool canPlaceCows(vector<int> stalls,int k,int distance){
        int count_cows=1,last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=distance){
                count_cows++;
                last=stalls[i];
            }
        }
        return count_cows>=k;
    }
    public:
    int aggressiveCows(vector<int> stalls,int k){
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=(*max_element(stalls.begin(),stalls.end()))-(*min_element(stalls.begin(),stalls.end()));
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlaceCows(stalls,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low-1;
    }

};
int main(){
    Solution sol;
    vector<int> stalls={4,2,1,3,6};
    int numbers;
    numbers=sol.aggressiveCows(stalls,2);
    cout<<"Maximum of minimum distance you can put cows at is: "<<numbers; 
}