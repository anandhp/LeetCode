/**
*   Given a collection of integers that might contain duplicates, S, return all possible subsets.
*   
*   Note:
*   Elements in a subset must be in non-descending order.
*   The solution set must not contain duplicate subsets.
*   For example,
*   If S = [1,2,2], a solution is:
*   
*   [
*     [2],
*     [1],
*     [1,2,2],
*     [2,2],
*     [1,2],
*     []
*   ]
*   
*
**/
class Solution {
public:
    void subsetsWithDup(vector<int> &S, vector<vector<int> > &R, vector<int> current, int index, int size) {
        if (current.size() == size) {
           R.push_back(current);
           return;     
        }

        int prev = INT_MIN;
        for (int i = index; i < S.size(); i++) {
            if (prev != S[i]) {
                current.push_back(S[i]);
                subsetsWithDup(S, R, current, i + 1, size);
                current.pop_back();
            }
            prev = S[i];
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> current;
        
        sort(S.begin(), S.end());
        
        for (int i = 0; i <= S.size(); i++)
            subsetsWithDup(S, result, current, 0, i);
        return result;           
    }
};