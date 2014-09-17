/**
*   Given an array of non-negative integers, you are initially positioned at the 
*   first index of the array. Each element in the array represents your maximum 
*   jump length at that position.
*   
*   Determine if you are able to reach the last index.
*       
*   For example:
*
*   A = [2,3,1,1,4], return true.
*   
*   A = [3,2,1,0,4], return false.
*   
**/

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0 || (n > 1 && A[0] == 0))
            return false;

        vector<int> M(n, INT_MAX);
        M[0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + A[j] >= i && M[j] != INT_MAX) {
                    M[i] = min(M[i], M[j] + 1);
                    break;
                }
            }
        }
        
        return M[n - 1] != INT_MAX;
    }
};