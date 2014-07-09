/**
    Implement int sqrt(int x).
    
    Compute and return the square root of x.

**/

class Solution {
public:
    int sqrt(int x) {
        if (x == 1)
            return 1;
            
        long long low = 0;
        long long high = 1 + x / 2;
        
        while (low + 1  < high) {
            long long mid = (high + low) / 2;
            long long sqr = mid * mid;
            
            if (sqr == x)
                return mid;
            else if (sqr > x)
                high = mid;
            else 
                low = mid;
        }
        
        return low;
    }
};