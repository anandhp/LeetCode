/**
*   Given an array of words and a length L, format the text such that each line has exactly 
*   L characters and is fully (left and right) justified.
*
*   You should pack your words in a greedy approach; that is, pack as many words as you can 
*   in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
*   
*   Extra spaces between words should be distributed as evenly as possible. If the number of 
*   spaces on a line do not divide evenly between words, the empty slots on the left will 
*   be assigned more spaces than the slots on the right.
*   
*   For the last line of text, it should be left justified and no extra space is inserted between words.
*   
*   For example,
*   words: ["This", "is", "an", "example", "of", "text", "justification."]
*   L: 16.
*   
*   Return the formatted lines as:
*   [
*      "This    is    an",
*      "example  of text",
*      "justification.  "
*   ]
*   Note: Each word is guaranteed not to exceed L in length.
*   
*   click to show corner cases.
*   
*   Corner Cases:
*    A line other than the last line might contain only one word. What should you do in this case?
*    In this case, that line should be left-justified.
*
**/


class Solution {
public:
    void addLine(vector<string> &lines, vector<string> &words, int prev, int curr, int L, int curLen) {
        int i, spaces = curr - prev;
        int extra = L - curLen - spaces;
        string line = "";
        
        //when single word line
        if(spaces == 0) {
            line += words[prev] + string(L - words[prev].length(), ' ');
            lines.push_back(line);    
            return;
        }
        //add spaces based on remaining extra spaces
        for (i = prev; i < curr; i++) {
            //when less extra spaces, add them evenly across all words
            if (extra && extra < spaces) {
                line += words[i] + string(2, ' ');
                extra--;
            }
            else {  //add surplus spaces between words
                line += words[i] + string(extra / spaces + extra % spaces + 1, ' ');
                extra -= extra % spaces;
            }        
        }
        
        line += words[i];
        lines.push_back(line);    
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> lines;
        
        if (words.size()  == 0)
            return lines;

        int curLen = 0;    
        for (int i = 0, prev = 0; i < words.size(); i++) {
            //check we can add more words to the line
            if(curLen + (i - prev) + words[i].length() > L) {
                addLine(lines, words, prev, i - 1, L, curLen);
                prev = i, curLen = 0;
            }
            //when single word fills this line, just add that word
            if (words[i].length() == L) {
                lines.push_back(words[i]);
                prev = i + 1, curLen = 0;
                continue;
            }
            //when last line, justify that word
            if(i == words.size() - 1) {
                string line = "";
                for (int j = prev; j <= i; j++)
                    line += words[j] + ' ';
                line += string(L - line.length(), ' ');
                lines.push_back(line);    
            }
            
            curLen += words[i].length();
        }
        
        return lines;
    }
};