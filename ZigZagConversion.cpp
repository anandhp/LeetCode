/**
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:
    
    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

**/

class Solution {
public:
     string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
        int length  = s.length();
        vector< vector<char> > matrix(nRows);
        bool nextRow = true;
        
        for(int i = 0, row = 0; i < length; i++) {
            if (nextRow) {
                matrix[row++].push_back(s[i]);
            }
            if (!nextRow) {
                matrix[row--].push_back(s[i]);
            }
            if (row >= nRows || row < 0) {
                row += nextRow ? -2 : 2;
                nextRow = !nextRow;
            }
        }
        string rs = "";
        for (int i = 0 ; i < nRows; i++) {
            for(int j = 0; j < matrix[i].size(); j++)
                rs += matrix[i][j];       
        }
        return rs;
    }
};