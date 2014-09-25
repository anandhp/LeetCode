/**
*   Given a string S and a string T, find the minimum window in S which will 
*   contain all the characters in T in complexity O(n).
*
*   For example,
*   S = "ADOBECODEBANC"
*   T = "ABC"
*   Minimum window is "BANC".
*   
*   Note:
*   If there is no such window in S that covers all characters in T, return the emtpy string "".
*   
*   If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*
**/

class Solution {
public:
    string minWindow(string S, string T) {
        int sLen = S.length();
        int tLen = T.length();
        string result = "";
        
        if (sLen == 0 || tLen == 0)
            return result;
        
        int hasFound[256] = {0}; //holds characters found so far
        int needToFind[256] = {0}; // characters to be found 
        
        for (int i = 0; i < tLen; i++)
            needToFind[T[i]]++;
        
        int count = 0;
        int windowLen = INT_MAX;
        
        for(int begin = 0, end = 0; end < sLen; end++) {
            int endChar = S[end];
            //Skip characters which are not needed
            //ie. which are not present in T
            if (needToFind[endChar] == 0)
                continue;

            hasFound[endChar]++;
            
            //keep track of characters found from T
            if (hasFound[endChar] <= needToFind[endChar])
                count++;
            
            //when all characters from T are found    
            if (count == tLen) {
                int beginChar = S[begin];
                //adjust the window such that 
                while(needToFind[beginChar] == 0 
                    || hasFound[beginChar] > needToFind[beginChar]) {
                    if (hasFound[beginChar] > needToFind[beginChar])
                        hasFound[beginChar]--;
                    beginChar = S[++begin];   
                }
                //adjust new window if its optimal
                int newWinLen = end - begin + 1;
                if (newWinLen < windowLen) {
                    windowLen = newWinLen;
                    result = S.substr(begin, windowLen);
                }
            }

        }//end of for
        
        return result;
    }
};