/**
*   Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
*
*   You have the following 3 operations permitted on a word:
*   
*   a) Insert a character
*   b) Delete a character
*   c) Replace a character
*
**/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int fromLen = word1.length();
        int toLen = word2.length();
        
        int distance[fromLen + 1][toLen + 1];

        //to convert from emtpy string to empty string
        distance[0][0] = 0;

        //to convert from word1 to empty string
        for (int i = 1; i <= fromLen; i++)
            distance[i][0] = i;
        
        //to convert from empty string to word2     
        for (int i = 1; i <= toLen; i++)
            distance[0][i] = i;

        //otherwise calculate the operations
        for (int i = 1; i <= fromLen; i++) {
            for (int j = 1; j <= toLen; j++) {
                if (word1[i - 1] == word2[j - 1])
                    distance[i][j] = distance[i - 1][j - 1];
                else {
                    //get te minimum of 3 co-ord
                    int d = min(distance[i - 1][j - 1], distance[i - 1][j]);
                    distance[i][j] = min(d, distance[i][j - 1]) + 1;
                }
            }
        }
        return distance[fromLen][toLen];
    }

};