/**
*   A robot is located at the top-left corner of a m x n grid 
*   (marked '$' in the diagram below).
*
*   The robot can only move either down or right at any point in time. 
*   The robot is trying to reach the bottom-right corner of the 
*   grid (marked '#' in the diagram below).
*
*   How many possible unique paths are there?
*    ---------------
*   | $ |   |   |   |
*    ---------------
*   |   |   |   |   |
*    ---------------
*   |   |   |   | # |
*    ---------------
*
*   Above is a 3 x 4 grid. How many possible unique paths are there?
*
*   Note: m and n will be at most 100.
*
*
**/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0)
            return 0;
            
        vector<vector<int> > M(m, vector<int>(n, 0));
        M[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0)
                    M[i][j] = M[i - 1][j] + M[i][j - 1];
                else if (i > 0)
                    M[i][j] = M[i - 1][j];
                else if (j > 0)    
                    M[i][j] = M[i][j - 1];
            }
        }
        
        return M[m - 1][n - 1];
    }
};