/**

    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,
    
    Consider the following matrix:
    
    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.

**/
class Solution {
public:
    
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        while(low <= high) {
            int middle = (high + low) / 2;
            vector<int>& row = matrix[middle];
            int l = 0, h = row.size() - 1;
            if (target < row[l]) {
                high = middle - 1;
            }
            else if (target > row[h])
                low = middle + 1;
            else {
                while (l <= h) {
                    int mid = (l + h) / 2;
                    if (row[mid] == target)
                        return true;
                    else if (row[mid] > target)
                        h = mid - 1;
                    else 
                        l = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};