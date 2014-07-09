/**
*   Given a string S, find the longest palindromic substring in S. 
*   You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
**/
class Solution {
public:
    string longestPalindrome(string s, int index1, int index2) {
        int i = index1;
        int j = index2;
        while (i >= 0 && j < s.length()) {
            if (s[i] != s[j])
                break;
            i--;
            j++;
        }
        string palindrome = "";
        if (i + 1 >= 0 && j - 1 < s.length()) {
            palindrome = s.substr(i + 1, j - i - 1);
        }
        return palindrome;
    }
    
    string longestPalindrome(string s) {
        string lpalindrome = "";
        for (int i = 0 ; i < s.length(); i++) {
            string palindrome1 = longestPalindrome(s, i, i);
            string palindrome2 = longestPalindrome(s, i, i + 1);
           
            if (palindrome1.length() > palindrome2.length()) {
                if (palindrome1.length() > lpalindrome.length()) {
                    lpalindrome = palindrome1;
                }
            }
            else {
                if (palindrome2.length() > lpalindrome.length()) {
                    lpalindrome = palindrome2;
                }
            }
           
        }
        return lpalindrome;
    }
};
