#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findPath(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<string> solution;
        string result;

        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return solution;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        backtrack(grid, visited, 0, 0, result, solution, n);
        return solution;
    }

    void backtrack(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, string &path, vector<string> &res, int n) {
        // If destination is reached
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        // Direction vectors: D, L, R, U
        string dir = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            // Check bounds, cell is open and not visited
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1 && visited[ni][nj] == 0) {
                visited[i][j] = 1;
                path.push_back(dir[k]);

                backtrack(grid, visited, ni, nj, path, res, n);

                path.pop_back();
                visited[i][j] = 0;
            }
        }
    }
};
int main(){

}
