/**
*   Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
*   
*   The same repeated number may be chosen from C unlimited number of times.
*   
*   Note:
*   All numbers (including target) will be positive integers.
*   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 = a2 = … = ak).
*   The solution set must not contain duplicate combinations.
*   For example, given candidate set 2,3,6,7 and target 7, 
*   A solution set is: 
*   [7] 
*   [2, 2, 3] 
*
**/
class Solution {
public:
    void dfs(vector<vector<int> > &results, vector<int> result, int target, int index, vector<int> &candidates) {
        if (index > candidates.size())
            return;
        
        if (target == 0) {
            results.push_back(result);
            return;
        }
        
        for (int i = index;  i < candidates.size(); i++) {
            if(target - candidates[i] >= 0) {
                result.push_back(candidates[i]);
                dfs(results, result, target - candidates[i], i, candidates);
                result.pop_back();
            }
        }       
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> result;
        vector<vector<int> > results;
        sort(candidates.begin(), candidates.end());
        dfs(results, result, target, 0, candidates);
        return results;
    }
};