#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    long long invCount = 0;

    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
            invCount += (mid - i + 1); 
        }
    }

    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }

    return invCount;
}

long long mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long invCount = 0;

    invCount += mergeSort(nums, left, mid);
    invCount += mergeSort(nums, mid + 1, right);
    invCount += merge(nums, left, mid, right);

    return invCount;
}

long long countInversions(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}



int main(){
    vector<int> nums;
    for(int i = 1000; i >= 1; i--) {
        nums.push_back(i);
    }

    auto start = high_resolution_clock::now();
    long long inv_cont = countInversions(nums);
    auto end = high_resolution_clock::now();

    cout << "Most inversions are: " << inv_cont << endl;
    cout << "Time taken: " << duration_cast<seconds>(end - start).count() << " seconds\n";
}
