/**

    Given a sorted array of integers, find the starting and ending position of a given target value.
    
    Your algorithm's runtime complexity must be in the order of O(log n).
    
    If the target is not found in the array, return [-1, -1].
    
    For example,
        Given [5, 7, 7, 8, 8, 10] and target value 8,
        return [3, 4].

**/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, h = n - 1;
        vector<int> indices(2, -1);
        while (l <= h) {
            int mid = (l + h) / 2;
            if (A[mid] < target) {
                l = mid + 1;
            } else if (A[mid] > target) {
                h = mid - 1;
            } else {
                int k = mid;
                while(k >= l) {
                    if (A[k] != target)
                        break;
                    indices[0] = k--;
                }
                k = mid;
                while(k <= h) {
                    if (A[k] != target)
                        break;
                    indices[1] = k++;
                }
                break;
            }
        }
        return indices;
    }
};