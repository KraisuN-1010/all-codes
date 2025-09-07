#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.empty()) return {};
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
            int j = 0;
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] <= merged[j][1]) {
                    merged[j][1] = max(merged[j][1], intervals[i][1]);
                } else {
                    merged.push_back(intervals[i]);
                    j++;
                }
            }
    
            return merged;
        }
    };
int main(){
    Solution sol;
    vector<vector<int>> intervals={{1,2},{2,6},{3,6},{10,90}};
    vector<vector<int>> solved=sol.merge(intervals);
    for(auto it:solved) cout<<"["<<it[0]<<","<<it[1]<<"]"<<endl;
}    