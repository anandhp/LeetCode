/**
*   Given an array and a value, remove all instances of that value in place and return the new length.
*
*   The order of elements can be changed. It doesn't matter what you leave beyond the new length.
**/
class Solution {
public:
    void swap(int A[], int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    int removeElement(int A[], int n, int elem) {
        int length = n;
        for (int i = 0; i < length; i++) {
            if (A[i] == elem) {
                for (int j = length - 1; j >= i && A[j] == elem; j--) {
                    length--;
                }
                if (length < 0)
                    break;
                if (length > i) {
                    swap(A, i, length - 1);
                    length--;
                }
            }
        }
        return length;
    }
};