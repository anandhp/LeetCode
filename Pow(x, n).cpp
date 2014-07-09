/**
    Implement pow(x, n).
**/

class Solution {
public:
    double powEx(double x, int n) {
        if (n == 0)
            return 1.0;
        double r = powEx(x, n / 2);
        if (n % 2)
            return r * r * x;
        return r * r;
    }    
    double pow(double x, int n) {
        if (n < 0)
            return 1 / powEx(x, n * -1);
        return powEx(x, n);
    }
    
};