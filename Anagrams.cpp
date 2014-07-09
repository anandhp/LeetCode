/**
    Given an array of strings, return all groups of strings that are anagrams.
    
    Note: All inputs will be in lower-case.

**/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1)
            return res;

        map<string, int> anagramMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagramMap.find(s) == anagramMap.end())
                anagramMap.insert(make_pair(s, i));
            else {
                if (anagramMap[s] >= 0) {
                    res.push_back(strs[anagramMap[s]]);
                    anagramMap[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};