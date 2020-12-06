/**
 * @file smallest_distinct_window.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/smallest-distant-window/0#
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int smallestDistinctWindow(string s)
{
    int n = s.size();

    set<char> unique;
    for (char c : s)
        unique.insert(c);

    vector<int> count(128, 0);

    int i = 0, j = 0;
    int distinctCount = 0;
    int minWindowSize = n;
    while (j < n)
    {
        while (j < n && distinctCount < unique.size())
        {
            if (count[s[j]] == 0)
            {
                distinctCount++;
            }

            count[s[j++]]++;
        }

        while (distinctCount == unique.size())
        {
            minWindowSize = min(minWindowSize, j - i);

            if (count[s[i]] == 1)
            {
                distinctCount--;
            }

            count[s[i++]]--;
        }
    }

    return minWindowSize;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << smallestDistinctWindow(s) << "\n";
    }

    return 0;
}