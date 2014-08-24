/**
*   Given an index k, return the kth row of the Pascal's triangle.
*
*   For example, given k = 3,
*   Return [1,3,3,1].
*
*   Note:
*   Could you optimize your algorithm to use only O(k) extra space?
*
**/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex  = rowIndex + 1;
        vector<int> row(rowIndex);
    
        for (int i = 0, j; i < rowIndex; i++) {
            vector<int> last = row; 

            row[0] = 1;
    
            for (j = 1; j < i; j++)
                row[j] = last[j - 1] + last[j];
                
            row[i] = 1;
        }
    
        return row;        
    }
};