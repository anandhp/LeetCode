/**
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    
    For example, given n = 3, a solution set is:
    
    "((()))", "(()())", "(())()", "()(())", "()()()"
**/
class Solution {
public:
    void generateParenthesis(int open, int close, vector<string>& paraContainer, string s) {
        if (open == 0 && close == 0) {
            paraContainer.push_back(s);
            return;
        }
        if (open > 0)
            generateParenthesis(open - 1, close + 1, paraContainer, s + "(");
        if (close > 0)
            generateParenthesis(open, close - 1, paraContainer, s + ")");
        return;
    } 
    
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        if (n == 0)
            return parenthesis;
        
        generateParenthesis(n, 0, parenthesis, "");
    }
};