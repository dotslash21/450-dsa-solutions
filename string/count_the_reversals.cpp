/**
 * @file count_the_reversals.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/count-the-reversals/0
 * @version 0.1
 * @date 2020-11-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int minReversals(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    if (n % 2 != 0)
        return -1;

    int open = 0, close = 0, reversals = 0;
    for (char c : s)
    {
        if (c == '{')
            open++;
        else
            close++;

        if (close > open)
        {
            reversals++;
            close--;
            open++;
        }
        else if (open > (n / 2))
        {
            reversals++;
            open--;
            close++;
        }
    }

    if (open != close)
        return -1;

    return reversals;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << minReversals(s) << "\n";
    }

    return 0;
}