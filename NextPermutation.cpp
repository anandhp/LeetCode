/**
*   Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
*
*   If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
*   
*   The replacement must be in-place, do not allocate extra memory.
*   
*   Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
*   1,2,3 ==> 1,3,2
*   3,2,1 ==> 1,2,3
*   1,1,5 ==> 1,5,1
*
**/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int small = -1;
        int big = -1;
        
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] < num[i + 1])
                small = i;
        }
    
        if (small == -1) {
            sort(num.begin(), num.end());
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > num[small])
                big = i;
        }
    
        swap(num[small], num[big]);
        reverse(num.begin() + small + 1, num.end());
    }
};