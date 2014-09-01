/**
*   Given a non-negative number represented as an array of digits, plus one to the number.
*
*   The digits are stored such that the most significant digit is at the head of the list.
*
**/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        vector<int> newDigits(size);
        int carry = 0;
        
        if (digits[size - 1] +  1 >= 10) {
            carry = (digits[size - 1] +  1) / 10;
            newDigits[size - 1] = (digits[size - 1] + 1) % 10;
        }
        else
            newDigits[size - 1] = digits[size - 1] + 1;
        
        for (int i = digits.size() - 2; i >= 0; i--) {
            newDigits[i] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        
        if (carry > 0)
            newDigits.insert(newDigits.begin(), carry);
            
        return newDigits;
    }
};