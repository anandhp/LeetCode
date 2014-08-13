/** 
*   Given a digit string, return all possible letter combinations that the number could represent.
*
*   A mapping of digit to letters (just like on the telephone buttons) is given below.
*
*       1       2[abc]  3[def]
*       4[ghi]  5[jkl]  6[mno]
*       7[pqrs] 8[tuv]  9[wxyz]
*       *       0[ ]    #
*
*   Input:Digit string "23"
*    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*    
*    
**/

class Solution {
public:
    void generate(const vector<string>& alNumMap, string digits, int index, vector<string>& result, string s) {
        if (index == digits.length()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        for (int i = 0; i < alNumMap[digit].length(); i++) {
            generate(alNumMap, digits, index + 1, result, s + alNumMap[digit][i]); 
        }        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> alphaNumMap {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        generate(alphaNumMap, digits, 0, result, "");
        return result;
    }
    
};