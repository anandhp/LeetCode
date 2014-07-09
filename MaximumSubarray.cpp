/**
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
    
    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
    
**/

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int maxSubArray(int A[], int n) {
        if( n <= 0)
            return 0;
            
        int maxSum = A[0], currentSum = A[0];
        
        for (int i = 1; i < n; i++) {
            currentSum = max(currentSum + A[i], A[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};