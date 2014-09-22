/**
*   Say you have an array for which the ith element is the price of a given stock on day i.
*
*   Design an algorithm to find the maximum profit. You may complete at most two transactions.
*   
*   Note:
*   You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*
**/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int size = prices.size();
        
        if (size <= 1)
            return profit;
            
        vector<int> left(size);
        int index = prices[0];
        left[0] = 0;
        
        for (int i = 1; i < size; i++) {
            left[i] = max(left[i - 1], prices[i] - index);
            index = min (index, prices[i]);
        } 
        
        vector<int> right(size);
        index = prices[size - 1];
        right[size - 1] = 0;
        
        for (int i = size - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], index - prices[i]);
            index = max(index, prices[i]);
        }
        
        for (int i = 0; i < size; i++)
            profit = max(profit, left[i] + right[i]);
            
        return profit;   
        
    }
};