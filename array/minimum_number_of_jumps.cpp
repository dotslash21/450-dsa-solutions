/**
 * @file minimum_number_of_jumps.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    int dp[n];
    dp[n - 1] = 0;

    for (int i = n - 2; i > -1; i--)
    {
        if (arr[i] == 0)
        {
            dp[i] = -1;
            continue;
        }

        int start = i + 1;
        int end = min(n, start + arr[i]);
        int minJumps = INT_MAX;
        for (int j = start; j < end; j++)
        {
            if (dp[j] == -1)
                continue;
            minJumps = min(minJumps, 1 + dp[j]);
        }
        dp[i] = (minJumps == INT_MAX) ? -1 : minJumps;
    }

    return dp[0] > n ? -1 : dp[0];
}

int minJumpsOptimized(int arr[], int n)
{
    if (n <= 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    int maxReachable, stepsPossible, numJumps;

    maxReachable = arr[0];
    stepsPossible = arr[0];
    numJumps = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return numJumps;

        maxReachable = max(maxReachable, i + arr[i]);

        stepsPossible--;

        if (stepsPossible == 0)
        {
            numJumps++;

            if (i >= maxReachable)
                return -1;

            stepsPossible = maxReachable - i;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}