/**
*   Given a string s and a dictionary of words dict, determine if s can be segmented 
*   into a space-separated sequence of one or more dictionary words.
*   
*   For example, given
*   s = "leetcode",
*   dict = ["leet", "code"].
*   
*   Return true because "leetcode" can be segmented as "leet code".
*
**/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.size() <= 0)
            return false;
        
        vector<bool> seg(s.length() + 1, false);
        seg[0] = true;
        
        for (int i = 0; i < s.length(); i++) {
            if (!seg[i])
                continue;
                
            unordered_set<string>::iterator it;
            for (it = dict.begin(); it != dict.end(); ++it)
                if (s.substr(i, (*it).length()) == *it)
                    seg[i + (*it).length()] = true;
        }
        return seg[s.length()];
    }

};