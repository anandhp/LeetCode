/**
*   Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
*   
*   For example,
*   Given n = 3,
*   
*   You should return the following matrix:
*   [
*    [ 1, 2, 3 ],
*    [ 8, 9, 4 ],
*    [ 7, 6, 5 ]
*   ]
*
**/

class Solution {
public:
    void fillMatrix(vector<vector<int> > &matrix, int x, int y, int r, int c, int index) {
        if (r - x <= 0 || c - y <=0)
            return;
            
        int i;
        //top row
        for (i = y; i < c; i++)
            matrix[x][i] = index++;
            
        //right column
        for (i = x + 1; i < r - 1; i++)
            matrix[i][c - 1] = index++;

        //bottom row
        for (i = c - 1; i > y; i--)
            matrix[r - 1][i] = index++;
            
        //left column
        for (i = r - 1; i > x; i--)
            matrix[i][y] = index++;
        
        fillMatrix(matrix, x + 1, y + 1, r - 1, c - 1, index);
    }
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        fillMatrix(matrix, 0, 0, n, n, 1);
        return matrix;
    }
};