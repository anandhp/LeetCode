/**
*   Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*
*   For example,
*   [1,1,2] have the following unique permutations:
*   [1,1,2], [1,2,1], and [2,1,1].
*
**/

class Solution {
public:
    bool duplicate(int i, int index, vector<int> &num) {
        for (int j = index; j < i; j++) {
            if (num[j] == num[i])
                return true;
        }
        return false;
    }
    void permuteUnique(vector<int> &num, set<vector<int> > &P, int index) {
        if (index == num.size()) {
            P.insert(num);
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            if (duplicate(i, index, num))
                continue;
            swap(num[index], num[i]);
            permuteUnique(num, P, index + 1);
            swap(num[index], num[i]);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int> > P;
        vector<vector<int> > result;

        permuteUnique(num, P, 0);

        for (set<vector<int> >::iterator it = P.begin(); it != P.end(); ++it)
            result.push_back(*it);
        return result;    
    }
};