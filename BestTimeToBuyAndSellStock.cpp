/**
*   Say you have an array for which the ith element is the price of a given stock on day i.
*
*   If you were only permitted to complete at most one transaction (ie, buy one and sell one 
*   share of the stock), design an algorithm to find the maximum profit in a day.
*
**/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int size = prices.size();

        if (size == 0)
            return profit;

        vector<int> minPrices;
        int minPrice = prices[0];        

        for (int i = 1; i < size; i++) {
            minPrice = min(minPrice, prices[i]);
            minPrices.push_back(minPrice);
        }
        
        for (int i = 1; i < size; i++) {
            if (prices[i] - minPrices[i - 1] > profit)
                profit = prices[i] - minPrices[i - 1];
        }
        
        return profit;
    }
    
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int size = prices.size();

        if (size == 0)
            return profit;
            
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(prices[i] - minPrice, profit);
        }
        
        return profit;
    }
};