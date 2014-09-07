/**
*   Given a 2D board and a word, find if the word exists in the grid.
*
*   The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
*   
*   For example,
*   Given board =
*   
*   [
*     ["ABCE"],
*     ["SFCS"],
*     ["ADEE"]
*   ]
*   word = "ABCCED", -> returns true,
*   word = "SEE", -> returns true,
*   word = "ABCB", -> returns false.
*
**/

class Solution {
public:
    bool formWord(vector<vector<char> > &board, string word, int x, int y, vector<vector<bool> >& visited, int index) {
        if (word.length() == index)
            return true;
            
        if (x > 0 && board[x-1][y] == word[index] && !visited[x - 1][y]) {
            visited[x - 1][y] = true;
            if(formWord(board, word, x - 1, y, visited, index + 1))
                return true;
            visited[x - 1][y] = false;        
        }
        if (x < board.size() - 1 && board[x+1][y] == word[index] && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            if(formWord(board, word, x + 1, y, visited, index + 1))
                return true;
            visited[x + 1][y] = false;
        }
        if (y > 0 && board[x][y - 1] == word[index] && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            if(formWord(board, word, x, y - 1, visited, index + 1))
                return true;
            visited[x][y - 1] = false;    
        }
        if (y < board[x].size() - 1 && board[x][y + 1] == word[index] && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            if(formWord(board, word, x, y + 1, visited, index + 1))
                return true;
            visited[x][y + 1] = false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty())
            return false;
            
        vector<vector<bool> > visited(board.size(), vector<bool>(board.begin()->size(), false));
        int index = 0;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[index]) {
                    visited[i][j] = true;

                    if (formWord(board, word, i, j, visited, index + 1))
                        return true;

                    visited[i][j] = false;
                }
        }
            
        
        return false;
    }
};