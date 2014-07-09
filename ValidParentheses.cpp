/**
*   Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*
*   The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/

class Solution {
public:

    char findMatching(char rightParathesis) {
        switch(rightParathesis) {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';    
        }
        return 0;
    }
    
    bool isValid(string s) {
        stack<char> paranthesis;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                paranthesis.push(s[i]);
            } else {
                if (!paranthesis.empty() && paranthesis.top() == findMatching(s[i])) {
                    paranthesis.pop();
                }else {
                    return false;
                }
            }
        }
        if (!paranthesis.empty())
            return false;
        return true;
    }
};