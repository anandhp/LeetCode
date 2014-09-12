/**
*   Given a string s, partition s such that every substring of the partition is a palindrome.
*
*   Return all possible palindrome partitioning of s.
*
*   For example, given s = "aab",
*   Return
*    
*     [
*       ["aa","b"],
*       ["a","a","b"]
*     ]
*     
*
**/

class Solution {
public:
    bool valid(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
    }
    
    void findPal(string &s, vector<vector<string> > &pals, vector<string> &current, int index) {
        if (index >= s.length()) {
            if (current.size() > 0)
                pals.push_back(current);
            return;
        }
        
        for (int i = 0; i + index < s.length(); i++) {
            string sub = s.substr(index, i + 1);
            if (valid(s, index, index + i)) {
                current.push_back(sub);
                findPal(s, pals, current, index + i + 1);
                current.pop_back();
            }
        }
    }    

    vector<vector<string> > partition(string s) {
        vector<vector<string> > palindromes;
        vector<string> current;
        findPal(s, palindromes, current, 0);
        return palindromes;
    }
};