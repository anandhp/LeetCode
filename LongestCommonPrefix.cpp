/**

    Write a function to find the longest common prefix string amongst an array of strings.

**/

class Solution {
public:
    
    string longestCommonPrefix(vector<string> &strs) {
        int length = strs.size();
        if (length <= 0)
            return "";
        int i, j;
        string prefix = strs[0];
        for (i = 1; i < length; i++) {
            string str = strs[i];
            for (j = 0; j < str.length() && j < prefix.length(); j++) {
                if (prefix[j] != str[j])
                    break;
            }
            prefix = prefix.substr(0, j);
            if (prefix == "")
                break;
        }
        
        return prefix;
    }
};