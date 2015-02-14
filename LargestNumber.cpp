/**
*   Given a list of non negative integers, arrange them such 
*   hat they form the largest number.
*   
*   For example, given [3, 30, 34, 5, 9], the largest formed 
*   number is 9534330.
*   
*   Note: The result may be very large, so you need to return a 
*   string instead of an integer.
*
**/

class Solution {
public:
    class Compare {
    public:
        string numToStr(int number) {
            ostringstream os;
            os<<number;
            return os.str();
        }
        
        bool operator()(int x, int y) {
           string strX = numToStr(x);
           string strY = numToStr(y);
           
           return strX + strY  > strY + strX;
        }    
    };
    
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), Compare());
        string result = "";
        for (int i = 0; i < num.size(); i++) {
            ostringstream os;
            os<<num[i];
            result += os.str();
        }
        
        while(result[0]=='0' && result.length()>1)
            result.erase(0,1);
            
        return result;    
    }
};