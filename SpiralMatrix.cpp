/**
*
*
*   Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*   
*   For example,
*   Given the following matrix:
*   
*   [
*    [ 1, 2, 3 ],
*    [ 4, 5, 6 ],
*    [ 7, 8, 9 ]
*   ]
*   You should return [1,2,3,6,9,8,7,4,5].
*
**/

class Solution {
public:
    void spiralOrder(vector<vector<int> > &matrix, int x, int y, int r, int c, vector<int> &order) {
        //empty matrix
        int i = 0;
        if (r - x <= 0 || c - y <= 0)
            return;
            
        //single row matrix
        if (r - x == 1) {
            for (i = y; i < c; i++)
                order.push_back(matrix[x][i]);
            return;    
        }
        
        //single column matrix
        if (c - y == 1) {
            for (i = x; i < r; i++)
                order.push_back(matrix[i][y]);
            return;        
        }

        //top row
        for (i = y; i < c; i++)
            order.push_back(matrix[x][i]);

        //right column
        for (i = x + 1; i < r; i++)
            order.push_back(matrix[i][c - 1]);
        
        //bottom row
        for (i = c - 2; i > y; i--)
            order.push_back(matrix[r - 1][i]);
            
        //left column
        for (i = r - 1; i > x; i--)
            order.push_back(matrix[i][y]);
        
        spiralOrder(matrix, x + 1, y + 1, r - 1, c - 1, order);    
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> order;
        if (matrix.size() == 0)
            return order;
        spiralOrder(matrix, 0, 0, matrix.size(), matrix.begin()->size(), order);
        return order;
    }
};