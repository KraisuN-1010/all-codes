#include <bits/stdc++.h>
using namespace std;

vector<int> binarySearch(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int low = 0, high = nums.size() - 1;
    int first = -1, last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return {first, last};
}

int searchRange(vector<int>& nums, int target) {
    vector<int> occurences = binarySearch(nums, target);
    if (occurences[0] == -1 || occurences[1] == -1)
        return 0; 
    return occurences[1] - occurences[0] + 1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 10, 10, 10};
    int target = 10;
    cout << searchRange(nums, target); 
}
