/**
*   Given a collection of numbers, return all possible permutations.
*
*   For example,
*   [1,2,3] have the following permutations:
*   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*
**/

class Solution {
public:
    void permute(vector<int> &num, vector<vector<int> > &P, int index) {
        if (index == num.size()) {
            P.push_back(num);
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            swap(num[index], num[i]);
            permute(num, P, index + 1);
            swap(num[index], num[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > P;
        permute(num, P, 0);
        return P;
    }
};