/**
 * @file chocolate_distribution_problem.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0#
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int getMinDifference(int arr[], int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (n < m)
        return -1;

    sort(arr, arr + n);

    int minDifference = INT_MAX;
    for (int i = 0, j = m - 1; j < n; i++, j++)
    {
        minDifference = min(minDifference, arr[j] - arr[i]);
    }

    return minDifference;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> m;
        cout << getMinDifference(arr, n, m) << "\n";
    }

    return 0;
}