/**
 * @file trapping_rain_water.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

long long trappedWater(int arr[], int n)
{
    if (n <= 2)
        return 0;

    long long trapped = 0;
    int i = 0, j = n - 1, level = 0;
    while (i < j)
    {
        level = max(level, min(arr[i], arr[j]));

        if (arr[i] <= arr[j])
        {
            trapped += (level <= arr[i]) ? 0 : level - arr[i];
            i++;
        }
        else
        {
            trapped += (level <= arr[j]) ? 0 : level - arr[j];
            j--;
        }
    }

    return trapped;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << trappedWater(arr, n) << "\n";
    }

    return 0;
}