/**
*   Given n non-negative integers representing an elevation map where the 
*   width of each bar is 1, compute how much water it is able to trap after raining.
*
*   For example, 
*   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*
**/

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
            return 0;
            
        int maxPiller = 0, left[n];
        
        left[0] = A[0];
        maxPiller = A[0];
        
        for (int i = 1; i < n; i++) {
            maxPiller = max(maxPiller, A[i]);
            left[i] = maxPiller;
        }
        
        maxPiller = A[n - 1];
        int total = 0;
        
        for (int i = n - 1; i >=0; i--) {
            maxPiller = max(maxPiller, A[i]);
            total += min(left[i], maxPiller) - A[i];
        }
        
        return total;
    }
};