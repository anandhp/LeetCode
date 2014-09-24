/**
*   Find the contiguous subarray within an array (containing at least one number) 
*   which has the largest product.
*
*   For example, given the array [2,3,-2,4],
*   the contiguous subarray [2,3] has the largest product = 6.
*
**/

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0)
            return 0;

        int maximum = A[0]; 
        int maxAt = A[0], minAt = A[0];

        for (int i = 1; i < n; i++) {
            int minProd = minAt * A[i];
            int maxProd = maxAt * A[i];
            minAt = min(A[i], min(maxProd, minProd));
            maxAt = max(A[i], max(maxProd, minProd));
            maximum = max(maxAt, maximum);
        }
        
        return maximum;
    }
};