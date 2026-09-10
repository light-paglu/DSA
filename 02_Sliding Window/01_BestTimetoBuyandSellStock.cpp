#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), 
// profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed 
// because you must buy before you sell.

// Sell: ith day
// Buy: min value from start to i-1 day
// TC - O(N)
// SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuy = prices[0];

        for (auto curr : prices) {
            profit = max(profit, curr - minBuy);
            minBuy = min(minBuy, curr);
        }
        
        return profit;
    }
};