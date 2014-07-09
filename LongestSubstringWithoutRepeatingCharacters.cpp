/**
    Given a string, find the length of the longest substring without repeating characters. 
    
    For example, 
    
    The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
    For "bbbbb" the longest substring is "b", with the length of 1.
**/

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
     int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
            
        int maxLen = 0, curPos = 0;
        vector<bool> index(256);
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!index[c - 'A']) {
                index[c - 'A'] = true;
                maxLen = max(maxLen, i - curPos + 1);
            } else {
                for (; s[curPos] != s[i]; curPos++)
                    index[s[curPos] - 'A'] = false;
                curPos++;
            }
        }
        return maxLen;
    }
};