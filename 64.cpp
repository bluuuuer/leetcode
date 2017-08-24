/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > values(m, vector<int>(n, INT_MAX));    
        values[m - 1][n - 1] = grid[m - 1][n - 1];
        
        for (int curSum = m + n - 2; curSum > 0; curSum --) {
            for (int i = m - 1; i >= 0; i --) {
                for (int j = n - 1; j >= 0; j --) {
                    if (i + j == curSum) {
                        // left
                        if (i > 0) {
                            values[i - 1][j] = min(values[i][j] + grid[i - 1][j], values[i - 1][j]);
                        }
                        // up
                        if (j > 0) {
                            values[i][j - 1] = min(values[i][j] + grid[i][j - 1], values[i][j - 1]);
                        }
                    }
                }
            }
        }
        
        return values[0][0];
    }
};
