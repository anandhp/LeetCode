/**
*   Given numRows, generate the first numRows of Pascal's triangle.
*
*   For example, given numRows = 5,
*   Return
*
*   [
*        [1],
*       [1,1],
*      [1,2,1],
*     [1,3,3,1],
*    [1,4,6,4,1]
*   ]
*
**/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle(numRows);
        for (int i = 0, j ; i < numRows; i++) {
            
            triangle[i] = vector<int>(i + 1);
            triangle[i][0] = 1;
    
            for (j = 1; j < i; j++)
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                
            triangle[i][i] = 1;
        
        }
    
        return triangle;        
    }
};