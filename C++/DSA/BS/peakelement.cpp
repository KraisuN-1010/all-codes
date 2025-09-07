#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findMaxRowIndex(vector<vector<int>>& matrix, int n, int m, int col) {
        int max_value = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (matrix[i][col] > max_value) {
                max_value = matrix[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakIndex(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int max_row_index = findMaxRowIndex(matrix, n, m, mid);

            int left = (mid - 1 >= 0) ? matrix[max_row_index][mid - 1] : -1;
            int right = (mid + 1 < m) ? matrix[max_row_index][mid + 1] : -1;

            if (matrix[max_row_index][mid] > left && matrix[max_row_index][mid] > right) {
                return {max_row_index, mid};
            } else if (matrix[max_row_index][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    vector<int> peak = sol.findPeakIndex(matrix);
    cout << "Peak found at: [" << peak[0] << ", " << peak[1] << "]\n";
    return 0;
}
