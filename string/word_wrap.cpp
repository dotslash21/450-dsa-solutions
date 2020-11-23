/**
 * @file word_wrap.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/word-wrap/0# (Badly worded problem don't follow GFG)
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printWordWrap(int lengths[], int n, int maxLineWidth)
{
    // Cost matrix for storing ith to jth words in a line.
    int cost[n][n];

    // Fill with the remaining space left for choosing ith to jth word.
    for (int i = 0; i < n; i++)
    {
        cost[i][i] = maxLineWidth - lengths[i];

        for (int j = i + 1; j < n; j++)
        {
            cost[i][j] = cost[i][j - 1] - lengths[j] - 1;
        }
    }

    // Find the actual square cost for choosing ith to jth word and store it.
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (cost[i][j] < 0)
            {
                cost[i][j] = INT_MAX;
            }
            else
            {
                cost[i][j] = cost[i][j] * cost[i][j];
            }
        }
    }

    // DP table to store the min cost of justifying
    // text from ith index onwards.
    int minCost[n];

    // Array to store the line breaks.
    int arrangement[n];

    // Populate minCost and arrangement
    for (int i = n - 1; i > -1; i--)
    {
        minCost[i] = cost[i][n - 1];
        arrangement[i] = n;

        for (int j = n - 1; j > i; j--)
        {
            if (cost[i][j - 1] == INT_MAX)
                continue;

            if (minCost[i] > cost[i][j - 1] + minCost[j])
            {
                minCost[i] = cost[i][j - 1] + minCost[j];
                arrangement[i] = j;
            }
        }
    }

    // Output
    int i = 0;
    while (i < n)
    {
        cout << i + 1 << " " << arrangement[i] << " ";
        i = arrangement[i];
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxLineWidth;
        cin >> n;
        int lengths[n];
        for (int i = 0; i < n; i++)
            cin >> lengths[i];
        cin >> maxLineWidth;

        printWordWrap(lengths, n, maxLineWidth);
    }

    return 0;
}