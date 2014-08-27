/**
*
*   Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
*   
*   For example, given the following triangle
*   [
*        [2],
*       [3,4],
*      [6,5,7],
*     [4,1,8,3]
*   ]
*   The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*   
*   Note:
*   Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*   
**/

class Solution {
public:
    int minimumTotalEx(vector<vector<int> > &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        
        return triangle[0][0];
    }
    
    int minimumTotal(vector<vector<int> > &triangle) {
        int k;
        int sum = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            sum = INT_MAX;
            for (int j = i; j >=0; j--) {
                if (j == 0)
                    k = 0;
                else if (j == i)
                    k = j - 1;
                else
                    k = triangle[i - 1][j - 1] < triangle[i - 1][j] ? j - 1 : j; 
                    
                triangle[i][j] += triangle[i - 1][k];
                sum = min(sum, triangle[i][j]);
            }
        }
        return sum;
    }    
};
