/**
*   Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*
*   Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*
*   Some examples:
*     ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*
**/

class Solution {
public:
    bool isOperator(const string& str) {
        if (str == "+" || str == "-" || str == "*" || str == "/")
            return true;
        return false;
    }
    
    int evaluate(int op1, int op2, const string& op) {
        if (op == "+")
            return op1 + op2;
        else if (op == "-")
            return op1 - op2;
        else if (op ==  "*")
            return op1 * op2;
        else if (op ==  "/")
            return op1 / op2;

        return 0;
    }
    
    int stringToInt(const string& str) {
        //atoi(str.c_str());
        istringstream buffer(str);
        int result;
        buffer >> result;
        return result;
    }

    string intToString(const int number) {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    
    
    int evalRPN(vector<string> &tokens) {
        stack<string> tokenStack;
        vector<string>::iterator it;

        for (it = tokens.begin(); it != tokens.end(); ++it) {
            if (isOperator(*it)) {
                int op2 = stringToInt(tokenStack.top()); tokenStack.pop();
                int op1 = stringToInt(tokenStack.top()); tokenStack.pop();
                int result = evaluate(op1, op2, *it);
                
                tokenStack.push(intToString(result));
            }
            else {
                tokenStack.push(*it);
            }
        }
        int result = stringToInt(tokenStack.top()); tokenStack.pop();
        return result;
    }
};