/**
    Given an array with n objects colored red, white or blue, sort them so that objects of the same color are 
    adjacent, with the colors in the order red, white and blue.
    
    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
    
    Note:
    You are not suppose to use the library's sort function for this problem.

**/

class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void sortColors(int A[], int n) {
        for (int c = 0, r = 0, b = n - 1; c <= b;) {
            if (A[c] == 2) {
                swap(A[b--], A[c]);
            }
            else if (A[c] == 0) {
                swap(A[r++], A[c++]);
            } else {
                c++;
            }
        }
    }
};