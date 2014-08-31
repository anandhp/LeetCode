/**
*   Implement strStr().
*
*    Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*
**/

class Solution {
public:
    int strLen(char *s) {
        int length = 0;
        while(s[length++] != '\0');
        return length;
    }
    vector<int> prefixTable(char *s) {
        int length = strLen(s);
        vector<int> table(length, 0);
        
        for (int i = 1, j = 0; s[i] != '\0';) {
            if (s[i] == s[j]) {
                table[i] = j + 1;
                i++, j++;
            }
            else if (j > 0)
                j = table[j - 1];
            else
                i++;
        }
        
        return table;
    }
    
    char *strStr(char *haystack, char *needle) {
        if (needle && needle[0] == '\0')
            return haystack;
            
        vector<int> T = prefixTable(needle);
        for (int i = 0, j = 0; haystack[i] != '\0';) {
            if (haystack[i] == needle[j]) {
                if (needle[j + 1] == '\0') {
                    return haystack + (i - j);
                }
                i++; j++;
            }
            else if (j > 0)
                j = T[j - 1];
            else 
                i++;
        }
        return NULL;
    }
};