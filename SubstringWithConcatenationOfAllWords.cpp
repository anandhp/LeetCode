/**
*   You are given a string, S, and a list of words, L, that are all of the same length. 
*   Find all starting indices of substring(s) in S that is a concatenation of each word in L 
*   exactly once and without any intervening characters.
*   
*   For example, given:
*   S: "barfoothefoobarman"
*   L: ["foo", "bar"]
*   
*   You should return the indices: [0,9].
*   (order does not matter).
*
**/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> indices;
        int numWords  = L.size();
        
        if (numWords == 0)
            return indices;
        
        int wordLen = L[0].length();
        map<string, int> words;
  
        for (int i = 0; i < numWords; i++) {
            words[L[i]]++;
        }
  
        for (int i = 0; (i + numWords * wordLen) <= S.length(); i++) {
            map<string, int> matchWords(words);
            for (int j = 0; j < numWords; j++) {
                string curStr = S.substr(i + j * wordLen, wordLen);
                
                if (matchWords.find(curStr) == matchWords.end())
                    break;
                    
                matchWords[curStr]--;
                
                if (matchWords[curStr] == 0)    
                    matchWords.erase(curStr);
            }
            if (matchWords.empty())
                indices.push_back(i);
        }
        return indices;
    }
};