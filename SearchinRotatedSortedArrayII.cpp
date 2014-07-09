/**
    
    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?
    
    Would this affect the run-time complexity? How and why?
    
    Write a function to determine if a given target is in the array.
    
**/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = (high + low) / 2;
            
            if (A[mid] == target)
                return true;
                
            if (A[low] < A[mid]) {
                if (A[low] <= target && A[mid] > target)
                    high = mid -1;
                else 
                    low = mid + 1;
            }else if (A[low] > A[mid]){
                if (A[mid] < target && A[high] >= target)
                    low = mid + 1;
                else 
                    high = mid - 1;
            } else {
                low++;
            }
        }
        
        return false;
    }
};