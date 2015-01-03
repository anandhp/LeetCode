/**
*   Given a column title as appear in an Excel sheet, return its corresponding column number.
*
*   For example:
*
*   A -> 1
*   B -> 2
*   C -> 3
*   ...
*   Z -> 26
*   AA -> 27
*   AB -> 28 
*
**/


class Solution {
public:
    int titleToNumber(string s) {
        int colNumber = 0;
        for (int i = 0; i < s.length(); i++) {
            colNumber = colNumber * 26 + (s[i] - 'A' + 1);
        }
        return colNumber;
    }
};