/**
*   Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*   
*   For example:
*
*       1 -> A
*       2 -> B
*       3 -> C
*       ...
*       26 -> Z
*       27 -> AA
*       28 -> AB 
*   
**/

class Solution {
public:
    string convertToTitle(int n) {
        string column = "";
        
        while (n > 0) {
            int rem = (n - 1) % 26;
            column = char (rem + 'A') + column;
            n = (n - rem) / 26;
        }
        
        return column;
    }
};