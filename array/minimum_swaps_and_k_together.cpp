/**
 * @file minimum_swaps_and_k_together.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0#
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            count++;
    }

    int i = 0;
    int j = count;
    int swaps = 0;
    int minSwaps = 0;

    for (int idx = i; idx < j; idx++)
    {
        if (arr[idx] > k)
            swaps++;
    }

    minSwaps = swaps;

    while (j < n)
    {
        if (arr[j] > k && arr[i] <= k)
            swaps++;
        else if (arr[j] <= k && arr[i] > k)
            swaps--;

        i++;
        j++;

        minSwaps = min(minSwaps, swaps);
    }

    return minSwaps;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwaps(arr, n, k) << "\n";
    }

    return 0;
}