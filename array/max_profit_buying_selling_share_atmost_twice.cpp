/**
 * @file max_profit_buying_selling_share_atmost_twice.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int prices[], int n)
{
    if (n <= 1)
        return 0;

    int profit[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i > -1; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        profit[i] = max(profit[i + 1], maxPrice - prices[i]);
    }

    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        profit[i] = max(profit[i - 1], profit[i] + (prices[i] - minPrice));
    }

    return profit[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int prices[n];
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        cout << getMaxProfit(prices, n) << "\n";
    }

    return 0;
}