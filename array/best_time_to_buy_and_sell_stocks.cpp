/**
 * @file best_time_to_buy_and_sell_stocks.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n <= 1) {
            return 0;
        }

        int maxRight = prices[n - 1];
        int maxProfit = 0;
        for (int i = n - 2; i > -1; i--) {
            maxProfit = max(maxProfit, maxRight - prices[i]);
            maxRight = max(maxRight, prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices{7,1,5,3,6,4};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
}