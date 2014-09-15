/**
*   Given two binary strings, return their sum (also a binary string).
*
*   For example,
*   a = "11"
*   b = "1"
*   Return "100".
*
**/

class Solution {
public:
    int INT(char c) { return (c - '0'); }
    char CHAR(int n) { return (n + '0'); }
    
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
  
        if (la == 0)
            return b;
        if (lb == 0)
            return a;
            
        string r = "";
        int sum = 0, carry = 0;
        int i, j;
  
        for (i = la - 1, j = lb - 1; i >=0 || j >=0;) {
            sum = 0;
            
            sum += i >= 0 ? INT(a[i--]) : 0;  
            sum += j >= 0 ? INT(b[j--]) : 0;  
            sum += carry;
            
            carry = sum / 2;
            sum = sum % 2;
            r = CHAR(sum) + r;
        }
        if (carry)
             r = CHAR(carry) + r;
        return r;
    }
};