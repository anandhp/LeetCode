/**
    Given an unsorted integer array, find the first missing positive integer.
    
    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.
    
    Your algorithm should run in O(n) time and uses constant space.

**/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        set<int> keySet;
        int i = 0;
        
        for (i = 0; i < n; i++) {
            if (A[i] > 0)
                keySet.insert(A[i]);
        }
        
        for (i = 0; i < keySet.size(); i++) {
            if (keySet.find(i+1) == keySet.end())
                break;
        }
        
        return i + 1;
        
    }
};