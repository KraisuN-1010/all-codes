#include<bits/stdc++.h>
using namespace std;
class Solution {
    long long totalHours(vector<int>& piles, int perhour) {
        long long totalhours = 0;
        for (auto it : piles) {
            totalhours += (it + perhour - 1) / perhour;  // Safer than ceil
        }
        return totalhours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_hours = totalHours(piles, mid);

            if (total_hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> piles={3,6,7,11};
    int time=sol.minEatingSpeed(piles,8);
    cout<<"Least speed will be: "<<time;
}