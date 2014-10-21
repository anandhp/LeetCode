/**
*   Follow up for "Find Minimum in Rotated Sorted Array":
*   What if duplicates are allowed?
*    
*   Would this affect the run-time complexity? How and why?
*   Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*   
*   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*   
*   Find the minimum element.
*   
*   The array may contain duplicates.
*
**/

class Solution {
public:
    int findMin(vector<int> &num, int low, int high) {
        // This condition is needed to handle the case when array is not
        // rotated at all
        if (high < low || num[low] < num[high])  
            return num[0];
        
        //Single element array
        if (low == high)
            return num[low];
            
        while (low <= high) {
            //find mid of the array
            int mid = (low + high) / 2;

            //check if left of mid is bigger than mid
            //if so mid is pivot
            if (mid > low && num[mid - 1] > num[mid])
                return num[mid];
                
            //check if mid is bigger than the right of mid
            //if so right is pivot
            if (mid < high && num[mid + 1] < num[mid])
                return num[mid + 1];
           
            //adjust the bounds
            //check if left half is sorted. then check the 
            //right half. else check left half
            if (num[low] < num[mid])
                low = mid + 1;
            else if (num[high] > num[mid])
                high = mid - 1;
            else
                return min(findMin(num, low, mid-1), findMin(num, mid+1, high));
        }
        
        //default case
        return num[0];
    }
    
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size() - 1;
        return findMin(num, low, high);
    }    
};