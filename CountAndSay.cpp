/**
*   The count-and-say sequence is the sequence of 
*   integers beginning as follows:
*   1, 11, 21, 1211, 111221, ...
*   
*   1 is read off as "one 1" or 11.
*   11 is read off as "two 1s" or 21.
*   21 is read off as "one 2, then one 1" or 1211.
*   Given an integer n, generate the nth sequence.
*   
*   Note: The sequence of integers will be represented as a string.
*
*/

class Solution {
public:
    string countAndSay(int n, string str) {
        if (n == 0)
            return str;
        
        string nstr = "";
        char c = str[0];
        int count = 1;
        for (int i = 1; i <= str.length(); i++) {
            if (c == str[i])
                count++;
            else {
                nstr += (count + '0');
                nstr += c;
                c = str[i];
                count = 1;
            }
        }
        
        return countAndSay(n - 1, nstr);
    }
    
    string countAndSay(int n) {
        return countAndSay(n - 1, "1");
    }
};