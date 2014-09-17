/**
*   Given an array of non-negative integers, you are initially positioned 
*   at the first index of the array.  Each element in the array represents 
*   your maximum jump length at that position.
*   
*   Your goal is to reach the last index in the minimum number of jumps.
*   
*   For example:
*   Given array A = [2,3,1,1,4]
*   
*   The minimum number of jumps to reach the last index is 2. 
*   (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
**/

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0 || (n > 1 && A[0] == 0))
            return 0;
        
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
        
        return M[n-1];
    }
};