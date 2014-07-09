/**
    Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
    
    For "(()", the longest valid parentheses substring is "()", which has length = 2.
    
    Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

**/

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int longestValidParentheses(string s) {
        stack<int> brackets;
        int maxLen = 0, curPos = 0;
        for(int i = 0, length = s.length(); i < length; i++) {
            if (s[i] == '(') {
                brackets.push(i);
            }
            else {
                if (brackets.empty()) {
                    curPos = i + 1;
                }
                else {
                    brackets.pop();
                    if (brackets.empty())
                        maxLen = max(maxLen, i - curPos + 1);
                    else
                        maxLen = max(maxLen, i - brackets.top());
                }
            }
        }
        return maxLen;
    }
};