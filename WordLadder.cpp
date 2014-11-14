/**
*   Given two words (start and end), and a dictionary, find the 
*   length of shortest transformation sequence from start to end, 
*   such that:
*   
*   Only one letter can be changed at a time
*   Each intermediate word must exist in the dictionary
*   
*   For example, 
*   Given:
*       start = "hit"
*       end = "cog"
*       dict = ["hot","dot","dog","lot","log"]
*       return its length 5.
*       As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
*   
*   Note:
*   Return 0 if there is no such transformation sequence.
*   All words have the same length.
*   All words contain only lowercase alphabetic characters.
*   
**/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.size() == 0)
            return 0;
        
        queue<string> wordsQ;
        queue<int> distancesQ;
        
        dict.insert(end);
        wordsQ.push(start);
        distancesQ.push(1);
        
        while (!wordsQ.empty()) {
            string currentWord = wordsQ.front();
            int currentDist = distancesQ.front();
            
            if (currentWord == end)
                return currentDist;
            
            wordsQ.pop(), distancesQ.pop();
            
            for (char c = 'a'; c <= 'z'; c++) {
                for (int i = 0; i < currentWord.length(); i++) {
                    string tempo = currentWord;
                    tempo[i] = c;       
                    if(dict.find(tempo) != dict.end()) {
                        wordsQ.push(tempo);
                        distancesQ.push(currentDist + 1);
                        dict.erase(tempo);
                    }
                }        
            }
        }
        
        return 0;
    }
};
