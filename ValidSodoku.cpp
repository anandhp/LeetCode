/**
*   Determine if a Sudoku is valid, according to Sudoku Rules.
*   
*   The Sudoku board could be partially filled, where empty 
*   cells are filled with the character '.'.
*   
*   
*   A partially filled sudoku which is valid.
*   
*   Note:
*   A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
*   
**/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int m = board.size(), n = board[0].size();
        
        vector<bool> square(9, false);
        //Checking rows
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                int digit = board[i][j] - '0';
                if (square[digit - 1])
                    return false;
                square[digit - 1] = true;
            }
            fill(square.begin(), square.end(), false);
        }
        
        
        //Checkiing columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[j][i] == '.')
                    continue;
                int digit = board[j][i] - '0';
                if (square[digit - 1])
                    return false;
                square[digit - 1] = true;
            }
            fill(square.begin(), square.end(), false);
        }
       
        for (int i = 0; i < m; i += 3) {
            for (int j = 0; j < n; j += 3) {
                for (int k = i; k < i+3; k++) 
                    for (int l = j; l < j+3; l++) {
                        if (board[k][l] == '.')
                            continue;
                        int digit = board[k][l] - '0';
                        if (square[digit - 1])
                            return false;
                        square[digit - 1] = true;
                    }
                fill(square.begin(), square.end(), false);  
            }
        }
        
        return true;
    }
};