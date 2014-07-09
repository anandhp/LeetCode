/**
    Given an input string, reverse the string word by word.
    
    For example,
    Given s = "the sky is blue",
    return "blue is sky the".
    
    click to show clarification.
    
    Clarification:
    
    - What constitutes a word?
    - A sequence of non-space characters constitutes a word.
    - Could the input string contain leading or trailing spaces?
    - Yes. However, your reversed string should not contain leading or trailing spaces.
    - How about multiple spaces between two words?
    - Reduce them to a single space in the reversed string.
**/

class Solution {
public:
    void reverseWords(string &s) {
        string result = "", word ="";
        int i = 0, size = s.size();
        
        while (i < size) {
            if(s[i] == ' ' && word.empty()) { 
               //Nothing to be done here. Just skimm thru  
            } else if (s[i] == ' ' && !word.empty()) {
                //Build reverse string and reset the word
                result = word + " "+ result;
                word = "";
            }
            else {
                word += s[i];
            }
            i++;
        }
        
        if (!word.empty())
            s = word + " "+ result;
        else 
            s = result;
            
        s = s.substr(0, s.size() - 1);
     }
};