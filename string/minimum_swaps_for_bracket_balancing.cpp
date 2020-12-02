/**
 * @file minimum_swaps_for_bracket_balancing.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0#
 * @version 0.1
 * @date 2020-12-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

long swapCount(string s)
{
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            pos.push_back(i);
    }

    int count = 0; // To count the number of '[' encountered
    int p = 0;     // To track the position of next '['
    long sum = 0;  // To sore the result
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            count++;
            p++;
        }
        else
        {
            count--;
        }

        // Check if we encountered unbalanced part of string
        if (count < 0)
        {
            // Increase the sum by number of swaps required
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            p++;

            // Reset the count
            count = 1;
        }
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << swapCount(s) << "\n";
    }
}