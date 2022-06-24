/*
Problem: You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <limits.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int max_profit = 0; //Init
        if (prices.size() < 2)
            return 0;
        for (auto itr = prices.begin(); itr < prices.end(); itr++) { //O(N)
            if (*itr < buy ) {
                buy = *itr;
            } else if (*itr-buy > max_profit) 
                max_profit = *itr-buy;
            
        }
        
        return(max_profit);
    }
};
