/**
*   Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
*   Find the minimum element.
*   
*   You may assume no duplicate exists in the array.
*
**/

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size() - 1;
        
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
            else 
                high = mid - 1;
        }
        
        //default case
        return num[0];
    }
};