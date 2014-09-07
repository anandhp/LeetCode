/**
*   Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
*
*   Each number in C may only be used once in the combination.
*   
*   Note:
*   All numbers (including target) will be positive integers.
*   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 = a2 = … = ak).
*   The solution set must not contain duplicate combinations.
*   For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
*   A solution set is: 
*   [1, 7] 
*   [1, 2, 5] 
*   [2, 6] 
*   [1, 1, 6] 
*
**/

class Solution {
public:
    void dfs(vector<vector<int> > &results, vector<int> result, int target, int index, vector<int> &num) {
        if (target == 0) {
            results.push_back(result);
            return;
        }

        if (index >= num.size())
            return;
        int prev = INT_MIN;
        for (int i = index; i < num.size(); i++) {
            if (target - num[i] >= 0 && prev != num[i]) {
                result.push_back(num[i]);
                dfs(results, result, target - num[i], i + 1, num);
                prev = num[i];
                result.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> result;
        vector<vector<int> > results;
        sort(num.begin(), num.end());
        dfs(results, result, target, 0, num);
        return results;
    }
};