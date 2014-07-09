/**
    Follow up for "Remove Duplicates":
    What if duplicates are allowed at most twice?
    
    For example,
    Given sorted array A = [1,1,1,2,2,3],
    
    Your function should return length = 5, and A is now [1,1,2,2,3].

**/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!A || n == 0)
            return n;
            
        int length = 0;
        int previous = A[length];
        int found = 1;
        
        for (int i = length + 1; i < n; i++) {
            if (A[length] != A[i]) {
                previous = A[++length] = A[i];
                found = 1;
            }
            else if (A[i] == previous && found < 2) {
                A[++length] = A[i];
                found++;
            }
        }
        
        return length + 1;
    }
};