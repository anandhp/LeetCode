/**
*   Given a string s, partition s such that every substring of the partition is a palindrome.
*
*   Return the minimum cuts needed for a palindrome partitioning of s.
*
*   For example, given s = "aab",
*   Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*
**/

class Solution {
public:
    
    int minCut(string s) {
        int L = s.length();
        if (L == 0)
            return 0;

        //Prepare palindrome matrix showin all possible palindromes
        //between 0, i            
        vector<vector<bool> > P(L, vector<bool>(L, false));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j <=i; j++) {
                if (s[j] == s[i] && (i - j < 2 || P[j + 1][i - 1])) {
                    P[j][i] = true;
                }
                else
                    P[j][i] = false;
            }
        }
        
        //Now find cost of each palidrome cuts
        vector<int> C(L, 0);
        for (int i = 0; i < L; i++) {
            int k = L;
            if (P[0][i])
                C[i] = 0;
            else {
                for (int j = 0;  j < i; j++) {
                    if (P[j + 1][i] && k > C[j] + 1)
                        k = C[j] + 1;
                }
                C[i] = k;
            }
        }
        
        return C[L - 1];
    }

};