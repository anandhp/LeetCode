/**
*   Given an array of integers, every element appears three times 
*   except for one. Find that single one.
*
*   Note:
*   Your algorithm should have a linear runtime complexity. 
*   Could you implement it without using extra memory?
*
**/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, mask = 0;
        
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];
            ones ^= A[i];
            mask = ~(ones & twos);
            ones = ones & mask;
            twos = twos & mask;
        }
        
        return ones;
    }
};