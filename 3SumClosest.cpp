/**
*   Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
*   target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
*
*   For example, given array S = {-1 2 1 -4}, and target = 1.
*
*   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
**/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        int result = 0;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1, k = size - 1; j < k;) {
                int sum = num[i] + num[j] + num [k];

                if (i == 0)
                    result = sum;
                
                if (sum == target)
                    return sum;
                else if (sum > target)
                    k--;
                else
                    j++;

                if (abs(target - sum) < abs(target - result))
                    result = sum;
            }
        }
        
        return result;
    }
};