/**
*   Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
*   Find all unique quadruplets in the array which gives the sum of target.
*
*   Note:
*   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a = b = c = d)
*   The solution set must not contain duplicate quadruplets.
*   For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
*   
*   A solution set is:
*   (-1,  0, 0, 1)
*   (-2, -1, 1, 2)
*   (-2,  0, 0, 2)
*   
**/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int size = num.size();
        vector<vector<int> > quads;

        if (size < 4)  
            return quads;

        multimap<int, pair<int, int> > pairSumMap;
        multimap<int, pair<int, int> >::iterator mmit, it;
        set<vector<int> > quadSet;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                pairSumMap.insert(make_pair(num[i] + num[j], make_pair(i, j)));
            }
        }
        
        for (mmit = pairSumMap.begin(); mmit != pairSumMap.end(); ++mmit) {
            int diff = target - mmit->first;
            
            if (pairSumMap.find(diff) == pairSumMap.end())
                continue;
                
            pair<int, int> p = mmit->second;
            pair<multimap<int, pair<int, int> >::iterator, multimap<int, pair<int, int> >::iterator > range;
            range = pairSumMap.equal_range(diff);
            
            for (it = range.first; it != range.second; it++) {
                if (p.first != it->second.first
                    && p.second != it->second.first
                    && p.first != it->second.second
                    && p.second != it->second.second) {
                        vector<int> quad;
                        quad.push_back(num[p.first]);
                        quad.push_back(num[p.second]);
                        quad.push_back(num[it->second.first]);
                        quad.push_back(num[it->second.second]);
                        sort(quad.begin(), quad.end());
                        quadSet.insert(quad);
                }
            }
        }

        for (set<vector<int> >::iterator sit = quadSet.begin(); sit != quadSet.end(); ++sit)
            quads.push_back(*sit);

        return quads;
    }
};