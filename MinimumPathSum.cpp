/**
*   Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
*   which minimizes the sum of all numbers along its path.
*
*   Note: You can only move either down or right at any point in time.
*
**/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid.begin()->size();
        vector<vector<int> > sum(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    sum[0][0] = grid[0][0];
                else {
                    if (i > 0 && j > 0)
                        sum[i][j] = min(sum[i][j], min(sum[i - 1][j], sum[i][j - 1]));
                    else if (i > 0)
                        sum[i][j] = min(sum[i][j], sum[i - 1][j]);
                    else
                        sum[i][j] = min(sum[i][j], sum[i][j - 1]);
                    sum[i][j] += + grid[i][j];
                }
            }
        }
        return sum[m - 1][n - 1];
    }
};