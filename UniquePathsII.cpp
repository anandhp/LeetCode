/**
*   Follow up for "Unique Paths":
*
*   Now consider if some obstacles are added to the grids. How many unique paths would there be?
*       
*   An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*   
*   For example,
*   There is one obstacle in the middle of a 3x3 grid as illustrated below.
*   
*   [
*     [0,0,0],
*     [0,1,0],
*     [0,0,0]
*   ]
*   
*   The total number of unique paths is 2.
*       
*   Note: m and n will be at most 100.
*
**/

class Solution {
public:
    inline int gridVal(vector<vector<int> > &grid, vector<vector<int> > &M, int i, int j) {
        return grid[i][j] ? 0 : M[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.begin()->size();
        
        if ((m == 0 && n == 0) || obstacleGrid[0][0])
            return 0;
            
        vector<vector<int> > M(m, vector<int>(n, 0));
        M[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j])
                    continue;
                    
                if (i > 0 && j > 0)
                    M[i][j] = gridVal(obstacleGrid, M, i - 1, j) + gridVal(obstacleGrid, M, i, j - 1);
                else if (i > 0)
                    M[i][j] = gridVal(obstacleGrid, M, i - 1, j);
                else if (j > 0)    
                    M[i][j] = gridVal(obstacleGrid, M, i, j - 1);
            }
        }
        
        return M[m - 1][n - 1];        
    }
};