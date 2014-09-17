/*
*   Given a set of distinct integers, S, return all possible subsets.
*   
*   Note:
*   Elements in a subset must be in non-descending order.
*   The solution set must not contain duplicate subsets.
*   For example,
*   If S = [1,2,3], a solution is:
*   
*   [
*     [3],
*     [1],
*     [2],
*     [1,2,3],
*     [1,3],
*     [2,3],
*     [1,2],
*     []
*   ]
**/

class Solution {
public:
    void subsets(vector<int> &S, vector<vector<int> > &R, vector<int> current, int index, int size) {
        if (current.size() == size) {
           R.push_back(current);
           return;     
        }
        
        for (int i = index; i < S.size(); i++) {
            current.push_back(S[i]);
            subsets(S, R, current, i + 1, size);
            current.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> current;
        
        //To keep numbers in order
        sort(S.begin(), S.end());
        
        //Try adding different size sets
        for (int i = 0; i <= S.size(); i++)
            subsets(S, result, current, 0, i);
        return result;           
    }
};