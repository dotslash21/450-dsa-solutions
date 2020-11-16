/**
 * @file smallest_subarray_with_sum_greater_than_x.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int x)
{
    if (n == 0)
        return -1;

    int size = INT_MAX;

    int i = 0, j = 0;
    int currSum = 0;
    while (j < n)
    {
        while (currSum <= x && j < n)
            currSum += arr[j++];

        while (currSum > x && i < n)
        {
            size = min(size, j - i);
            currSum -= arr[i++];
        }
    }

    return size > n ? -1 : size;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, n, x) << "\n";
    }

    return 0;
}