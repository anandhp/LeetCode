/**
*   Given an absolute path for a file (Unix-style), simplify it.
*   
*   For example,
*   path = "/home/", => "/home"
*   path = "/a/./b/../../c/", => "/c"
*   click to show corner cases.
*   
*   Corner Cases:
*   Did you consider the case where path = "/../"?
*   In this case, you should return "/".
*   Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
*   In this case, you should ignore redundant slashes and return "/home/foo".
*
**/

class Solution {
public:
    //my utility split function
    void split(string s, char delim, vector<string> &tokens) {
        stringstream ss(s);
        string token;
        while(getline(ss, token, delim))
            tokens.push_back(token);
    }
    
    string simplifyPath(string path) {
        vector<string> tokens;
        split(path, '/', tokens);
        stack<string> S;
        //for each token do following
        // if . ignore it
        // if .. pop the current top from stack if exits
        // push the token to top of stack
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if(token == ".")
                continue;
            else if (token == "..") {
                if (!S.empty())
                    S.pop();                
            }
            else if (!token.empty())
                S.push(tokens[i]);
        }

        // in end take all items from stack and build the final path
        string finalPath = "";
        while (!S.empty()) {
            finalPath = "/" + S.top() + finalPath;
            S.pop();
        }
        if (finalPath.empty())
            return "/";
        return finalPath;
    }
};