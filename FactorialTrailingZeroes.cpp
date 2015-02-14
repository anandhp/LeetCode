/**
*   Given an integer n, return the number of trailing zeroes in n!.
*   
*   Note: Your solution should be in logarithmic time complexity.
**/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            n = n / 5 ;   
            count += n;
        }
        return count;    
    }
};