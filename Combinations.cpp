/**
*   Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
*    
*   For example,
*   If n = 4 and k = 2, a solution is:
*   
*   [
*     [2,4],
*     [3,4],
*     [2,3],
*     [1,2],
*     [1,3],
*     [1,4],
*   ]
*
**/

class Solution {
public:
    void find(int n, int k, int start, vector<vector<int> > &result, vector<int> current) {
        if (k == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            find(n, k - 1, i + 1, result, current);
            current.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> current;
        find(n, k, 1, result, current);
        return result;
    }
};